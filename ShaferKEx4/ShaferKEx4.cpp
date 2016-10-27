//-----------------------------------------------------------------------------
//Name:
//Program:  Exercise 4
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
//Functions - General Requirements:
//  Follows the course naming style for function names
//  Prototypes above main
//  Function Parameter list like all code does not exceed 80 characters
//    (break into two lines where necessary)
//  Calls to functions primarily the ONLY code in the body of the main - modularity
//  Doc Block above each function definition
//  Function Definitions below the main function
//  Body of functions documented
//  Function Definitions blocked - each separated by a blank line
//Program Requirements:
//  Modularity - tasks in functions
//  The tasks:
//    Open the files
//    Check the input file to determine if it was successfully opened, 
//      set a flag & message appropriately
//    Output the required course heading to the output file
//    Output a message indicating successful opening of input file 
//      or a failure to open the input file 
//    Output the column heading for the exercise (The gender & the GPA)
//    Process the data in the input file one line at a time until all data is read
//    Assume the data file is of unknown length
//    Input the data, update the counts and accumulators appropriately
//    Calculate the averages for each gender
//    Output the statistical data for the file data
//    Close the files
//
//  Comments:
//  
//     
//    
//Points lost -----------------------------------------------------------> 
//
//
//Total Possible Points for the Lab -------------------------------------> 200
//Points Lost ----------------------------------------------------------->  
//Lab Grade ------------------------------------------------------------->  
//-----------------------------------------------------------------------------
//Documentation Block
//Exercise 4
//Program Flow
//  
//  
//  
//  
//  
//-----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

ifstream OpenInputFile(string fileName);
ofstream OpenOutputFile(string fileName);
void VerifyInputFile(ifstream& inputFile, string& msg, bool& validFile);
void OutputDivider(ofstream& outputFile);
void OutputCourseHeading(ofstream& outputFile);
void OutputSuccessfulFileMessage(ofstream& outputFile);
void OutputColumnHeading(ofstream& outputFile);
void InitializeAccumulatorVariables(double& femaleGPAS, double& maleGPAS);
void ProcessFile(ifstream& inputFile, double& femaleGPAS, double& maleGPAS);

//constants
const string COLLEGE = "SUNY Broome Community College";
const string NAME = "KC Shafer";
const string ASSIGNMENT = "CST 133 - Exercise 4";
const int DIVIDER_WIDTH = 75;

int main()
{
	//variables for input and output file
	ifstream inputFile;
	ofstream outputFile;

	//variable for messages
	string msg;

	//gpa accumulator variables
	double femaleGPAS;
	double maleGPAS;

	//boolean variable for input file validity
	bool validFile;

	//get input file
	inputFile = OpenInputFile("gpaByGender.txt");

	//get output file
	outputFile = OpenOutputFile("Ex4Out.txt");

	//verify that the input file is valid
	VerifyInputFile(inputFile, msg, validFile);

	//only continue if we have a valid file
	if (validFile)
	{
		//output the course heading in the output file 
		OutputCourseHeading(outputFile);

		//output the valid file message to the output file
		OutputSuccessfulFileMessage(outputFile);

		//output column headings to the output file
		OutputColumnHeading(outputFile);

		//initialize gpa accumulator variables
		InitializeAccumulatorVariables(femaleGPAS, maleGPAS);

		//process the file accumulating the gender gpas in passed accumulator variables
		ProcessFile(inputFile, femaleGPAS, maleGPAS);
	}

	//close the files 
	outputFile.close();
	inputFile.close();

	return 0;
}

//-------------------------------------------------------------------
//
//
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// OpenInputFileName - takes in a fileName and opens it as a
// ifstream inputfile and returns it 
//-------------------------------------------------------------------
ifstream OpenInputFile(string fileName)
{
	//initialize input file
	ifstream inputFile;
	
	//open the input file with the passed file name
	inputFile.open(fileName);

	return inputFile;
}

//-------------------------------------------------------------------
// OpenOutputFile - takes in a string file name and opens an ofstream
// with the name and returns it 
//-------------------------------------------------------------------
ofstream OpenOutputFile(string fileName)
{
	//initialize output file
	ofstream outputFile;

	//open the output file with the passed file name
	outputFile.open(fileName);

	return outputFile;
}

