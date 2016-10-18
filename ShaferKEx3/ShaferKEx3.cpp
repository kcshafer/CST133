//------------------------------------------------------------------------
//Name: KC Shafer
//Program:  Exercise 3
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
//Comment:
//  
//  
//  
//Points lost -----------------------------------------------------------> 
//
//Function to Output the Standard Exercise Heading
//  Prototype, call and definition
//  Function appropriately named
//  Constants created and used for name and course/exercise
//  Output to the screen
//  Divider function called appropriately from this function
//
//  Comment:
//     
//    
//Points lost -----------------------------------------------------------> 
//
//Function to input 4 integers
//  Prototype, call and definition
//  Function appropriately named
//  Parameter variables correctly defined
//  One prompt & one input statement
//  
//  Comment:
//     
//    
//Points lost -----------------------------------------------------------> 
//
//Function to Calculate Average 
//  Prototype, call and definition
//  Function appropriately named
//  Single return function with a double return type created
//  Result ONLY returned in the function name, not in the
//    parameter list
//  Constant created for number of grades
//  
//  Comment:
//
//
//Points lost -------------------------------------------------> 
//
//Function to determine the Highest and Lowest quiz grade
//  Prototype, call and definition
//  Function appropriately named
//  One function efficiently sets the highest & lowest values
//  Both values returned in the parameter list
//  
//  Comment:
//     
//    
//Points lost -----------------------------------------------------------> 
//
//Function to determine the number of grades above average
//  Prototype, call and definition
//  Function appropriately named
//  Single return function with an integer return type created
//  Correct variables passed into the function
//  
//  Comment:
//     
//    
//Points lost -----------------------------------------------------------> 
//
//Function to Output Quizzes and Stats 
//  Prototype, call and definition
//  Function appropriately named
//  Correct variables passed into the function
//  
//  Comment:
//     
//    
//Points lost -----------------------------------------------------------> 
//
//Driver Main
//  Formatting for floating point set up 
//  Main is primarily calls to the functions
//  Names of functions reflect the task they perform
//  Functions called in the correct order
//
//  Comment:
//     
//    
//Points lost -----------------------------------------------------------> 
//
//Output
//  One text file created with output from the 3 executions
//  Correct input used for the testing
//  Output is correctly calculated
//  Output formatted and labeled appropriately
//  Output added to the project,
//     listed in the Solution Explorer Window
//  
//  Comment:
//     
//    
//Points lost -----------------------------------------------------------> 
//
//
//Total Possible Points for the Lab -------------------------------------> 100
//Points Lost ----------------------------------------------------------->  
//Lab Grade ------------------------------------------------------------->  
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Documentation Block
//Exercise 3
//Program Flow:
// Output course heading 
//  Prompt user for four integers (quiz grades)
//	Assign four integers into variables from input
//	calculate the average of four quiz grades
//  assign average to double variable
//  calculate the highest and lowest quiz grades
//  assign lowest and highest calculated values to int variables
//  calculate count of grades above average
//		examine each grade, comparing to average variable 
//		determine if grade is greater than average
//		if greater than average increment counter
//  output grades and calculates values to screen
//  
//  
//  
//  
//-----------------------------------------------------------------------------

#include <iostream>

#include <iomanip>

#include <string>

using namespace std;

// void/value
void outputDivider(int numberOfSymbols, char symbol);

// void/void
void outputCourseHeading();

// void/void
void outputResultsHeading();

// void/ value
void outputQuizResults(int grade1, int grade2, int grade3, int grade4, double average, int highest, int lowest, int aboveAvgCount);

// void / reference
void getGrades(int& grade1, int &grade2, int& grade3, int& grade4);

// void / reference
void getHighestAndLowest(int& grade1, int& grade2, int& grade3, int& grade4, int& lowest, int& highest);

//void / value
int countGradesAboveAverage(int grade1, int grade2, int grade3, int grade4, int average);

//void / value
double getAverage(int grade1, int grade2, int grade3, int grade4);

const string NAME = "KC Shafer";
const string TITLE = "Fall 2016 Quiz Grades";
const string COLLEGE = "SUNY Broome Community College";
const string ASSIGNMENT = "CST 133 - Exercise 3";

int main()
{
	//set cout precision
	cout.precision(3);

	//variables for holding the quiz grades
	int grade1;
	int grade2;
	int grade3;
	int grade4;

	//variable to store the calculated average
	double average;

	//variables to store the calculated lowest and highest
	int lowest;
	int highest;

	//variable to store count above average
	int aboveAvgCount;

	//output the standard course heading to the screen
	outputCourseHeading();

	//prompt the user for the four grades and store them
	getGrades(grade1, grade2, grade3, grade4);

	//output divider between entered grades and results
	outputDivider(75, '-');

	//calculate the average of the four grades
	average = getAverage(grade1, grade2, grade3, grade4);

	//get the highest and lowest quiz grades
	getHighestAndLowest(grade1, grade2, grade3, grade4, lowest, highest);

	//get the number of grades above average
	aboveAvgCount = countGradesAboveAverage(grade1, grade2, grade3, grade4, average);

	//output quiz results and calculations
	outputQuizResults(grade1, grade2, grade3, grade4, average,highest, lowest, aboveAvgCount );

	return 0;
}

