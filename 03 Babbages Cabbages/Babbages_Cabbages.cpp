// Name of the Program: Babbage's Cabbages Version 4
// Author: Omair Qazi
// Date: 2020/10/21
// 
// Purpose: Calculates gross pay, net pay, and taxes for employees of Babbage's Cabbages.
// 
// Description: Uses tables and padding with modularized calculations to display the gross pay, net pay, and taxes for employees. 
//
//
// Date Modified:
// Mod Author: 
// Mod Reason: 

//Provides std:: cin, std::cout, std::left, std:: right, std::endl.
#include <iostream>

//Provides std::string.
#include <string>

//Provides std::setw.   
#include <iomanip>

//Provides input/output capabilities.
#include <cstdlib> 
#include <fstream>

//Declare Pay Constants.
#define WITHHOLDING 0.30
#define MIN_HOURS_WORKED 0.00
#define MAX_HOURS_WORKED 54.0
#define MIN_HOURLY_RATE 0.00
#define MAX_HOURLY_RATE 49.99
#define OVERTIME_CUTOFF 40.00

//Declare Transit Deduction Constants.
#define PARKING_DEDUCTION 10.00
#define TRANSIT_DEDUCTION 5.00
#define BIKE_DEDUCTION 1.00
#define NO_DEDUCTION 0.00

//Declare file location constant.
#define FILE_LOCATION "/Users/Omair/Desktop/payroll.txt"

//Declare Array Size
#define SIZE 10

//Declaring namespaces.
using std::cin, 
      std::cout, 
      std::left, 
      std::right, 
      std::setw, 
      std::setfill, 
      std::string, 
      std::fixed,
      std::setprecision,
      std::endl,
      std::ostream,
      std::ofstream;


//Prototype Declarations:

//Input Modules
void inputData(string &firstName, string &lastName, double &hoursWorked, double &hourlyRate);

//Processing Modules
void computePay(double hoursWorked, double &regularHours, double &overtimeHours, double hourlyRate, double &grossPay, double &taxAmount, double &netPay, double &deduction);
void computeHours(double hoursWorked, double &regularHours, double &overtimeHours);
double computeGrossPay(double hourlyRate, double regularHours, double overtimeHours);
double computeTaxAmount(double grossPay);
double computeNetPay(double grossPay, double taxAmount, double deduction);
string joinNames(string firstName, string lastName);
double transitDeduction();
char repeatProgram(string question);
double grossPayAmountSum(double grossPayArray[], double count);
double grossPayAverage(double grossPayArray[], double count);
double maximumGrossPay(double grossPayArray[], double count);
double minimumGrossPay(double grossPayArray[], double count);
void sortNumbersv3(double inputArray[], double inputNumbers);
void sortNumbersv4(double inputArray[], double inputNumbers);

//Output Wage Modules
void showWageHeader(ostream &stream);
void outputWageData(ostream &stream, string fullName, double regularHours, double overtimeHours, double hourlyRate, double grossPay, double taxAmount, double netPay, double deduction);
void payrollHeader(ostream &stream);
void outputSummaryData(ostream &stream, string fullNameArray[], double grossPayArray[], int numEmployees);

//Declare Bubble Sort Module variables.
int num_passes;       // global counters for recording the number of
int num_comparisons;  //   passes, comparisons, and swaps performed
int num_swaps;        //   by a sort

//Main Module.
int main()
{
    //Declare variables.
    char answer;
    string firstName, lastName, fullName;
    double hoursWorked, 
           hourlyRate,
           regularHours,
           overtimeHours,
           grossPay,
           taxAmount,
           netPay,
           deduction,
           grossPayAmountTotal;
    
    //Declare Bubblesort arrays.
    int numbers[SIZE];
    double num_numbers;    

    //Declare Lab Requirement Arrays.
    string fullNameArray[SIZE];
    double grossPayArray[SIZE];
    int numEmployees;
    
    //Initialize number of employee inputs.
    numEmployees = 0;

    //Declare outfile variable.
    ofstream outfile;

    //Open file output stream.
    outfile.open(FILE_LOCATION);
    
    //Write header to outfile.
    showWageHeader(outfile);
    
    //Check to see if output file is opened safely.
    if (!outfile.is_open()) {
        cout << "Cannot open output file" << endl;
        exit(EXIT_FAILURE);
    }
    
    //Call modules/functions.
    do {
        
        //Input section.
        inputData(firstName, lastName, hoursWorked, hourlyRate);
        
        //Processing section.
        fullName = joinNames(firstName, lastName);
        computePay(hoursWorked, regularHours, overtimeHours, hourlyRate, grossPay, taxAmount, netPay, deduction);

        //Store data in arrays.
        fullNameArray[numEmployees] = fullName;
        grossPayArray[numEmployees] = grossPay;
        numEmployees +=1;

        //Output data to screen.
        showWageHeader(cout);
        outputWageData(cout, fullName, regularHours, overtimeHours, hourlyRate, grossPay, taxAmount, netPay, deduction);
        
        //Repeat program.
        answer = repeatProgram("Process another employee (Y/N)?: ");

    } while((answer == 'Y') || (answer == 'y'));

    //Output data to file.
    showWageHeader(outfile);
    outputWageData(outfile, fullName, regularHours, overtimeHours, hourlyRate, grossPay, taxAmount, netPay, deduction);
        
    //Output array data to file.
    outputSummaryData(cout, fullNameArray, grossPayArray, numEmployees);

    //Close file output stream.
    outfile.close();
   
}

