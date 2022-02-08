// Name of the Program: "Pig" - Homework 1 CISP 400 Fowler Spring 2022
// Author: Omair Qazi
// Date: 2022/01/29
//
//
// Purpose: You are coding a simple game called Pig. Players take turns rolling a die. The die determines how many points they get. You may get points each turn your roll (turn points), you also have points for the entire game (grand points). 
//
//
// Description: The first player with 100 grand points is the winner. The rules are as follows: Each turn, the active player faces a decision (roll or hold): Roll the die. If it’s is a: 1: You lose your turn, no turn total points are added to your grand total. 2-6: The number you rolled is added to your turn total. Hold: Your turn total is added to your grand total. It’s now the next player’s turn.
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
      std::ostream,
      std::ofstream;

//Prototype Declarations
void programGreeting(ostream &stream);
void studentName(string firstName, string lastName, string &fullName);
void displayMainMenu(ostream &stream, string fullName);
int menuSelection(int optionNumber);
void menuManager(int &activePlayer, int optionNumber, int diceRollResult, int &turnTotal, int &grandTotal, int playerOneTurnTotal, int playerTwoTurnTotal, int playerOneGrandTotal, int playerTwoGrandTotal, string fullName, ostream &stream, int &playerHighScorePtr);
void scoreTracker(int activePlayer, int turnTotal, int grandTotal, int &playerOneTurnTotal, int &playerTwoTurnTotal, int &playerOneGrandTotal, int &playerTwoGrandTotal);
void rollOption(int diceRollResult, int &turnTotal, int &grandTotal, int &activePlayer);
void holdOption(int &turnTotal, int &grandTotal, int &activePlayer);
void quitOption();
int diceRoll(int diceRollResult);
int randomNumberGenerator(int minimumValue, int maximumValue, int randomNumberResult);
void selectPlayer(int &playerSelect, int &activePlayer);
void displayScoresPlayerOne(ostream &stream, int playerOneTurnTotal, int playerOneGrandTotal, int activePlayer, int turnTotal, int grandTotal);
void displayScoresPlayerTwo(ostream &stream, int playerTwoTurnTotal, int playerTwoGrandTotal, int activePlayer, int turnTotal, int grandTotal);
void highScore(int playerOneGrandTotal, int playerTwoGrandTotal, int &playerHighScorePtr);


int main()
{
    //Declare variables.
    string firstName, 
           lastName, 
           fullName;
    
    int    optionNumber,
           diceRollResult,
           minimumValue,
           maximumValue,
           randomNumberResult,
           playerTurnTotal,
           grandTotal,
           turnTotal,
           playerOneTurnTotal,
           playerTwoTurnTotal,
           playerOneGrandTotal,
           playerTwoGrandTotal,
           activePlayer,
           playerSelect,
           playerHighScorePtr;

    
    
    //Set Random Number Generator to specific seed.
    //Specification C1 - Fixed Seed.
    // srand(3);

    //Specification A3 - Use of Random Number Generator
    //Specification A4 - Use of Random Number Generator
    srand(randomNumberGenerator(10, 20, randomNumberResult));

    //Initializations
    turnTotal = 0;
    grandTotal = 0;
    playerOneTurnTotal = 0; 
    playerTwoTurnTotal = 0; 
    playerOneGrandTotal = 0; 
    playerTwoGrandTotal = 0;


    //Call Modules.
    programGreeting(cout);
    selectPlayer(playerSelect, activePlayer);
    studentName(firstName, lastName, fullName);

    //Display menu while active players change.
    while ((activePlayer == 1) || (activePlayer == 2))
    {
        
        displayMainMenu(cout,fullName);
        menuManager(activePlayer, 
                    menuSelection(optionNumber), 
                    diceRoll(diceRollResult), 
                    turnTotal, 
                    grandTotal, 
                    playerOneTurnTotal, 
                    playerTwoTurnTotal, 
                    playerOneGrandTotal, 
                    playerTwoGrandTotal,
                    fullName,
                    cout,
                    playerHighScorePtr);

    }

}

//Output Module: Program Greeting
void programGreeting(ostream &stream)
{
    stream << endl
           << endl
           << setfill('*') << setw(45) << "*"
           << endl
           << setfill(' ') << setw(9) << " "
           << "CISP 400 Fowler Spring 2022"
           << endl
           << setfill(' ') << setw(12) << " "
           << "Homework 01  - \"Pig\""
           << endl
           << setfill(' ') << setw(12) << " "
           //Specification B2 - Display Due Date
           << "Due: January 30, 2022"
           << endl 
           << endl
           << "An implementation of the dice roll game \"Pig\"."
           << endl
           << "See source code header for full details."
           << endl 
           << setfill('*') << setw(45) << "*"
           << setfill(' ') << setw(0) << " "
           << endl; 
    
}

