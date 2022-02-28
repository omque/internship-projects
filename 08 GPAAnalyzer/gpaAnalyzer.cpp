// Name of the Program: "GPA Analyzer" - Homework 2 CISP 400 Fowler Spring 2022
// Author: Omair Qazi
// Date: 2022/02/19
//
//
// Purpose: Your friend has asked you to help them with a project. He needs to calculate his grades, but is finding it difficult to operate a calculator. Create a program which will accept an unlimited number of grades and calculates the average score. Assume each test is worth 100 points. Suggested letter grades scale of 90+ ’A’, 80+ ’B’, 70+ ’C’, 60+ ’D’ , less than 60 are ’F’.
//
//
// Description:
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

//Provides rand().
#include <cstdlib>

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
      std::to_string,
      std::ostream,
      std::ofstream;


//CLASS: DUE DATE
class Date
{    
    public:
        int day, year;
        string month;
        
        //Provides default values
        void setDate(int, string, int);
        void dateComponentTest();
        string getDate();

        
};

//DUE DATE::DATE Setter to define date
void Date::setDate(int d, string m, int y)
{
    day = d;
    month = m;
    year = y;
}

//DUE DATE::Retrieve date for unit test
string Date::getDate()
{
    return (month) + " " + to_string(day) + ", " + to_string(year); 
}

//DUE DATE:: Component test for output validation.
void Date::dateComponentTest()
{
    Date test;
    test.setDate(1, "January", 1970);

    if (test.getDate() == "January 1, 1970")
    {
        cout << endl << "Date Class: Unit Test Passed." << endl;
    } 
    else
    {
        cout << endl << "Date Class: Unit Test Failed." << endl;
    }

}

//CLASS: Score - for validating letter grade conversion and input.
class Score
{
    private:
        double score, input;
    
    public:
        void setScore(double, double);
        char getScore();
        void scoreComponentTest();
        string getInput();

};

//SCORE::Constructor to intialize score values.
void Score::setScore(double s, double i)
{
    score = s;
    input = i;
}

//SCORE::Checks grade input to see if valid.
string Score::getInput()
{
    if ((input > 100) || (input < 0))
    {
        return "Bad input.";    
    }
    
    return 0;
}

char Score::getScore()
{

    if (score < 60)
    {
        return 'F';
    }
    else if (score < 70)
    {
        return 'D';
    }
    else if (score < 80)
    {
        return 'C';
    }
    else if (score < 90)
    {
        return 'B';
    } else
    {
        return 'A';
    }
     
}

void Score::scoreComponentTest()
{
    Score test;
    test.setScore(95,102);

    if (test.getScore() == 'A')
    {
        cout << endl << "Score Class: Unit Test 1 Passed." << endl;
    } 
    else
    {
        cout << endl << "Score Class: Unit Test 1 Failed." << endl;
    }

    if (test.getInput() == "Bad input.")
    {
        cout << endl << "Score Class: Unit Test 2 Passed." << endl;
    } 
    else
    {
        cout << endl << "Score Class: Unit Test 2 Failed." << endl;
    }
}


//Prototype Declarations
void programGreeting(ostream &stream, Date);
void displayMainMenu(ostream &stream);
int menuSelection(int optionNumber);
void getInput(double &userInput);
void displayGrades(ostream &stream, double numericalGradeArray[], int numericalGradeArraySize);
void calculateGPA(ostream &stream, double numericalGradeArray[], int numericalGradeArraySize);
void returnToMainMenu();
void unitTest();