//Input Module: Collect's worker data.
void inputData(string &firstName, string &lastName, double &hoursWorked, double &hourlyRate)
{
    cout << fixed << setprecision(2);

    cout << "Enter employee's first name: ";
    cin >> firstName;
    cout << "Enter employee's last name: ";
    cin >> lastName;

    //Hours worked must be between MIN_HOURS_WORKED and MAX_HOURS_WORKED   
    do {
        
        cout << "Enter number of hours worked: ";
        cin >> hoursWorked;

        if ((hoursWorked < MIN_HOURS_WORKED) || (hoursWorked > MAX_HOURS_WORKED)) {
            
            cout << "The number of hours worked must be between " << MIN_HOURS_WORKED << " and " << MAX_HOURS_WORKED;
            cout << endl;
            cout << endl;
        }
    } while ((hoursWorked < MIN_HOURS_WORKED) || (hoursWorked > MAX_HOURS_WORKED));

    //Hourly rate must be between between MIN_HOURLY_RATE and MAX_HOURLY_RATE
    do {
        cout << "Enter hourly pay rate: ";
        cin >> hourlyRate;   

        if ((hourlyRate < MIN_HOURLY_RATE) || (hourlyRate > MAX_HOURLY_RATE)) {
            cout << "The hourly pay rate must be between " << MIN_HOURLY_RATE << " and " << MAX_HOURLY_RATE;
            cout << endl;
            cout << endl;
        }
    } while ((hourlyRate < MIN_HOURLY_RATE) || (hourlyRate > MAX_HOURLY_RATE)); 

}

//Processing Module: Run modules to calculate pay items.
void computePay(double hoursWorked, double &regularHours, double &overtimeHours, double hourlyRate, double &grossPay, double &taxAmount, double &netPay, double &deduction)
{
    //Call modules.
    computeHours(hoursWorked, regularHours, overtimeHours);
    
    //Call functions.
    grossPay = computeGrossPay(hourlyRate, regularHours, overtimeHours);
    taxAmount = computeTaxAmount(grossPay);
    deduction = transitDeduction();
    netPay = computeNetPay(grossPay, taxAmount, deduction);
}

//Processing Module: Calculate Regular Hours and Overtime Hours.
void computeHours(double hoursWorked, double &regularHours, double &overtimeHours)
{
    //Initialize variable
    overtimeHours = 0;

    if (hoursWorked > OVERTIME_CUTOFF) {
        regularHours = OVERTIME_CUTOFF;
        overtimeHours = hoursWorked - OVERTIME_CUTOFF;
    } else {
        regularHours = hoursWorked;
    }
}

//Processing Module: Compute Gross Pay.
double computeGrossPay(double hourlyRate, double regularHours, double overtimeHours)
{
    return (regularHours * hourlyRate) + (overtimeHours * (hourlyRate * 1.5));
}

//Processing Module: Compute Tax Amount.
double computeTaxAmount(double grossPay)
{
    return WITHHOLDING * grossPay;
}

//Processing Module: Compute Tax Amount.
void computeTaxAmount(double grossPay, double &taxAmount)
{
    taxAmount = WITHHOLDING * grossPay;
}

//Processing Module: Compute Net Pay.
double computeNetPay(double grossPay, double taxAmount, double deduction)
{
    return grossPay - taxAmount - deduction;
}

//Processing Module: Combine first, last names to full name.
string joinNames(string firstName, string lastName)
{
    return lastName + ", " + firstName;
}