//Output Module: Display main menu to offer choices
//Specification C3 - Numeric Menu
void displayMainMenu(ostream &stream, string fullName)
{ 
    
    //Menu Header   
    stream << endl
           << endl
           << setfill('=') << setw(30) << "="
           << endl
           << setfill(' ') << setw(3) << " "
           << "Pig: A Simple Dice Game"
           << endl 
           << setfill('=') << setw(30) << "="
           << setfill(' ') << setw(0) << " "
           << endl;    
    
    stream << setfill(' ') << setw(2) << " "
           << "Programmed By: " << fullName
           << endl
           << setfill('=') << setw(30) << "="
           << setfill(' ') << setw(0) << " "
           << endl; 

    stream << endl
           << "Select an option from below:"
           << endl
           << endl;

    stream << "1. Roll dice."
           << endl
           << "2. Hold for this turn."
           << endl
           << "3. Quit program."
           << endl
           << endl;
    
    
}

// Processing Module: Obtain menu selection from user.
//Specification C4 - Bulletproof Menu
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
            default:
                cout << "That input is invalid. Please try again." << endl;
        }
        
        //Note: cin.fail() is used to detect if input is a non-integer but is not foolproof due to many edge cases. Used to prevent an infinite loop if a non integer value is entered. Invalid numerical options will continue the loop. Source: https://stackoverflow.com/a/18728791

        } while ((optionNumber != 1) && (optionNumber != 2) && (optionNumber != 3) && (cin.fail() != true));
    
    return 0;

}

//Processing Module: Manage menu options and call related sub-modules to execute menu items.
void menuManager(int &activePlayer, int optionNumber, int diceRollResult, int &turnTotal, int &grandTotal, int playerOneTurnTotal, int playerTwoTurnTotal, int playerOneGrandTotal, int playerTwoGrandTotal, string fullName, ostream &stream, int &playerHighScorePtr)
{   
    //Select Menu 1: Roll
    if (optionNumber == 1)
    {
        rollOption(diceRoll(diceRollResult), turnTotal, grandTotal, activePlayer);

        displayScoresPlayerOne(cout, playerOneTurnTotal, playerOneGrandTotal, activePlayer, turnTotal, grandTotal);

        displayScoresPlayerTwo(cout, playerTwoTurnTotal, playerTwoGrandTotal, activePlayer, turnTotal, grandTotal);

    } 
    
    //Select Menu 2: Hold
    else if (optionNumber == 2) 
    {   
        holdOption(turnTotal, grandTotal, activePlayer);

        displayScoresPlayerOne(cout, playerOneTurnTotal, playerOneGrandTotal, activePlayer, turnTotal, grandTotal);

        displayScoresPlayerTwo(cout, playerTwoTurnTotal, playerTwoGrandTotal, activePlayer, turnTotal, grandTotal);

    } 
    
    //Select Menu 3: Quit
    else if (optionNumber == 3) {
        
        quitOption();

        displayScoresPlayerOne(cout, playerOneTurnTotal, playerOneGrandTotal, activePlayer, turnTotal, grandTotal);

        displayScoresPlayerTwo(cout, playerTwoTurnTotal, playerTwoGrandTotal, activePlayer, turnTotal, grandTotal);

        //Specification B4 - Display High Score
        highScore(playerOneGrandTotal, playerTwoGrandTotal, playerHighScorePtr);
        
        exit(0);
    }

}

//Processing Module: Menu Option 1 - Dice Roll
void rollOption(int diceRollResult, int &turnTotal, int &grandTotal, int &activePlayer)
{
    //Perform a dice roll.
    cout << endl 
         << "You rolled a: " << diceRollResult << endl;
            
    //If dice roll is one, turn ends and no turn total points are awarded.
    if (diceRollResult == 1)
    {
        turnTotal = 0;
        grandTotal += turnTotal;
        
        //End Turn and switch active player.
        if (activePlayer == 1)
        {
            activePlayer = 2;
        } else
            activePlayer = 1;

        cout << "Your turn has ended." << endl;

    } 
    
    //If dice roll is between 2-6 then add amount to turn total.
    else if ((diceRollResult >= 2) && (diceRollResult <=6))
    {    
        // cout << "This is inside the fucntion:" << diceRollResult;
        turnTotal = diceRollResult;
        grandTotal += turnTotal;
        
    }

}

//Processing Module: Menu Option 2 - Hold
void holdOption(int &turnTotal, int &grandTotal, int &activePlayer)
{
        
    //End Turn and switch active player.
    if (activePlayer == 1)
    {
        activePlayer = 2;
    } else
        activePlayer = 1;

    cout << "Your turn has ended." << endl;
    
}

//Processing Module: Menu Option 3 - Quit
void quitOption()
{
    cout << endl;
    cout << "Thank you for playing." << endl;
    cout << "These are the final scores: " << endl;

}

