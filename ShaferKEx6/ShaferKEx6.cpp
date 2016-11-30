#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

//-----------------------------------------------------------------------------
//Exercise 6 Grading Block
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
//
//General Exercise Requirements
//  Course Heading
//    Includes the required course heading output to the screen
//      centered
//    Includes the college, your name, course & Exercise number
//  Divider
//    One line output divider used to separate and block any output
//    to the screen
//    
//Comment:
//  
//Points lost -----------------------------------------------------------> 
//
//Modularization
//  Main is mainly calls to functions to perform tasks
//  Functions do not perform multiple tasks
//  Single return functions written where appropriate
//  Comment:
//
//
//Points lost -----------------------------------------------------------> 
//
//File Management
//  Files Opened at the beginning with correct name
//  Files closed at end of main function
//  Comment:
//
//
//
//Points lost ----------------------------------------------------------->  
//  
//
//Suspect Data
//  Data read into the three arrays, string, int & int
//  tag field set for length of the arrays
//  Data read correctly until array is filled or all
//    data in input file is read
//  c-str type variable created for primer & changer of file 
//    loop
//  Comment:
//
//Points lost -----------------------------------------------------------> 
//
//Tallest & Shortest
//  Separate Functions written to determine the tallest & shortest
//  Position returned
//  Comment:
//  
//
//Points lost -----------------------------------------------------------> 
//
//Count of Crooks over 6 feet
//  Function written to count the crooks over 6 feet
//  Count returned
//  Comment:
//
//
//Points lost -----------------------------------------------------------> 
//
//Sorting of parallel arrays
//  Selection Sort used
//  Data sorted by alphabetically by name 
//  Other 2 array data swapped to maintain parallel arrays
//  Efficiently sorted
//  Comment:
//
//
//Points lost -----------------------------------------------------------> 
//
//Output of parallel array positions for tallest & shortest
//  Function written efficiently not passing entire arrays, only
//   passing one position of each array needed
//  Comment:
//
//
//Points lost -----------------------------------------------------------> 
//
//Silko Report
//  Message printed to the screen indicating the name of
//   the output file
//  Output to Silko.txt
//  Heading printed indicating unsorted
//  column heading printed
//  Name, Height & Weight aligned under the columns
//    Height displayed in feet and inches
//  Statistical data printed after list of suspects
//
//  Heading printed indicating sorted
//  column heading printed
//  Name, Height & Weight aligned under the columns
//    Height displayed in feet and inches
//  Statistical data printed after list of suspects
//  Comment:
//
//
//Points lost -----------------------------------------------------------> 
//
//Suspects file
//  Message printed to the screen indicating the name of
//   the output file
//  All crimes processed with a formatted list of criminals
//  Crime printed in formatted specified in the lab specs
//  List of suspects printed in columns formatted correctly
//    Height displayed in feet and inches
//  Number of suspect printed if there were any suspects
//  No suspect message printed if there were no suspects
//  Comment:
//
//
//Miscellaneous style errors
//  Comment:
//
//
//
//Points lost -----------------------------------------------------------> 
//
//Possible Points -------------------------------------------------------> 200
//Points lost ----------------------------------------------------------->  
//Lab Grade ------------------------------------------------------------->  
//-----------------------------------------------------------------------------
//
//Documentation Block
//Exercise 6
//Program Flow (IPO):
// create and initialize variables
// open the input and output files
// initialize c string for each value being read from file
// read values from file by number of characters - priming the file
// convert the c strings to integers
// store the values in the parallel arrays
//  while the files still has values to read
//		read values from file by number of characters
//		convert the c strings to integers
//		store the values in the parallel arrays
// increment the crooks count 
// create variable for largest value and index of largest value
// initialize largest value variable to the first value in the array
// initialize largest index to 0
// for the index is 0 to one less than the crooks count
//		if the value at the index is larger than the largest value
//			the value at index becomes the new largest value
//		increment the index
//  return the index of the largest height
// 
// initialize variables for smallest value and index of smallest value
// set smallest value to arbitrarily high value and index of smallests value to 0
// for the index is 0 to one less than the crooks count
//		if the value at index is less than smallest value
//			the value at index becomes the smallest value
//	return the shortest value index
// 
//  initialize variable to hold six foot crooks and set to 0
//	for the index is 0 to one less than the crooks count
//		retrieve the height from array
//		if height is greater than 72 inches
//			increment the six foot crooks count
//	return six foot crooks count
//
// OutputCrooksDataToSilkoFile - unsorted
// write passed title to silko file
// write column headers to silko file
// for the index is 0 to one less than the crooks count
//		output the formatted name, height converted to feet and inches, and weight
//
//OutputStatistics
//	output the number of crooks to the silko file
//	output the name and height of the tallest crook to the silko file
//	output the name and height of the smallest crook to the silko file
//	output the count of six foot crooks to the silko file
//	
// sort the suspects alphabetically
//
//SelectionSort
//for the index is 0 to one less than the crooks count
//	set the smallest index to the current index
//	for the location is index plus one to the crooks count
//		if the value we find is smaller than the current smallest value
//			set the smallest index
//	use the smallest index to swap the values for each array
//
//ProcessCapersFile
//prime the file by reading in the first line
//write the details to the suspects file
//call FindSuspects for each line in file
//
//FindSuspects
//output the column headers to the suspects files
// initialize suspect count to 0
//store absolute value of suspect height and weight minus height and weight by index
// for the index is 0 to one less than the crooks count
//	if height difference is less than 4 and weight difference is less than 10
//		write formatted suspect name to file
//		increment suspect count
//output count of suspects to suspects file
//
//close all open files
//-----------------------------------------------------------------------------

