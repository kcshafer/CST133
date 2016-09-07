//----------------------------------------------------------------
//Programmer's Name: KC Shafer
//Program: Practice
//Program Flow (IPO):
//	Output the standard heading to the screen
//	Output a menu of mathematical operations from the screen
//	Input a meth operation menu choice from the keyboard
//	Determine the operation selected based on the menu option selected
//		Output a prompt to the screen to get two operands from the user
//		Input two operands from the keyboard
//		Calculate the result
//	Output an error message if an incorrect menu option was chosen
//	Determine if the menu option is in range
//		Output the mathematical operation name to the screen
//		Output the two operands with labels to the screen
//		Output the labeled results to the screen
//Grade:
//Comments:
//----------------------------------------------------------------
//

//for input and output on the screen
#include <iostream>

//for formatting of the output
#include <iomanip>

//To use the string data type
#include <string>

using namespace std;

const string COLLEGE = "SUNY Broome Community College";
const string MY_NAME = "KC Shafer";
const string EXERCISE_NAME = "CST 133 - Practice Exercise";

const int DIVIDER_WIDTH = 75;

int main(void)
{
	int calculationChoice;

	double operand1;
	double operand2;
	double result;

	string operationName;

	//set up formatting of fixed data on the output on the screen
	cout << fixed << setprecision(2);

	//output a divider on the screen
	cout << setfill('-') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//output to the screen the programmers name and college
	cout << COLLEGE << endl;
	cout << MY_NAME << endl;
	cout << EXERCISE_NAME << endl;

	//output a divider on the screen
	cout << setfill('-') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//output a menu on the screen for user selection
	cout << "Math Operation Selection" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;

	//output a divider on the screen
	cout << setfill('-') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//input the user's choice for the math operation
	cout << "Enter math operation choice (1, 2 or 3) : ";
	cin >> calculationChoice;

	//user entered one for addition
	if ( calculationChoice == 1 )
	{//choice 1

		//assign the operation name
		operationName = "add";

		//Input the operands from the user
		cout << "Enter the two operands to " << operationName << " seperated by a space: ";
		cin >> operand1 >> operand2;

		//calculate the result
		result = operand1 + operand2;
	}//end choice 1

	//user entered 2 for subtraction
	else if ( calculationChoice == 2 )
	{//choice 2
		//Assign the operation name
		operationName = "subtraction";
		//Input the operands from the user
		cout << "Enter the two operands to " << operationName << " seperated by a space: ";
		cin >> operand1 >> operand2;

		//calculate the result
		result = operand1 - operand2;
	}//end choice 2

	//user entered a 3 for multiplication
	else if ( calculationChoice == 3 )
	{//choice 3
		//assign the operation name
		operationName = "multiply";

		//Input the operands from the user
		cout << "Enter the two operands to " << operationName << " seperated by a space: ";
		cin >> operand1 >> operand2;

		//calculate the result
		result = operand1 * operand2;
	}//end choice 3

	//choice was not 1,2 or 3
	else
	{//default error message

		//output a divider on the screen
		cout << setfill('-') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

		//output the error message on the screen
		cout << "Invalid operation choice entered, ";
		cout << "no calculations performed" << endl;
		cout << "Please run the program again and select 1,2 or 3" << endl;
	}//default error message

	//Output the results if a valid choice was entered
	if ( calculationChoice == 1 || calculationChoice == 2 || calculationChoice == 3 )
	{//valid operation output
		
		//output a divider on the screen
		cout << setfill('-') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

		//Output the operation name, the two values and the result on the screen
		cout << "For the math operation: " << operationName << endl;
		cout << "Operand1: " << left << setw(12) << operand1 << right << setw(12) << "Operand2: " << operand2 << endl;
		cout << "Result is " << setw(12) << result << endl;
	
	}//valid operation output

	 //output a divider on the screen
	cout << setfill('-') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//ends the program, returns control to OS
	return 0;
}