// Processing Module: Keep track of scores per round and display the results for Player One.
//Specification B1 - Display Turn Stats (1 of 2)
void displayScoresPlayerOne(ostream &stream, int playerOneTurnTotal, int playerOneGrandTotal, int activePlayer, int turnTotal, int grandTotal)
{
    
    //Assign scores to active player totals.
    if (activePlayer == 1)
    {
        playerOneTurnTotal = turnTotal;
        playerOneGrandTotal = grandTotal;

    }     
    //Display Sub-module for scores
    //TODO: This can be factored out, but due to time considerations was not done so in this version.

    //Menu Header   
    stream << endl
           << endl
           << setfill('=') << setw(50) << "="
           << endl
           << setfill(' ') << setw(20) << " "
           << "Score Tracker"
           << endl 
           << setfill('=') << setw(50) << "="
           << endl
           << setfill(' ') << setw(0) << " "
           << endl;

    stream << setfill(' ') << setw(20) << " "
           << "Turn Score"
           << setfill(' ') << setw(8) << " "
           << "Grand Total"
           << endl 
           << setfill('=') << setw(50) << "="
           << setfill(' ') << setw(0) << " "
           << endl;     
    
    stream << setfill(' ') << setw(1) << " "
           << "Player One"
           << setfill(' ') << setw(14) << " "
           << playerOneTurnTotal
           << setfill(' ') << setw(17) << " "
           << playerOneGrandTotal
           << endl
           << setfill('=') << setw(50) << "="
           << setfill(' ') << setw(0) << " "
           << endl;

       
}

// Processing Module: Keep track of scores per round and display the results for Player Two.
//Specification B1 - Display Turn Stats (2 of 2)
void displayScoresPlayerTwo(ostream &stream, int playerTwoTurnTotal, int playerTwoGrandTotal, int activePlayer, int turnTotal, int grandTotal)
{
    //Assign scores to active player totals.
    if (activePlayer == 2)
    {
        playerTwoTurnTotal = turnTotal;
        playerTwoGrandTotal = grandTotal;

    }     

    stream << setfill(' ') << setw(1) << " "
            << "Player Two"
            << setfill(' ') << setw(14) << " "
            << playerTwoTurnTotal
            << setfill(' ') << setw(17) << " "
            << playerTwoGrandTotal
            << endl
            << setfill('=') << setw(50) << "="
            << setfill(' ') << setw(0) << " "
            << endl;
}

//Processing Module: Dice rolling function to produce a randomly generated number between 1 and 6.
//Specification A1 - D6() Function
int diceRoll(int diceRollResult)
{
    //Lower and upper bounds for roll.
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 6;

    return diceRollResult = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

}

//Processing Module: Random Number generator for use to determine seed number.
//Specification A2 - RandomNumber() function
int randomNumberGenerator(int minimumValue, int maximumValue, int randomNumberResult)
{
    
    //Check that parameters are valid for random number generation.
    //Specification A3 - Protect Random number input
    if ((maximumValue > minimumValue) && (minimumValue > 1) && (maximumValue < 100)) {
        
        randomNumberResult = rand() % (maximumValue - minimumValue + 1) + minimumValue;

        //Check that resulting random number is acceptable for use.
        //Specification A4 - Protect Random Number output
        if (randomNumberResult > 100) {
            
            cout << "Error: Exit -2 (Bad Random Number)" << endl;
            exit (-2);
        }
        else 
        {
            return randomNumberResult;
        }
    } 
    else
    {
        //Exit with Error Code 1 - Bad Parameters.
        cout << "Error: Exit -1 (Bad Parameters)" << endl;
        exit(-1);
    }
    
    
}

//Output Module: Takes first and last name, returns full name of student.
//Specification C2 - Student Name
void studentName(string firstName, string lastName, string &fullName)
{
    cout << endl;
    cout << "Student, please enter your first name: ";
    cin >> firstName;
    cout << "Please enter your last name: ";
    cin >> lastName;

    fullName = firstName + " " + lastName;

}

//Processing Module: Select Active Player
void selectPlayer(int &playerSelect, int &activePlayer)

{
    cout << endl;
    cout << "Are you Player One or Player Two?" << endl;
    cout << "Please answer with '1' or '2': ";
    cin >> playerSelect;
    
    if (playerSelect == 1)
    {
        activePlayer = 1;

    } else if (playerSelect == 2)
    {
        activePlayer = 2;

    } else
    {
        cout << "I did not understand that, please play again.";
        exit(1);
    }

    cout << "Welcome Player " << activePlayer << endl;
}

//Processing Module: Calculate High Score
//Specification B3 - Hi Score on Heap
void highScore(int playerOneGrandTotal, int playerTwoGrandTotal, int &playerHighScorePtr)
{
    if (playerOneGrandTotal > playerTwoGrandTotal) 
    {
        int *playerHighScorePtr = new int;
    
        *playerHighScorePtr = playerOneGrandTotal;

        cout << "The High Score is: " << *playerHighScorePtr;

        delete new int;

    } else
    {
        int *playerHighScorePtr = new int;
    
        *playerHighScorePtr = playerTwoGrandTotal;

        cout << "The High Score is: " << *playerHighScorePtr;

        delete new int;
    }
}