using namespace std;

void OutputDivider(ofstream& outputFile);
ifstream OpenInputFile(string fileName);
ofstream OpenOutputFile(string fileName);
void ReadCrooksFile(ifstream& crooksFile, string names[], int heights[], int weights[], int& crooksCount);
int GetTallestCrook(string names[], int heights[], int crooksCount);
int GetShortestCrook(string names[], int heights[], int crooksCount);
int CountSixFootCrooks(int heights[], int crooksCount);
void OutputCrooksDataToSilkoFile(ofstream& silkoFile, string title, string names[], int heights[], int weights[], int crooksCount);
string ConvertInchesToFeetString(int inches);
void OutputStatistics(ofstream& silkoFile, string names[], int heights[], int crooksCount, int tallestCrookIndex, int shortestCrookIndex, int sixFootCrooks);
void SelectionSort(string names[], int heights[], int weights[], int crooksCount);
void ProcessCapersFile(ifstream& capersFile, ofstream& suspectsFile, string names[], int heights[], int weights[], int crooksCount);
void FindSuspects(ofstream& suspectFile, int height, int weight, string names[], int heights[], int weights[], int crooksCount);

const int MAX_SIZE = 35;
const int DIVIDER_WIDTH = 75;

int main()
{
	//initialize input and output files
	ifstream crooksFile;
	ifstream capersFile;
	ofstream silkoFile;
	ofstream suspectFile;

	//parallel arrays for names, heights and weights
	string names[MAX_SIZE];
	int heights[MAX_SIZE];
	int weights[MAX_SIZE];

	//parallel arrays for suspect names, heights and weights
	string suspectNames[MAX_SIZE];
	int suspectHeights[MAX_SIZE];
	int suspectWeights[MAX_SIZE];

	//single integer that will store the size of all the arrays aka the crook count
	int crooksCount;

	//int to store index of tallest crook
	int tallestCrookIndex;

	//int to store index of shortest crook
	int shortestCrookIndex;

	//integer to store six foot crooks
	int sixFootCrooks;

	//open the crooks file
	crooksFile = OpenInputFile("crooks.txt");

	//open the output file
	silkoFile = OpenOutputFile("silko.txt");

	//open the capers file
	capersFile = OpenInputFile("capers.txt");

	//open the suspects file
	suspectFile = OpenOutputFile("suspects.txt");

	//read data in from the crooks file
	ReadCrooksFile(crooksFile, names, heights, weights, crooksCount);

	//get the tallest crook
	tallestCrookIndex = GetTallestCrook(names, heights, crooksCount);

	//get the shortest crook
	shortestCrookIndex = GetShortestCrook(names, heights, crooksCount);

	//get the count of six foot crooks
	sixFootCrooks = CountSixFootCrooks(heights, crooksCount);

	//output unsorted data to silko file
	OutputCrooksDataToSilkoFile(silkoFile, "Silko Report - UNSORTED", names, heights, weights, crooksCount);
	
	//output statistics section
	OutputStatistics(silkoFile, names, heights, crooksCount, tallestCrookIndex, shortestCrookIndex, sixFootCrooks);

	//sort the crooks alphabetically
	SelectionSort(names, heights, weights, crooksCount);

	//output sorted data to silko file
	OutputCrooksDataToSilkoFile(silkoFile, "Silko Report - SORTED", names, heights, weights, crooksCount);

	//process the caper file
	ProcessCapersFile(capersFile, suspectFile, names, heights, weights, crooksCount);

	//close all open files
	crooksFile.close();
	silkoFile.close();
	suspectFile.close();
	capersFile.close();

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
// ReadCrooksFile - read value from crooks.txt into parallel arrays
// for names, height and weight
//-------------------------------------------------------------------
void ReadCrooksFile(ifstream& crooksFile, string names[], int heights[], int weights[], int& crooksCount)
{

	//variables to store name height and weight temporarily
	string name;
	string height;
	string weight;

	//temp string used to store the name as its is retrieved from the file hopefully pthis can be done differently
	char tempName[27];
	char tempHeight[3];
	char tempWeight[6];

	//character that will discard the newline character
	char discard;

	//loop variable for setting index of array items
	int index;

	//initialize index to 1 because we are reading first values out of loop
	index = 1;
	
	//get the first 27 characters of file line into tempName
	crooksFile.get(tempName, 27);
	//read the next 3 in which gives the height
	crooksFile.get(tempHeight, 3);
	//read the next 5 in which gives the weight
	crooksFile.get(tempWeight, 5);
	//discard the rest of the line to move to next line
	crooksFile.get(discard);

	//store values in arrays, converting height and weight to integers
	names[0] = tempName;
	heights[0] = atoi(tempHeight);
	weights[0] = atoi(tempWeight);

	//while the file still has unread values
	while (!crooksFile.eof()) {
		//these are the same exact operations used in priming the loop - comments above apply to these
		crooksFile.get(tempName, 27);
		crooksFile.get(tempHeight, 3);
		crooksFile.get(tempWeight, 5);
		crooksFile.get(discard);

		names[index] = tempName;
		heights[index] = atoi(tempHeight);
		weights[index] = atoi(tempWeight);

		//increment the loop control variable
		index++;
	}

	//set crooks count to index
	crooksCount = index + 1;
}

//-------------------------------------------------------------------
// GetTallestCrook - find the largest height value in array
// and return the index of the tallest crook
//-------------------------------------------------------------------
int GetTallestCrook(string names[], int heights[], int crooksCount)
{	
	//loop control integer
	int index;

	//integer to store the index of the largest height
	int largestHeightIndex;

	//init largestIndex to 0
	largestHeightIndex = 0;

	//ineger to store the largest height
	int largestHeight;

	//string to return largest height corresponding name
	string largestName;

	//initialize largest height to 0 so anything is larger than it
	largestHeight = 0;

	//loop through all heights
	for (index = 0; index < crooksCount - 1; index++)
	{
		//if the height at index is greater than the largest height
		if (heights[index] > largestHeight)
		{
			//set that value as largestHeight and the index as largestHeightIndex
			largestHeight = heights[index];
			largestHeightIndex = index;
		}
	}
	
	return largestHeightIndex;
}

//-------------------------------------------------------------------
// GetShortestCrook - find the shortest height value in array
// and return the index of the shortest crook
//-------------------------------------------------------------------
int GetShortestCrook(string names[], int heights[], int crooksCount)
{
	//loop control integer
	int index;

	//integer to store the index of the largest height
	int shortestHeightIndex;

	//ineger to store the largest height
	int shortestHeight;

	//string to return largest height corresponding name
	string shortestName;

	//initialize largest height to 99999 so anything is smaller than it
	shortestHeight = 99999;

	//loop through all heights
	for (index = 0; index < crooksCount - 1; index++)
	{
		//if the height at index is greater than the largest height
		if (heights[index] < shortestHeight)
		{
			//set that value as largestHeight and the index as largestHeightIndex
			shortestHeight = heights[index];
			shortestHeightIndex = index;
		}
	}

	return shortestHeightIndex;
}

//-------------------------------------------------------------------
// CountSixFootCrooks - count the number of crooks at at least six 
// feet tall
//-------------------------------------------------------------------
int CountSixFootCrooks(int heights[], int crooksCount)
{
	//variable to store amount of six foot crooks
	int sixFootCrooks;

	//initialize count of crooks to 0
	sixFootCrooks = 0;

	//variable to temporarily hold the height inside loop
	int height;

	//loop control variable
	int index;

	for (index = 0; index < crooksCount; index++) 
	{
		//get height from array
		height = heights[index];
		
		//check if height is greater than or equal to 72
		if (height >= 72)
		{
			sixFootCrooks++;
		}
	}

	return sixFootCrooks;
}

//-------------------------------------------------------------------
// OutputCrooksToSilkoFile
//-------------------------------------------------------------------
void OutputCrooksDataToSilkoFile(ofstream& silkoFile, string title, string names[], int heights[], int weights[], int crooksCount)
{
	//write title to file 
	silkoFile << title << endl;

	//output empty line
	silkoFile << endl;

	//output row headings
	silkoFile << setfill(' ') << "Crook's Name" << setw(75 / 3) << "Height" << setw(75 / 3) << "Weight" << endl;


	//output divider between title and data
	OutputDivider(silkoFile);

	//loop control variable
	int index;

	for (index = 0; index < crooksCount - 1; index++)
	{
		silkoFile << setfill(' ') << names[index] << setw(15) << ConvertInchesToFeetString(heights[index]) << setw(20) << weights[index] << endl;
	}
}

//-------------------------------------------------------------------
// ConvertInchesToFeetString - convert integer inches to feet and
// inches string
//-------------------------------------------------------------------
string ConvertInchesToFeetString(int inches)
{
	//string to store feet and inches
	string feetWithInches;
	
	//integer to temporarily store the feet
	int tempFeet;

	//int to temporarily store the inches 
	int tempInches;

	//divide by 12 to get the feet, integer division to integer rounds to floor
	tempFeet = inches / 12;

	//modulus by 12 to get the inches
	tempInches = inches % 12;

	//create feet and inches string
	feetWithInches = to_string(tempFeet) + " ft. " + to_string(tempInches) + " in.";
	
	return feetWithInches;
}

//-------------------------------------------------------------------
// OutputStatistics - output statistics section to silko report
//-------------------------------------------------------------------
void OutputStatistics(ofstream& silkoFile, string names[], int heights[], int crooksCount, int tallestCrookIndex, int shortestCrookIndex, int sixFootCrooks)
{
	//output divider above statistics
	OutputDivider(silkoFile);

	//output number of crooks
	silkoFile << "Number of crooks: " << crooksCount << endl;

	//output tallest crook
	silkoFile << "The tallest crook is " << names[tallestCrookIndex] << " at a height of " << ConvertInchesToFeetString(heights[tallestCrookIndex]) << endl;
	
	//output shortest crook
	silkoFile << "The shortest crook is " << names[shortestCrookIndex] << " at a height of " << ConvertInchesToFeetString(heights[shortestCrookIndex]) << endl;

	//output crooks over six feet
	silkoFile << "Count of suspects over 6 feet: " << sixFootCrooks << endl;

	//output divider below statistics
	OutputDivider(silkoFile);
}

//-------------------------------------------------------------------
// SelectionSort - implementation of selection sort 
//-------------------------------------------------------------------
void SelectionSort(string names[], int heights[], int weights[], int crooksCount)
{	
	//loop control variable
	int index;

	//inner loop control variable 
	int location;

	//int to store the location of the smallest value for each inner loop
	int smallestIndex;
	
	//temp variables for swapping values
	string temp;
	int tempHeight;
	int tempWeight;

	//outer loop through each value in the array
	for (index = 0; index < crooksCount - 1; index++)
	{
		
		//set smallest index as index
		smallestIndex = index;

		//inner loop through the unsorted part of the array
		for (location = index + 1; location < crooksCount - 1; location++)
		{
			//if the value we find is smaller than the current smallest value
			if (names[location] < names[smallestIndex])
			{
				//set it to the smallest index
				smallestIndex = location;
			}
		}
			
		//swap the smallest value, moving it into the next position in the sorted part of the array
		temp = names[smallestIndex];
		names[smallestIndex] = names[index];
		names[index] = temp;

		//swap heights
		tempHeight = heights[smallestIndex];
		heights[smallestIndex] = heights[index];
		heights[index] = tempHeight;

		//swap weights
		tempWeight = weights[smallestIndex];
		weights[smallestIndex] = weights[index];
		weights[index] = tempWeight;
	}
}

//-------------------------------------------------------------------
// ProcessCapersFile - read capers from file and match to suspects 
// writing the suspects to suspects.txt
//-------------------------------------------------------------------
void ProcessCapersFile(ifstream& capersFile, ofstream& suspectsFile, string names[], int heights[], int weights[], int crooksCount)
{
	//variables to store crime, suspect height and weight
	string crime;
	int suspectHeight;
	int suspectWeight;

	//temp string used to store the name as its is retrieved from the file hopefully pthis can be done differently
	char tempCrime[27];
	char tempHeight[3];
	char tempWeight[6];

	//character that will discard the newline character
	char discard;

	//loop variable for setting index of array items
	int index;

	//initialize index to 1 because we are reading first values out of loop
	index = 1;

	//get the first 27 characters of file line into tempName
	capersFile.get(tempCrime, 27);
	//read the next 3 in which gives the height
	capersFile.get(tempHeight, 3);
	//read the next 5 in which gives the weight
	capersFile.get(tempWeight, 5);
	//discard the rest of the line to move to next line
	capersFile.get(discard);

	crime = tempCrime;
	suspectHeight = atoi(tempHeight);
	suspectWeight = atoi(tempWeight);

	//write the header of the suspects file
	OutputDivider(suspectsFile);
	suspectsFile << "Suspect Report" << endl;
	OutputDivider(suspectsFile);

	//write the primed data to the suspects file outside the loop 

	//write the crime header
	suspectsFile << "For the crime of: " << crime << endl;
	suspectsFile << "With a recorded height of " << ConvertInchesToFeetString(suspectHeight) << " & weight of " << suspectWeight << endl;
	suspectsFile << "Height Range: " << ConvertInchesToFeetString(suspectHeight - 4) << " to " << ConvertInchesToFeetString(suspectHeight + 4) << endl;
	suspectsFile << "Weight Range: " << suspectWeight - 10 << " to " << suspectWeight + 10 << endl;
	suspectsFile << endl;

	FindSuspects(suspectsFile, suspectHeight, suspectWeight, names, heights, weights, crooksCount);

	//end writing primed data for suspects file 

	//while the file still has unread values
	while (!capersFile.eof()) {
		//get the first 27 characters of file line into tempName
		capersFile.get(tempCrime, 27);
		//read the next 3 in which gives the height
		capersFile.get(tempHeight, 3);
		//read the next 5 in which gives the weight
		capersFile.get(tempWeight, 5);
		//discard the rest of the line to move to next line
		capersFile.get(discard);

		crime = tempCrime;
		suspectHeight = atoi(tempHeight);
		suspectWeight = atoi(tempWeight);


		//write the header of the suspects file
		OutputDivider(suspectsFile);
		suspectsFile << "Suspect Report" << endl;
		OutputDivider(suspectsFile);

		//write the crime header
		suspectsFile << "For the crime of: " << crime << endl;
		suspectsFile << "With a recorded height of " << ConvertInchesToFeetString(suspectHeight) << " & weight of " << suspectWeight << endl;
		suspectsFile << "Height Range: " << ConvertInchesToFeetString(suspectHeight - 4) << " to " << ConvertInchesToFeetString(suspectHeight + 4) << endl;
		suspectsFile << "Weight Range: " << suspectWeight - 10 << " to " << suspectWeight + 10 << endl;
		suspectsFile << endl;

		FindSuspects(suspectsFile, suspectHeight, suspectWeight, names, heights, weights, crooksCount);
	}
}

//-------------------------------------------------------------------
// FindSuspects - find the suspects matching the heights and weights
// and write them to the suspects report
//-------------------------------------------------------------------
void FindSuspects(ofstream& suspectFile, int height, int weight, string names[], int heights[], int weights[], int crooksCount)
{
	//output column headers
	suspectFile << setfill(' ') << "Crook's Name" << setw(75 / 3) << "Height" << setw(75 / 3) << "Weight" << endl;
	OutputDivider(suspectFile);

	//loop control variable
	int index;
	
	//count of suspects
	int suspectCount;

	//init suspectCount to 0
	suspectCount = 0;

	//diff variables for height and weight
	int heightDiff;
	int weightDiff;

	//loop through suspects to find matches for crime
	for (index = 0; index < crooksCount; index++)
	{
		//get absolute value difference of height and weight of crime and height and weight in array
		heightDiff = abs(height - heights[index]);
		weightDiff = abs(weight - weights[index]);

		//check if height and weight within range
		if (heightDiff <= 4 && weightDiff <= 10)
		{
			suspectFile << setfill(' ') << names[index] << setw(15) << ConvertInchesToFeetString(heights[index]) << setw(20) << weights[index] << endl;
			suspectCount++;
		}
	}

	//output line break between list and count
	suspectFile << endl;

	//output count of suspects to suspects report
	suspectFile << "The number of possible suspects is: " << suspectCount << endl;
}

