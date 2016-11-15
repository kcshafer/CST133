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
//  Open input and output files
//  Fill the calculated array
//		Read in the first two values which are the start value and number of values to calculate
//      calculate the values to fill array
//		initialize variable to store value being entered in array
//		for index 0 to the number of values to calculate or the maximum size of the array
//		add 45 to the value
//		if value is divisible by 3
//			multiply value by index
//		else
//			divide value by index
//		store value in array
//	Read files in from file to store in array
//	while file is not empty and the max size has not been reached
//		read value into array
//		increment file size
//	Output formatted arrays to output file
//	Calculate average for each array
//		initialize value for total
//		for index = 0 while index is less than arraySize
//			add array value by index to total
//		create double type variable average to store average calculation
//		cast total and count to double and divide them into average
//		return average
//	Output formatted average to output file
//	Calculate occurences of digit in array integers
//		initialize temporary integer and string variables to store values pulled from array
//		for index is 0 to the array size by 1
//			extract the array value at index into temporary integer variable
//			convert temporary integer into string using to_string and assigning to temporary string variable
//			if the search character is found in the string using string.find, returns the position not the end of the string
//				increment the occurence count
//		return the occurence count
//	Output the formatted occurence count to the output file
//	Calculate the highest value and number of occurences in each array
//		pass in array, size and reference variables for highest value and count for multi-return
//		initialize highest count to 0
//		for the index is 0 while less than array size by 1
//			if the value at array index is greater than the highestValue stored
//				value at array index becomes highestValue
//				highest count becomes 1
//			else if value at array index is equal to highestValue
//				increment highestCount by 1
//	Output formatted highest value and highest count for each array
//	Calculate the number of values in the two arrays that are equal values at the same array position
//		pass in both arrays and array sizes to function
//		initialize match count to 0
//		determine the smaller of the two array sizes which will be the maximum size used to control the loop
//		for the index is 0 while the index is less than the maximum array size by 1
//			if the value in array one is equal to the value in array two at the current index
//				increment match count by 1
//		return match count to main
//	Output formatted match count to output file
//	Increase the value of each item of each array by a specified value
//		pass in array, array size and value to increase by
//		for index is 0 while less than array size by 1
//			replace value of array at index with value at index plus specified value
//	Output formatted updated array to output file
//-----------------------------------------------------------------------------

using namespace std;

//constants
const int MAX_SIZE = 20;

void OutputDivider(ofstream& outputFile);
ifstream OpenInputFile(string fileName);
ofstream OpenOutputFile(string fileName);
void FillArray(ifstream& inputFile, int calculatedArray[], int& calculatedArraySize, int maxSize);
void ReadFileArrayData(ifstream& inputFile, int fileArray[], int& fileArraySize, int maxSize);
void OutputArray(ofstream& outputFile, int arr[], int arraySize, string arrayName);
double CalculateAverage(int arr[], int arraySize);
void OutputAverage(ofstream& outputFile, string type, double average);
int CalculateOccurences(int arr[], int arraySize, string searchValue);
void OutputOccurences(ofstream& outputFile, string type, int occurenceCount);
void CalculateHighest(int arr[], int arraySize, int& highestValue, int& highestCount);
void OutputHighestData(ofstream& outputFile, string type, int highestValue, int highestCount);
int MatchByPosition(int arrayOne[], int arrayTwo[], int arrayOneSize, int arrayTwoSize);
void OutputMatchCount(ofstream& outputFile, int matchCount);
void IncreaseArray(int arr[], int arraySize, int increaseValue);

const int DIVIDER_WIDTH = 75;