//-------------------------------------------------------------------
// Verify InputFile - takes by ref inputFile string msg and bool validFile
// verifying file exists and has data, setting bool and msg
//-------------------------------------------------------------------
void VerifyInputFile(ifstream& inputFile, string& msg, bool& validFile)
{
	//initialize input file error message string
	msg = "Input File Errors: ";

	//initialize validFile to false - we will prove in the function that it is true
	validFile = false;
	
	//prime the input file eof function
	inputFile.peek();

	//check if file exists
	if (!inputFile)
	{
		msg.append("Input file does not exist.");
	}
	//check if file is not empty
	else if (inputFile.eof())
	{
		msg.append("Input file is empty");
	}
	else {
		validFile = true;
	}
}

//-------------------------------------------------------------------
// Output Divider - output the standard dashed divider line to the 
// passed by ref output file
//-------------------------------------------------------------------
void OutputDivider(ofstream& outputFile)
{
	outputFile << setfill('-') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
}

//-------------------------------------------------------------------
//OutputCourseHeading - output constant course information to header
// of passed by ref file
//-------------------------------------------------------------------
void OutputCourseHeading(ofstream& outputFile)
{
	OutputDivider(outputFile);

	outputFile << setfill(' ') << setw((COLLEGE.length() + DIVIDER_WIDTH) / 2) << COLLEGE << endl;
	outputFile << setfill(' ') << setw((NAME.length() + DIVIDER_WIDTH) / 2) << NAME << endl;
	outputFile << setfill(' ') << setw((ASSIGNMENT.length() + DIVIDER_WIDTH) / 2) << ASSIGNMENT << endl;

	OutputDivider(outputFile);
}

//-------------------------------------------------------------------
// OutputSuccessfulFileMessage - output successfully opened file
// message to by ref outputfile 
//-------------------------------------------------------------------
void OutputSuccessfulFileMessage(ofstream& outputFile)
{
	outputFile << "gpaByGender.txt file successfully opened Processing Continues..." << endl;

	OutputDivider(outputFile);
}

//-------------------------------------------------------------------
// OutputColumnHeading - output the gender and gpa column headings
// to the passed by ref output file
//-------------------------------------------------------------------
void OutputColumnHeading(ofstream& outputFile)
{
	outputFile << setfill(' ') << setw(75/3) << "Gender" << setw(75/3) << "GPA" << endl;
}

//-------------------------------------------------------------------
// InitializeAccumulatorVariables - initialize the accumulator variables
// passed by reference
//-------------------------------------------------------------------
void InitializeAccumulatorVariables(double& femaleGPAS, double& maleGPAS)
{
	femaleGPAS = 0;
	maleGPAS = 0;
}

//-------------------------------------------------------------------
// ProcessFile - process the file, checking if the line is male or fem
// and accumulating the gpas in corresponding variable
//-------------------------------------------------------------------
void ProcessFile(ifstream& inputFile, double& femaleGPAS, double& maleGPAS)
{
	//variable to store the gender read from the file
	string gender;
	
	//variable to hold standardized gender value
	char standardizedGender;

	//variable to store the gpa read from the file
	double gpa;

	//prime the loop
	//inputFile >> gender >> gpa;

	//cout << "GENDER: " << gender << endl;
	//cout << "GPA: " << gpa << endl;

	//read from file line by line, assigning the gender and gpa values in each line to variables
	//will return false at the end of file, doesn't requiring priming => all executed in loop
	while (inputFile >> gender >> gpa)
	{
		cout << "GENDER: " << gender << endl;
		cout << "GPA: " << gpa << endl;

		//check that the string is one character so we can cast it to char
		cout << "STRING LEN: " << gender.length() << endl;
		
		//NOTE TO SELF: working on validating that the string length is 1 so that it can be cast into a char
		// then upcased to test that it is an m or f, probably using a case statement.

		//standardizedGender = toupper(gender);

		//cout << "Standardized GENDER: " << standardizedGender << endl;
	}
}