//-------------------------------------------------------------------
//outputDivider - prints on the screen the symbol,
// the number of times specified by numberOfSymbols
//-------------------------------------------------------------------
void outputDivider(int numberOfSymbols, char symbol)
{
	cout << setfill(symbol) << setw(numberOfSymbols + 1) << ' ' << setfill(' ') << endl;


}

//-------------------------------------------------------------------
//outputCourseHeading - prints the standard course heading to 
// the screen
//-------------------------------------------------------------------
void outputCourseHeading()
{
	cout << COLLEGE << endl;
	cout << NAME << endl;
	cout << ASSIGNMENT << endl;

	outputDivider(75, '-');
}

//-------------------------------------------------------------------
//getGrades - prompt user for four integer grades
// and store them in four by reference variables
//-------------------------------------------------------------------
void getGrades(int& grade1, int &grade2, int& grade3, int& grade4)
{
	cout << "Enter four quiz grades: " << endl;
	cin >> grade1 >> grade2 >> grade3 >> grade4;
}

//-------------------------------------------------------------------
//getAverage - take in grades and calculate average
// returning double 
//-------------------------------------------------------------------
double getAverage(int grade1, int grade2, int grade3, int grade4)
{
	//variable to hold the calculated average
	double average;
	
	//calculate the average
	average = (double)(grade1 + grade2 + grade3 + grade4) / (double)4;

	return average;
}

//-------------------------------------------------------------------
//outputResultsHeading - outputs the programmer name 
// and the title of the output to the screen
//-------------------------------------------------------------------
void outputResultsHeading()
{
	cout << NAME << endl;
	cout << TITLE << endl;

	outputDivider(75,'-');
}

//-------------------------------------------------------------------
//outputQuizResults - takes in quiz grades and calculated values 
// and outputs them to the screen
//-------------------------------------------------------------------
void outputQuizResults(int grade1, int grade2, int grade3, int grade4, double average, int highest, int lowest, int aboveAvgCount)
{
	//output the result heading
	outputResultsHeading();

	//output all four grades
	cout << "Grade 1: " << grade1 << endl;
	cout << "Grade 2: " << grade2 << endl;
	cout << "Grade 3: " << grade3 << endl;
	cout << "Grade 4: " << grade4 << endl;

	//output the average
	cout << fixed << setprecision(3);
	cout << "Average: " << average << endl;

	//output the count above average
	cout << "Number of grades above the average: " << aboveAvgCount << endl;

	//output the highest and lowest grades
	cout << "Lowest Grade: " << lowest << endl;
	cout << "Highest Grade: " << highest << endl;
}

//-------------------------------------------------------------------
//getHighestAndLowest - takes in grades by reference and calculates
//the highest and lowest grade, storing them in 2 reference variables
//-------------------------------------------------------------------
void getHighestAndLowest(int& grade1, int& grade2, int& grade3, int& grade4, int& lowest, int& highest)
{
	//start with grade1 as highest and lowest
	lowest = grade1;
	highest = grade1;

	//check if grade2 is lower than lowest
	if (grade2 < lowest)
	{
		lowest = grade2;
	}

	//check if grade2 is higher than highest
	if (grade2 > highest)
	{
		highest = grade2;
	}

	//check if grade3 is lower than lowest
	if (grade3 < lowest)
	{
		lowest = grade3;
	}

	//check if grade3 is higher than highest
	if (grade3 > highest)
	{
		highest = grade3;
	}

	//check if grade4 is lower than lowest
	if (grade4 < lowest)
	{
		lowest = grade4;
	}

	//check if grade4 is higher than highest
	if (grade4 > highest)
	{
		highest = grade4;
	}
}

//-------------------------------------------------------------------
//countGradesAboveAverage - takes in 4 quiz grades and average, counts
// the number that are above the average, returning the integer count
//-------------------------------------------------------------------
int countGradesAboveAverage(int grade1, int grade2, int grade3, int grade4, int average)
{
	int averageCount;
	averageCount = 0;

	//check if grade1 is above average
	if (grade1 > average)
	{
		averageCount++;
	}

	//check if grade2 is above average
	if (grade2 > average)
	{
		averageCount++;
	}

	//check if grade3 is above average
	if (grade3 > average)
	{
		averageCount++;
	}

	//check if grade4 is above average
	if (grade4 > average)
	{
		averageCount++;
	}

	return averageCount;
}