//Main Module
int main()
{

    //Instantiate Objects
    Date dueDate;

    //Declare variables
    int optionNumber = 0, 
        menuChoice;
    
    double userInput;

    //Declare array
    double* numericalGradeArray = nullptr;
    int numericalGradeArraySize = 0;
    numericalGradeArray = new double[numericalGradeArraySize];
        
    do {
        
        //Call Greeting Module
        programGreeting(cout, dueDate);
        
        //Call Main Menu Module
        displayMainMenu(cout);
        menuChoice = menuSelection(optionNumber);

        if (menuChoice == 1)
        {
            
            //Get grade from user.
            getInput(userInput);

            //Set user input to last index of array.
            numericalGradeArray[numericalGradeArraySize] = userInput;

            //Declare temporary array, increased by one element.
            double* tempArray = nullptr;
            numericalGradeArraySize++;
            tempArray = new double[numericalGradeArraySize];

            //Copy existing values into new array.
            for (int i=0; i < numericalGradeArraySize; i++)
            {
                tempArray[i] = numericalGradeArray[i];
            }
            
            //Delete reference to original array.
            delete[] numericalGradeArray;

            //Set array equal to new array.
            numericalGradeArray = tempArray;

            //Clear screen.
            cout << "\033[2J\033[1;1H";            
    
        } 
        else if (menuChoice == 2)
        {
            
            if (numericalGradeArraySize == 0)
            {
                cout << "There are no entries in the grade book." << endl;
            }
            else 
            {
                displayGrades(cout, numericalGradeArray, numericalGradeArraySize);    
            }
            
            //Return to main menu.
            returnToMainMenu();

        }
        else if (menuChoice == 3)
        {
            calculateGPA(cout, numericalGradeArray, numericalGradeArraySize);
            returnToMainMenu();

        }
        else if (menuChoice == 4)
        {
            unitTest();
            returnToMainMenu();
        }

    } while((menuChoice != 5));

    cout << endl 
         << "Goodbye!" 
         << endl
         << endl;

    return 0;
}

//Output Module: Program Greeting
void programGreeting(ostream &stream, Date)
{
    //Instantiate Date object and set default values
    Date dueDate;
    dueDate.setDate(20, "February", 2022);

    stream << endl
           << endl
           << setfill('*') << setw(50) << "*"
           << endl
           << setfill(' ') << setw(9) << " "
           << "CISP 400 Fowler Spring 2022"
           << endl
           << setfill(' ') << setw(9) << " "
           << "Homework 02  - \"GPA Analyzer\""
           << endl
           << setfill(' ') << setw(12) << " "
           << "Due: " << dueDate.month << " " << dueDate.day << ", " << dueDate.year
           << endl
           << setfill(' ') << setw(10) << " "
           << "Programmed By: Omair Qazi"
           << endl 
           << endl
           << "A grade management program and GPA calculator."
           << endl
           << "See source code header for full details."
           << endl 
           << setfill('*') << setw(50) << "*"
           << setfill(' ') << setw(0) << " "
           << endl; 
    
}

//Output Module: Display main menu to offer choices
void displayMainMenu(ostream &stream)
{ 
    
    //Menu Header   
    stream << endl
           << endl
           << setfill('=') << setw(30) << "="
           << endl
           << setfill(' ') << setw(3) << " "
           << "Welcome to GPA Analyzer"
           << endl 
           << setfill('=') << setw(30) << "="
           << setfill(' ') << setw(0) << " "
           << endl;    

    stream << endl
           << "Select an option from below:"
           << endl
           << endl;

    stream << "1. Add a grade"
           << endl
           << "2. Display all grades"
           << endl
           << "3. Process all grades"
           << endl
           << "4. Unit Tests"
           << endl
           << "5. Exit program"
           << endl
           << endl;
    
}

// Processing Module: Obtain menu selection from user.
int menuSelection(int optionNumber)
{   
    
    do {
        cout << "Enter your option: ";
        cin >> optionNumber;

        switch(optionNumber)
        {
            case 1:
                return optionNumber;
            case 2:
                return optionNumber;
            case 3:
                return optionNumber;
            case 4:
                return optionNumber;
            case 5:
                return optionNumber;
            default:
                cout << "That input is invalid. Please try again." << endl;
        }
        
        //Note: cin.fail() is used to detect if input is a non-integer but is not foolproof due to many edge cases. Used to prevent an infinite loop if a non integer value is entered. Invalid numerical options will continue the loop. Source: https://stackoverflow.com/a/18728791

        } while ((optionNumber != 1) && (optionNumber != 2) && (optionNumber != 3) && (cin.fail() != true));
    
    return 0;

}