int main()
{
	
	//array variables
	int calculatedArray[MAX_SIZE];
	int fileArray[MAX_SIZE];

	//variables to hold array size
	int calculatedArraySize;
	int fileArraySize;

	//variables to hold averages for both arrays
	double calculatedArrayAverage;
	double fileArrayAverage;

	//variables to hold number of occurences
	int calculatedOccurenceCount;
	int fileOccurenceCount;

	//variables for highest value from both arrays
	int calculatedArrayHighestValue;
	int fileArrayHighestValue;

	//variables for highest value count from both arrays
	int calculatedArrayHighestCount;
	int fileArrayHighestCount;

	//variable to store the position match count 
	int positionMatchCount;

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
	OutputArray(outputFile, calculatedArray, calculatedArraySize, "Calculated Array");
	OutputArray(outputFile, fileArray, fileArraySize, "File Array");

	//calculate the average for both arrays
	calculatedArrayAverage = CalculateAverage(calculatedArray, calculatedArraySize);
	fileArrayAverage = CalculateAverage(fileArray, fileArraySize);

	OutputDivider(outputFile);

	//output the averages to the file
	OutputAverage(outputFile, "Calculated Array Average", calculatedArrayAverage);
	OutputAverage(outputFile, "File Array Average", fileArrayAverage);

	//calculate the occurences of a character in arrays
	calculatedOccurenceCount = CalculateOccurences(calculatedArray, calculatedArraySize, "7");
	fileOccurenceCount = CalculateOccurences(fileArray, fileArraySize, "9");

	OutputDivider(outputFile);

	//output the occurence counts to the output file
	OutputOccurences(outputFile, "Calculated Array 7 Occurence Count", calculatedOccurenceCount);
	OutputOccurences(outputFile, "File Array 9 Occurence Count", fileOccurenceCount);

	//calculate the highest value and count from each array
	CalculateHighest(calculatedArray, calculatedArraySize, calculatedArrayHighestValue, calculatedArrayHighestCount);
	CalculateHighest(fileArray, fileArraySize, fileArrayHighestValue, fileArrayHighestCount);

	OutputDivider(outputFile);

	//output highest value and count from each array
	OutputHighestData(outputFile, "Calculated Array", calculatedArrayHighestValue, calculatedArrayHighestCount);
	OutputHighestData(outputFile, "File Array", fileArrayHighestValue, fileArrayHighestCount);

	//calculate the number of position matches in the two arrays
	positionMatchCount = MatchByPosition(calculatedArray, fileArray, calculatedArraySize, fileArraySize);

	OutputDivider(outputFile);

	//output the position matches to output file
	OutputMatchCount(outputFile, positionMatchCount);

	//bonus increase array - this was behaving strangly, it gave me a weird error message I'd never seen
	//without any stack trace or informative message that I knew how to get too, but still worked to increase
	//the array. Comment it out and it works fine. I decided to include it since it does actually work.
	//I'm curious how to debug the error message at the end and why it was working despite that.
	//(calculatedArray, calculatedArraySize, 4);
	//IncreaseArray(fileArray, fileArraySize, 9);

	//OutputArray(outputFile, calculatedArray, calculatedArraySize, "Calculated Array Increased");
	//OutputArray(outputFile, fileArray, fileArraySize, "File Array Increased");

	//close the input and output files
	inputFile.close();
	outputFile.close();

	return 0;
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
	calculatedArraySize = 1;

	//get the values from the input file
	inputFile >> startValue >> numberToCalculate;

	//store start value in first array position and increment array size
	calculatedArray[0] = startValue;
	calculatedArraySize++;
	
	//loop control variable
	int index;

	for (index = 1; index < numberToCalculate && index < maxSize; index++)
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

	//variable to store array index starting at 0
	int index;

	//initialize index to 0
	index = 0;

	//initialize fileArraySize
	fileArraySize = 1;

	//while there is still values to read from the file or the array max size has been reached
	while (inputFile >> fileValue && index < maxSize)
	{
		//store value in array and increment array size
		fileArray[index] = fileValue;
		index++;
		fileArraySize++;
	}
}

//-------------------------------------------------------------------
// OutputArray - output values from passed array in formatted rows
//-------------------------------------------------------------------
void OutputArray(ofstream& outputFile, int arr[], int arraySize, string arrayName)
{	
	//variable for loop control
	int index;

	OutputDivider(outputFile);

	//output the array name in between the dividers as header
	outputFile << arrayName << endl;

	OutputDivider(outputFile);

	for (index = 0; index < arraySize - 1; index++)
	{
		//output value from array
		outputFile << setw(10) << arr[index];

		//if this is the fifth value, end the line
		if ((index + 1) % 5 == 0)
		{
			outputFile << endl;
		}
	}

	outputFile << endl;
}