//Processing Module: Deducts specific amounts if the employee uses the parking garage ($10), transit program ($5), bike locker ($1), or none ($0).
double transitDeduction()
{
    char answer;
    double deduction;

    if ((answer = repeatProgram("Does the employee use the parking garage? (Y/N)?: ")) == 'Y') {
        deduction = PARKING_DEDUCTION;
    } else if ((answer = repeatProgram("Does the employee use the transit program? (Y/N)?: ")) == 'Y') {
        deduction = TRANSIT_DEDUCTION;
    } else if ((answer = repeatProgram("Does the employee use a bike locker? (Y/N)?: ")) == 'Y') {
        deduction = BIKE_DEDUCTION;
    } else {
        deduction = NO_DEDUCTION;
    }

    return deduction;
  
}

//Procesing/Output Module: Prompt user to see if they want to add another worker.
char repeatProgram(string question)
{
    char answer;

    do {
        cout << endl;
        cout << question;
        cin >> answer;

        if (answer == 'y') {
            answer = 'Y';
        } else if (answer == 'n') {
            answer = 'N';
        }
        
        if ((answer != 'Y') && (answer != 'N')) {
            cout << "Please enter 'Y' for yes or 'N' for no.";
        }

    } while ((answer != 'Y') && (answer != 'N'));

    return answer;
}

//Processing Module: Calculate sum of gross pay amounts.
double grossPayAmountSum(double grossPayArray[], double count)
{
    //Counter and accumulator variables.
    int i;
    double sum;

    //Compute Sum of Gross Pay Array.
    sum = 0.0;
    for (i = 0; i < count; i++) {
        sum += grossPayArray[i];
    }

    return sum;
    
}

//Processing Module: Calculate average of gross pay.
double grossPayAverage(double grossPayArray[], double count)
{
    //Counter and accumulator variables.
    int i;
    double sum;
    double average;

    //Compute Sum of Gross Pay Array.
    sum = 0.0;
    for (i = 0; i < count; i++) {
        sum += grossPayArray[i];
    }

    //Compute average.
    return average = sum / count;
    
}

//Processing Module: Calculate maximum gross pay amount.
double maximumGrossPay(double grossPayArray[], double count)
{
    //Call Bubble Sort v.4.
    sortNumbersv4(grossPayArray, count);
    return grossPayArray[0];
}

//Processing Module: Calculate minimum gross pay amount.
double minimumGrossPay(double grossPayArray[], double count)
{
    //Call Bubble Sort v.3.
    sortNumbersv3(grossPayArray, count);
    return grossPayArray[0];

}

//Processing Module: Sorts the given array of numbers in ascending order using an optimized version of the Bubble Sort. (Supplied by Professor Krofchok)
void sortNumbersv3(double numbers[], double num_numbers)
{
    bool swaps;        // flags if elements were swapped during a pass
    int  pass;         // pass counter
    int  i;            // general counter for comparing adjacent elements
    int  temp_number;  // facilitates swapping of adjacent array elements

    num_passes = num_comparisons = num_swaps = 0;

    swaps = true;
    for (pass = 1; (pass < num_numbers) && swaps; pass++) {
        num_passes++;
        swaps = false;
        for (i = 0; i < num_numbers-pass; i++) {
            num_comparisons++;
            if (numbers[i] > numbers[i+1]) {
                num_swaps++;
                swaps = true;
                temp_number = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp_number;
            }
        }
    }
}

//Processing Module: Sorts the given array of numbers in descending order using an optimized version of the Bubble Sort. (Supplied by Professor Krofchok)
void sortNumbersv4(double numbers[], double num_numbers)
{
    bool swaps;        // flags if elements were swapped during a pass
    int  pass;         // pass counter
    int  i;            // general counter for comparing adjacent elements
    int  temp_number;  // facilitates swapping of adjacent array elements

    num_passes = num_comparisons = num_swaps = 0;

    swaps = true;
    for (pass = 1; (pass < num_numbers) && swaps; pass++) {
        num_passes++;
        swaps = false;
        for (i = 0; i < num_numbers-pass; i++) {
            num_comparisons++;
            if (numbers[i] < numbers[i+1]) {
                num_swaps++;
                swaps = true;
                temp_number = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp_number;
            }
        }
    }
}

