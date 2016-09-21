//-----------------------------------------------------------------------------
//Name: KC Shafer
//Program:  Exercise 1
//Grade:
//General Comments:  
//                   
//                   
//-----------------------------------------------------------------------------
//Met Standard Programming Requirements
// Students should review this PDF file to assure these specs are met
//  which can be found in Angel in Important Course Documents
// There is a summary of the program requirements doc that can be
// found in the lab link in Angel
// 
// Comments for each category of the Programming Standards:
//  Project: 
//   
//  Program Order:
//   
//  Main Doc Block:
//
//  Identifiers:
//   
//  Style Requirements:
//   
//  Points Lost -------------------------------------------------> 
//
//-----------------------------------------------------------------------------
//Program Specifications
//
//General Exercise Requirements
//  Heading
//    Includes the required course heading output to the output file
//      centered
//    Includes the college, your name, course & Exercise number
//    Heading printed to the screen and to the output file
//  Divider
//    One line output divider used to separate and block any output
//    to the file or the screen
//
//Comment:
//  
//  
//  
//Points lost -----------------------------------------------------------> 
//
//Task 1a
//  Efficient solution for the loop type
//  Solved using a while loop FIRST
//  Solved a second time using a do-while loop
//  while loop
//    uses input with a primer and a changer
//  do while
//   user input statement ONLY ONCE in the loop
//  Error message printed on screen if invalid user input
//  values from each loop stored in the SAME variables
//  values from second loop used in later processing
//  Output
//   Output to the screen includes:
//     Task # & loop type, prompt & user input, error message where 
//        appropriate
//   Output to the file includes:
//     Task # and loop type
//     Two valid values eventually entered from each loop execution
//Comment:
//  
//  
//  
//Points lost -----------------------------------------------------------> 
//
//Task 1b
//  Efficient solution for the loop type
//  Solved using a for loop ONLY
//  Values used are from Task 1A do while loop
//  Output
//    Task # and loop type
//    Inclusive of start and end range value output to the output file
//    Output of numbers in 5 formatted & aligned columns
//Comment:
//  
//  
//  
//Points lost -----------------------------------------------------------> 
//
//Task 1d
//  Efficient solution for the loop type
//  Solved using a while loop FIRST
//  Solved a second time using a for loop
//  Output
//    Task # and loop type for EACH type
//    Formatted column headings using setw
//    Each pair - number & square output on a separate line
//Comment:
//  
//  
//  
//Points lost -----------------------------------------------------------> 
//
//Task 1e
//  Efficient solution for the loop type
//  Solved using a for loop
//  Output
//    ONLY ODD values included in the output
//    Task # & loop type
//    Formatted column headings using setw
//    Aligned output of number, square and running total
//      each set of values on one line in the output file
//Comment:
//  
//  
//  
//Points lost -----------------------------------------------------------> 
//
//Miscellaneous errors not anticipated by your professor
//  
//Comment:
//  
//  
//Points lost -----------------------------------------------------------> 
//
//-----------------------------------------------------------------------------
//Total Possible Points for the Lab -------------------------------------> 100
//Points Lost ----------------------------------------------------------->  
//Lab Grade ------------------------------------------------------------->  
//-----------------------------------------------------------------------------
//
//Documentation Block
//Exercise 1
//Open the logical output file fout for Ex1Output.txt
//Output the course heading to the screen and to the output file
//Task 1a
//IPO:
//Input two integer values from the keyboard
//While the first is less than or equal to the second:
// Output an error message to the screen stating first is less than or
//  or equal to the second
//  Input two integer values from the keyboard
// Output success message to the screen
// Output the two values to the output file
//
//Task 1b
//IPO:
//For each value from the first value to the second value
// from the previous task:
//  Determine if the value is odd,
//   Output the value to the output file
//   Determine if five values have been output to the file
//     move to the next line in the output file.
//
//Task 1d
//IPO:
//Output the values from 1 to 10 along with their squares to the output file
//
//Task 1e
//IPO:
//Initialize the accumulator variable
//For each value entered by the user from the first value
//  to the second value:
//  Determine if the value is odd
//    Calculate the square of the value
//    Accumulate the square in the sum of squares
//  Output the value along with its square, and
//   the running sum of the squares to the output file
//
//Close the logical output file for Ex1Output.txt
//-----------------------------------------------------------------------------
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