//Input Module: Obtain user input for Grade
void getInput(double &userInput)
{
	
	cout << "Enter the numerical grade (0-100): ";
	cin >> userInput;
  
	while (userInput < 0 || userInput > 100)
		{
			cout << "Invalid Input" << endl;

			cout << "Enter the numerical grade (0-100): ";
			cin >> userInput;
		}
    
}

//Processing Module: Calculates Letter Grade and Displays Grades
void displayGrades(ostream &stream, double numericalGradeArray[], int numericalGradeArraySize)
{
    
	//Menu Header   
    stream  << endl
            << endl
            << setfill('=') << setw(30) << "="
            << endl
            << setfill(' ') << setw(9) << " "
            << "Grade Report"
            << endl 
            << setfill('=') << setw(30) << "="
            << setfill(' ') << setw(0) << " "
            << endl;

    stream  << "Numeric Score"
            << setfill(' ') << setw(5) << " "
            << "Letter Grade"
            << endl
            << setfill('=') << setw(30) << "=";
					  
    //Displays numerical grade and equivalent letter grade for the elements in the array.                      
    for (int i = 0; i < numericalGradeArraySize; i++)
        {

        //Assigns a letter grade for each numerical score in the array as it is being output.
        char letterGrade;
        
        if (numericalGradeArray[i] < 60)
        {
            letterGrade = 'F';
        }
        else if (numericalGradeArray[i] < 70)
        {
            letterGrade = 'D';
        }
        else if (numericalGradeArray[i] < 80)
        {
            letterGrade = 'C';
        }
        else if (numericalGradeArray[i] < 90)
        {
            letterGrade = 'B';
        } else
        {
            letterGrade = 'A';
        }
		
        //Set display precision to two decimal places.
        stream << fixed << setprecision(2);

        //Displays array and corresponding letter grade.
        stream << endl
               << setfill(' ') << setw(5) << " "
               << numericalGradeArray[i] 
               << setfill(' ') << setw(14) << " " << letterGrade
               << endl;

        }
	
}

//Processing Module: Calculates GPA and corresponding Letter Grade.
void calculateGPA(ostream &stream, double numericalGradeArray[], int numericalGradeArraySize)
{
    //Declare local variables for GPA Processing
    double arraySum = 0;
    double gpaScore;
    char letterGrade;

    //Calculate numericalGradeArray sum
    for (int i=0; i < numericalGradeArraySize; i++)
    {
        arraySum += numericalGradeArray[i];
    }

    //Calculate GPA Score
    gpaScore = arraySum/numericalGradeArraySize;

    //Assign letter grade to GPA Score.
    if (gpaScore < 60)
    {
        letterGrade = 'F';
    }
    else if (gpaScore < 70)
    {
        letterGrade = 'D';
    }
    else if (gpaScore < 80)
    {
        letterGrade = 'C';
    }
    else if (gpaScore < 90)
    {
        letterGrade = 'B';
    } else
    {
        letterGrade = 'A';
    }

    //Menu Header   
    stream  << endl
            << endl
            << setfill('=') << setw(30) << "="
            << endl
            << setfill(' ') << setw(9) << " "
            << "GPA Report"
            << endl 
            << setfill('=') << setw(30) << "="
            << setfill(' ') << setw(0) << " "
            << endl;

		stream  << "Numeric GPA"
                << setfill(' ') << setw(5) << " "
                << "Letter Grade"
                << endl
                << setfill('=') << setw(30) << "=";
        
        //Set display precision to two decimal places.
        stream << fixed << setprecision(2);
		
        stream << endl
               << setfill(' ') << setw(3) << " "
               << gpaScore 
               << setfill(' ') << setw(14) << " " << letterGrade
               << endl;

}

//Processing Module: Return to Main Menu and clear screen
void returnToMainMenu()
{
    do
    {     
        cout << endl;
        cout << "Press ENTER to return to main menu.";
        cin.get();
        


    } while (cin.get() != '\n');

    //Clear screen.
    cout << "\033[2J\033[1;1H";
}

//Processing Module: Runs Unit Test on Date Class objects
void unitTest()
{
    Date dueDate;
    dueDate.dateComponentTest();

    Score studentScore;
    studentScore.scoreComponentTest();
    
}