//-------------------------------------------------------------------
//CalculateAverage - calculate average of values in array
//-------------------------------------------------------------------
double CalculateAverage(int arr[], int arraySize)
{
	//variable to store average
	double average;

	//variable for totaling the array values
	int total;

	//loop control variable
	int index;
	
	//initialize total
	total = 0;

	//loop through array values
	for (index = 0; index < arraySize - 1; index++)
	{
		//add the value at index to total
		total += arr[index];
	}

	average = (double)total / (double)arraySize;

	return average;
}

//-------------------------------------------------------------------
//OutputAverage - output the averages to the file 
//-------------------------------------------------------------------
void OutputAverage(ofstream& outputFile, string type,  double average)
{
	outputFile << fixed << setprecision(2) << type << ": " << average << endl;
}

//-------------------------------------------------------------------
//CalculateOccurences - calculate the occurences of a digit in an integer
//-------------------------------------------------------------------
int CalculateOccurences(int arr[], int arraySize, string searchValue)
{
	//variable to store occurence count
	int occurenceCount;
	occurenceCount = 0;

	//loop control variable
	int index;

	//variable to store the int from the array before converting to string
	int temp;

	//variable to store the integer converted to string for searching
	string tempStr;

	for (index = 0; index < arraySize; index++)
	{
		//get int out of array and convert to string
		temp = arr[index];
		tempStr = to_string(temp);

		//this seemed like an easier way to check if a character exists in string and was more efficient 
		//check if passed value exists in string - returns the index of the match or no possible values which can be compared to npos constant
		if (tempStr.find(searchValue) != string::npos)
		{
			occurenceCount++;
		}
	}

	return occurenceCount;
}

//-------------------------------------------------------------------
//OutputOccurences - output the occurence count to the output file
//-------------------------------------------------------------------
void OutputOccurences(ofstream& outputFile, string type, int occurenceCount)
{
	outputFile << type << ": " << occurenceCount << endl;
}

//-------------------------------------------------------------------
//Calculate Highest - find the highest integer in the array
//-------------------------------------------------------------------
void CalculateHighest(int arr[], int arraySize, int& highestValue, int& highestCount)
{
	//loop control variable
	int index;

	//variable to store temporary array value
	int tempValue;

	//set highest count to 0
	highestCount = 0;

	for (index = 0; index < arraySize; index++)
	{
		//extract int into temp variable from array
		tempValue = arr[index];

		//check if current value is larger than highestValue and set to highest value if it is
		if (tempValue > highestValue)
		{
			highestValue = tempValue;
			highestCount = 1;
		}
		//highest value equals the current array value increment the count
		else if (tempValue == highestValue)
		{
			highestCount++;
		}
	}
}

//-------------------------------------------------------------------
//OutputHighestData - output highest value and count to file
//-------------------------------------------------------------------
void OutputHighestData(ofstream& outputFile, string type, int highestValue, int highestCount)
{
	outputFile << type << " Highest Value: " << highestValue << endl;
	outputFile << type << " Highest Value Count: " << highestCount << endl;
}

//-------------------------------------------------------------------
//MatchByPosition - count the number of times the same value is stored
// in the same position in the two arrays
//-------------------------------------------------------------------
int MatchByPosition(int arrayOne[], int arrayTwo[], int arrayOneSize, int arrayTwoSize)
{
	//loop control variable
	int index;

	//integer to store the max index
	int maxIndex;
	
	//position match count
	int positionMatchCount;

	//initalize position match count to 0
	positionMatchCount = 0;

	//assign the smaller of the array sizes to the max index
	maxIndex = arrayOneSize < arrayTwoSize ? arrayOneSize : arrayTwoSize;

	for (index = 0; index < maxIndex; index++)
	{
		if (arrayOne[index] == arrayTwo[index])
		{
			positionMatchCount++;
		}
	}

	return positionMatchCount;
}

//-------------------------------------------------------------------
//OutputMatchCount - output the match count to the file
//-------------------------------------------------------------------
void OutputMatchCount(ofstream& outputFile, int matchCount)
{
	outputFile << "Match Count: " << matchCount << endl;
}

//-------------------------------------------------------------------
//IncreaseArray - increase each value in array by passed in value
//-------------------------------------------------------------------
void IncreaseArray(int arr[], int arraySize, int increaseValue)
{
	//loop control variable
	int index;

	for (index = 0; index < arraySize; index++)
	{
		arr[index] = arr[index] + increaseValue;
	}
}
