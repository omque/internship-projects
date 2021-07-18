// Name of the Program: FizzBuzz - C++
// Author: Omair Qazi
// Date: 2021/07/18
//
//
// Purpose: Implement FizzBuzz in C++
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

//Namespace Declaration - not reccomended for production code.
using namespace std;

//Prototype Declarations
void fizzBuzz(int n);

//Main Function
int main()
{
    //Declare Variables
    int i;

    //Call Modules
    for (i = 1; i < 20; i++) {
        fizzBuzz(i);
    } 
    
}

//Fizz Buzz Processing Module
void fizzBuzz(int n) {
        
    if (n % 15 == 0) {
        cout << "FizzBuzz";
        cout << endl;
    } else if (n % 3 == 0) {
        cout << "Fizz";
        cout << endl;
    } else if (n % 5 == 0) {
        cout << "Buzz";
        cout << endl;
    } else {
        cout << n;
        cout << endl;
    }

}

