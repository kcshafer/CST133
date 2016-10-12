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
//  
//  
// 
//
//  
//  
//  
//  
//  
//  
//
//  
//  
//  
//  
//  
//-----------------------------------------------------------------------------

#include <iostream>

#include <iomanip>

#include <string>

using namespace std;

void outputDivider(int numberOfSymbols, char symbol);
void outputCourseHeading();
int* getGrades(int& grade1, int &grade2, int& grade3, int& grade4);
double getAverage(int grade1, int grade2, int grade3, int grade4);

int main()
{
	//set cout precision
	cout.precision(4);


	int* grades;

	//variables for holding the quiz grades
	int grade1;
	int grade2;
	int grade3;
	int grade4;

	//variable to store the calculated average
	double average;

	//output the standard course heading to the screen
	outputCourseHeading();

	//prompt the user for the four grades and store them
	grades = getGrades(grade1, grade2, grade3, grade4);

	cout << "Grades: " << grades;

	//calculate the average of the four grades
	average = getAverage(grade1, grade2, grade3, grade4);

	cout << average << endl;

	return 0;
}

//TODO: look at at documentation guide for how functions need to be commented
void outputDivider(int numberOfSymbols, char symbol)
{
	cout << setfill(symbol) << setw(numberOfSymbols + 1) << ' ' << setfill(' ') << endl;


}

void outputCourseHeading()
{
	cout << "SUNY Broome Community College" << endl;
	cout << "KC Shafer" << endl;
	cout << "CST 133 - Exercise 3" << endl;

	outputDivider(75, '-');
}

int* getGrades(int& grade1, int &grade2, int& grade3, int& grade4)
{
	cout << "Enter four quiz grades: " << endl;
	cin >> grade1 >> grade2 >> grade3 >> grade4;
	
	int grades[4] = { grade1, grade2, grade3, grade4 };

	return grades;
}

double getAverage(int grade1, int grade2, int grade3, int grade4)
{
	//variable to hold the calculated average
	double average;
	
	//calculate the average
	average = (grade1 + grade2 + grade3 + grade4) / (double)4;

	return average;
}