//Output Module: Displays wage and employee header.
void showWageHeader(ostream &stream)
{
    //Row 1 Header
    stream << setw(25) << "Reg."   << "  "
           << setw(5)  << "Ovt."   << "  "
           << setw(8)  << "Hourly" << "  "
           << setw(7)  << "Gross"  << "  "
           << setw(22) << "Net"    << "  "
           << endl;
  
    //Row 2 Header
    stream << setw(0)  << "Name"   << "  "
           << setw(20) << "Hours"  << "  "
           << setw(2)  << "Hours"  << "  "
           << setw(5)  << "Rate"   << "  "
           << setw(7)  << "Pay"    << "  "
           << setw(8)  << "Taxes"  << "  "
           << setw(7)  << "Deduct" << "  "
           << setw(5)  << "Pay"    << "  "
           << endl;
    
    //Row 3 Header
    stream
           //Name Spacer
           << setfill('=') << setw(15) << "=" 
           << setfill(' ') << setw(6)  << " " 
           //Regular Hours Spacer
           << setfill('=') << setw(5)  << "="
           << setfill(' ') << setw(2)  << " "
           //Overtime Hours Spacer 
           << setfill('=') << setw(6)  << "="
           << setfill(' ') << setw(2)  << " "
           //Hourly Rate Spacer
           << setfill('=') << setw(7)  << "="
           << setfill(' ') << setw(3)  << " "
           //Gross Pay Spacer
           << setfill('=') << setw(6)  << "="
           << setfill(' ') << setw(2)  << " "
           //Taxes Spacer
           << setfill('=') << setw(6)  << "="
           << setfill(' ') << setw(2)  << " "
           //Deductions Spacer
           << setfill('=') << setw(8)  << "="
           << setfill(' ') << setw(2)  << ""
           //Net Pay Spacer
           << setfill('=') << setw(8)  << "="
           << setfill(' ') << setw(0)  << ""
           << endl;
  
}

//Output Module: Display worker data and pay rates with formatting applied.
void outputWageData(ostream &stream, string fullName, double regularHours, double overtimeHours, double hourlyRate, double grossPay, double taxAmount, double netPay, double deduction)
{
    stream << fixed << setprecision(2);
    
    stream << left    << setw(21)   << fullName
           << right   << setw(5)    << regularHours  << " "
           << right   << setw(7)    << overtimeHours << " "
           << setw(8) << hourlyRate << " "
           << setw(8) << grossPay   << " "
           << setw(7) << taxAmount  << " "
           << setw(9) << deduction  << " "
           << setw(9) << netPay     << " "
           << endl;

}

//Output Module: Displays Employee Payroll Summary Headings
void payrollHeader(ostream &stream)
{
    stream << fixed << setprecision(2);
    
    stream << endl
           << endl
           << setfill('=') << setw(25) << "="
           << endl
           << "Employee Payroll Summary"
           << endl 
           << setfill('=') << setw(25) << "="
           << setfill(' ') << setw(0) << " "
           << endl;    

    //Row Stream Spacer
    stream << endl
           << endl;

    //Row 1 Header
    stream << setw(30) << "Gross" << " "
           << endl;
    
    //Row 2 Header
    stream << setw(0) << "Name" << " "
           << setfill(' ') << setw(0) << " "
           << setw(22) << "Pay" << " "
           << endl;
    
    //Row 3 Header
    stream << setfill('=') << setw(20) << "="
           << setfill(' ') << setw(5) << " "
           << setfill('=') << setw(15) << "="
           <<endl;
}

//Output Module: Write employee payroll (full name, gross salary) summary to file.
void outputSummaryData(ostream &stream, string fullNameArray[], double grossPayArray[], int numEmployees)
{
    //Call Payroll Header Display
    ofstream outfile;
    payrollHeader(outfile);

    //Sort Data Descending
    sortNumbersv4(grossPayArray, numEmployees);    
    
    //Write Data
    int i;
    for (i = 0; i < numEmployees; i++) {
        stream << fullNameArray[i]
               << setfill(' ') << setw(14) << " "
               << grossPayArray[i]
               << endl;

    }

    //Write Total Gross Pay Data.
    stream << endl
           << endl
           << endl
           << endl 
           << "Total Gross Pay: "   << grossPayAmountSum(grossPayArray, numEmployees) << endl
           << "Average Gross Pay: " << grossPayAverage(grossPayArray, numEmployees)    << endl
           << "Minimum Gross Pay: " << minimumGrossPay(grossPayArray, numEmployees)    << endl
           << "Maximum Gross Pay: " << maximumGrossPay(grossPayArray, numEmployees);
}
