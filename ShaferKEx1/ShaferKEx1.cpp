//----------------------------------------------------------------
//Programmer's Name: KC Shafer
//Program: Exercise 1
//Program Flow (IPO):
//TODO
//Grade:
//Comments:
//----------------------------------------------------------------

//for input and output on the screen
#include <iostream>

//for formatting of the output
#include <iomanip>

//To use the string data type
#include <string>

//for file manipulation
#include <fstream>

using namespace std;

const string COLLEGE = "SUNY Broome Community College";
const string MY_NAME = "KC Shafer";
const string EXERCISE_NAME = "CST 133 - Exercise 1";

const int DIVIDER_WIDTH = 75;

int main(void)
{
	//heading variables
	int stringLength;
	string taskTitle;

	//output file variable
	ofstream outputFile;
	outputFile.open("output.txt");

	//task variables
	int firstNumber;
	int secondNumber;
	int index;
	int counter;
	int squareRoot;
	int squareRootSum;

	//start heading to console
	cout << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	//COLLEGE
	stringLength = (int)COLLEGE.length();
	cout << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << COLLEGE << endl;

	//MY NAME
	stringLength = (int)MY_NAME.length();
	cout << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << MY_NAME << endl;

	//EX NAME
	stringLength = (int)EXERCISE_NAME.length();
	cout << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << EXERCISE_NAME << endl;

	cout << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	//end heading to console

	//write heading to output file
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	//COLLEGE
	stringLength = (int)COLLEGE.length();
	outputFile << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << COLLEGE << endl;

	//MY NAME
	stringLength = (int)MY_NAME.length();
	outputFile << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << MY_NAME << endl;

	//EX NAME
	stringLength = (int)EXERCISE_NAME.length();
	outputFile << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << EXERCISE_NAME << endl;

	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	//end writing header to output file


	//solution for task 1a

	//while loop
	taskTitle = "Task 1a - while loop";
	stringLength = (int)taskTitle.length();
	cout << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	cout << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << ' ' << setfill(' ') << endl;

	//priming read for two integers
	cout << "Please input two integers where the first integer is less than the second: " << endl;
	cin >> firstNumber >> secondNumber;

	//execute while the first or second number is null or the firstNumber is less than the second number
	while (firstNumber > secondNumber)
	{
		cout << "First number must be less than the second, try again: " << firstNumber << " " << secondNumber << endl;
		cin >> firstNumber >> secondNumber;
	}

	//write while loop results to output file
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	outputFile << "Results from Task 1a with a while loop" << endl;
	outputFile << "First Number:         " << firstNumber << setfill(' ') << "     Second Number:         " << secondNumber << endl;

	cout << "Integer values were successfully entered - processesing continues..." << endl;

	//do while loop
	taskTitle = "Task 1a - do while loop";
	stringLength = (int)taskTitle.length();
	cout << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	cout << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << ' ' << setfill(' ') << endl;

	do
	{
		//read first number and second number from input
		cout << "Please input two integers where the first integer is less than the second: " << endl;
		cin >> firstNumber >> secondNumber;

		//check if the firstNumber is less than the secondNumber
		if (firstNumber > secondNumber)
		{
			cout << "First number must be less than the second, try again: " << firstNumber << " " << secondNumber << endl;
		}
	} while (firstNumber > secondNumber);

	//write do while loop results to output file
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	outputFile << "Results from Task 1a with a do while loop" << endl;
	outputFile << "First Number:         " << firstNumber << setfill(' ') << "     Second Number:         " << secondNumber << endl;

	cout << "Integer values were successfully entered - processing continues..." << endl;

	//end solution for task 1a

	//solution for task 1b
	taskTitle = "Task 1b - for loop";
	stringLength = (int)taskTitle.length();
	cout << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	cout << setfill(' ') << setw((stringLength + DIVIDER_WIDTH) / 2) << ' ' << setfill(' ') << endl;

	//write title to output file
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	outputFile << taskTitle << endl;

	//line break after title
	outputFile << "" << endl;

	//write start and end number to file
	outputFile << "Start Value:         " << firstNumber << setfill(' ') << "     End Value:         " << secondNumber << endl;

	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;


	counter = 0;
	for (index = firstNumber; index < secondNumber; index++)
	{
		//check if number is odd
		if (index % 2 == 1)
		{
			outputFile << index << " ";

			//increment counter only if it's odd
			counter++;
		}

		//check if we have 5 numbers and if we do, print that line out
		if (counter == 5)
		{
			counter = 0;
			outputFile << endl;
		}
	}

	//end solution for task 1b

	//solution for task 1d

	//while loop for 1d
	taskTitle = "task 1d - while loop";
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	outputFile << taskTitle << endl;
	outputFile << "" << endl;
	outputFile << setw(10) << "Number" << setw(10) << "Square" << endl;
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	//reusing counter 
	counter = 1;
	while (counter <= 10)
	{
		//square the counter
		squareRoot = counter * counter;
		outputFile << setw(10) << counter << setw(10) << squareRoot << endl;

		counter++;
	}

	//for loop for 1d
	taskTitle = "task 1d - for loop";
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	outputFile << taskTitle << endl;
	outputFile << "" << endl;
	outputFile << setw(10) << "Number" << setw(10) << "Square" << endl;
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	//for loop for squares, reuses index for the loop variable
	for (index = 1; index <= 10; index++)
	{
		//square the counter
		squareRoot = index * index;
		outputFile << setw(10) << index << setw(10) << squareRoot << endl;
	}

	//end solution for task 1d

	//solution for task 1e
	taskTitle = "task 1e - for loop";
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	outputFile << taskTitle << endl;
	outputFile << "" << endl;
	outputFile << setw(10) << "Number" << setw(10) << "Square" << setw(10) << "Running Sum" << endl;
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	squareRootSum = 0;
	for (index = firstNumber; index < secondNumber; index++)
	{
		if (index % 2 != 0)
		{
			squareRoot = index * index;
			squareRootSum += squareRoot;
			outputFile << setw(10) << index << setw(10) << squareRoot << setw(10) << squareRootSum << endl;
		}
	}

	//end solution for task 1e

	//close output file
	outputFile.close();

	return 0;

}