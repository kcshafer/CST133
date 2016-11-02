#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

//-----------------------------------------------------------------------------
//Exercise 5 Grading Block
//Programmer:
//Grade ->
//General Comments from your professor:
//  
//  
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
//FillArray Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Calculates the values for the array from startValue correctly
//  for loop used to fill the integer array
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//ReadFileArrayData Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Input of data until array filled or all data input
//
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//OutputArray Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Clearly labeled output sent to the output file
//  Comment:
//Points lost -------------------------------------------------> 
//
//CalculateAverage Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Correctly calculates the average of the array
//  Single return function
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//OutputAverages Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Clearly labeled output sent to the output file
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//CalculateOccurrences Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Correctly accomplish task defined
//  Single return function
//  Comment:
//Points lost -------------------------------------------------> 
//
//OutputOccurrences Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Clearly labeled output sent to the output file
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//CalculateHighest Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Calculates & returns the highest value in the array, 
//  assumes no particular range of values in the array
//  Calculates & returns the number of times highest was
//  found in the array
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//OutputHighestData Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Clearly labeled output sent to the output file
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//MatchByPosition Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Single return function that returns the number of
//    matches by position in the two arrays
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//OutputMatchCount Function
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Clearly labeled output sent to the output file
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//IncreaseArray Function - BONUS
//  Prototype, call and definition
//  Function named correctly
//  Parameter list correct
//  Each array value increased by the value passed in
//  Comment:
//Points GAINED ---------------------------------------------------------> 
//
//Driver Main
//  Files opened in the main
//  Formatting for floating point set up 
//  Main is primarily calls to the functions
//  Functions called in the correct order (by tasks)
//  Files closed in the main
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//Output
//  One txt file created with all output
//  Correct input used for the testing to create correct output
//  Output formatted and labeled appropriately
//  Output added to the project,
//     listed in the Solution Explorer Window
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//Miscellaneous
//  No additional functions written beyond those specified
//  Errors not anticipated by your professor
//  Comment:
//Points lost -----------------------------------------------------------> 
//
//Possible Points -------------------------------------------------------> 200
//Total Points Lost ----------------------------------------------------->  
//Points BEFORE Bonus --------------------------------------------------->  
//Bonus Points Gained --------------------------------------------------->  
//Exercise Grade -------------------------------------------------------->  
//-----------------------------------------------------------------------------
//Documentation Block
//Exercise 5
//Program Flow
//  
//  
//  
//  
//  
//-----------------------------------------------------------------------------

using namespace std;

//constants
const int MAX_SIZE = 20;

ifstream OpenInputFile(string fileName);
ofstream OpenOutputFile(string fileName);
void FillArray(ifstream& inputFile, int calculatedArray[], int& calculatedArraySize, int maxSize);
void ReadFileArrayData(ifstream& inputFile, int fileArray[], int& fileArraySize, int maxSize);
void OutputArray(int arr[], int arraySize);

int main()
{
	
	//array variables
	int calculatedArray[MAX_SIZE];
	int fileArray[MAX_SIZE];

	//variables to hold array size
	int calculatedArraySize;
	int fileArraySize;

	//variables for input and output files
	ifstream inputFile;
	ofstream outputFile;

	//open the input and output files
	inputFile = OpenInputFile("Ex5Numbers.txt");
	outputFile = OpenOutputFile("output.txt");
	
	//fill the calculated array
	FillArray(inputFile, calculatedArray, calculatedArraySize, MAX_SIZE);

	//read values into file array from input file
	ReadFileArrayData(inputFile, fileArray, fileArraySize, MAX_SIZE);

	//output the array results from both arrays
	OutputArray(calculatedArray, calculatedArraySize);

	return 0;
}

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

	//set output file precision
	outputFile.precision(3);
	outputFile << setprecision(3);

	return outputFile;
}

//-------------------------------------------------------------------
// FillArray - takes an input file, array and array size and fills 
// the array based on values in the input file
//-------------------------------------------------------------------
void FillArray(ifstream& inputFile, int calculatedArray[], int& calculatedArraySize, int maxSize)
{
	//variables for start value and numbers of values to calculate
	int startValue;
	int numberToCalculate;

	//variable to store the calculated value
	int calculatedValue;

	//initialize the calculated array size variable
	calculatedArraySize = 0;

	//get the values from the input file
	inputFile >> startValue >> numberToCalculate;

	//store start value in first array position and increment array size
	calculatedArray[0] = startValue;
	calculatedArraySize++;
	
	//loop control variable
	int index;

	for (index = 1; index < numberToCalculate || index < maxSize; index++)
	{
		//add 45 to start value
		startValue = startValue + 45;

		//is the array position divisible evenly by 3 multiply start value by index
		if (index % 3 == 0)
		{
			calculatedValue = startValue * index;
		}
		//otherwise it is the startValue divided by index
		else
		{
			calculatedValue = startValue / index;
		}

		//store the calculated value in the array at index and increment the array size
		calculatedArray[index] = calculatedValue;
		calculatedArraySize++;
	}
}

//-------------------------------------------------------------------
// ReadFileArrayData - take inputFile and array storing values in
// input file in the array, and storing array size
//-------------------------------------------------------------------
void ReadFileArrayData(ifstream& inputFile, int fileArray[], int& fileArraySize, int maxSize)
{
	//variable to store file value
	int fileValue;

	//index variable used to assign value to correct location in array in loop
	int index;

	//initialize index variable to 0
	index = 0;

	while (inputFile >> fileValue)
	{
		//store value in array and increment array size
		fileArray[index] = fileValue;
		fileArraySize++;
	}
}

//-------------------------------------------------------------------
// OutputArray - output values from passed array in formatted rows
//-------------------------------------------------------------------
void OutputArray(int arr[], int arraySize)
{
	//variable for loop control
	int index;

	cout << "output array?!?" << endl;

	for (index = 0; index < arraySize; index++)
	{
		//output value from array
		cout << setw(10) << arr[index];

		//if this is the fifth value, end the line
		if ((index + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
}