//-----------------------------------------------------------------------------
//Exercise 7 Grading Block
//Programmer: KC Shafer
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
//    Includes the required course heading output to the output file
//      centered
//    Includes the college, your name, course & Exercise number
//  Divider
//    One line output divider used to separate and block any output
//    to the output file as necessary
//    
//Comment:
//  
//Points lost -----------------------------------------------------------> 
//
//File Management
//  Files closed at end of main function
//
//  Comment:
//
//Points lost -----------------------------------------------------------> 
//
//Struct Definition
//  string member- id
//  double members - cost, markUpPercent, markUpAmount,
//                   sellingPrice,potentialProfit, inventoryValue
//  int member - quantity
//  array of struct defined in the main, inventoryType
//  Constant declared for the size of the array
//
//Comment:
//  
//Points Lost ----------------------------------------------------------->  
//
//Driver Main
//  Files opened in the main
//  Formatting for floating point set up 
//  Main is primarily calls to the functions
//  Functions called TWICE where needed
//
//  Comment:
//
//Points lost -----------------------------------------------------------> 
//
//
//Function Requirements
//  Functions Names appropriate for tasks
//  Divider function prints any number of characters to any output file
//  Prototypes above main, blocked
//  Calls in main and other functions
//  Function definitions below the main
//  Function Documentation block above each function
//  Parameter passing correct 
//  Single return functions used where appropriate
//  Highly modularized program
//  Functions Re-used where appropriate, no duplicate task functions
//    Calculate total function calculated both total profit and total value
//    Output inventory function outputs both the initial report and the 
//      updated report
//
//Comment:
//
//Points Lost ----------------------------------------------------------->  
//
//Lab 7 specific Tasks accomplished:
//  RoundUp function copied into solution & used appropriately
//    Data read into the array of struct, tag field set
//    Mark up amount & selling price calculated &
//      values set in appropriate members
//    Potential profit & inventory value calculated &
//      values set in appropriate members
//    Report written to inventoryReport with all data
//      aligned in columns in order shown in the sample output
//    Totals of profit & inventory value calculated & output
//      aligned in the appropriate columns with label and leader dots
//    (Each total on a separate line)
//    Report of ids that contain a specific character output, 
//      tested with X & B
//    Report of low stock output, tested with 10 & 1000
//    Update file read ONE line at a time, inventory updated
//      appropriately for all members necessary
//
//  Comment:
//
//Points lost -----------------------------------------------------------> 
//
//Miscellaneous
//  Errors not anticipated by your professor
//
//  Comment:
//
//Points lost -----------------------------------------------------------> 
//
//Possible Points -------------------------------------------------------> 200
//Total Points Lost ----------------------------------------------------->  
//Exercise Grade --------------------------------------------------------> 
//-----------------------------------------------------------------------------
//
//Documentation Block
//Exercise 7
//Program Flow (IPO):
//  Open the logical input file, fin for inventory.txt
//  Open the logical input file, updateFile for update.txt
//  Open the logical output file, fout for inventoryreport.txt
//  Input the part ID, the wholesale cost, the markup percentage and the
//    quantity in stock from the input file inventory.txt
//  Calculate the markup amount and the retail price of each item
//  Calculate the potential profit and the  inventory value for each item
//  Output the initial inventory data to the output file, inventoryReport
//  Calculate the total profit
//  Calculate the total inventory value
//  Output the total profit and the total inventory value to the output file,
//    Inventory Report
//  Output a report where the ID has the letter 'X' to the output file, 
//    Inventory Report
//  Output a report where the ID has the letter 'B' to the output file, 
//    Inventory Report
//  Output a report of items with a quantity less than or equal to 10 to the
//    output file, Inventory Report
//  Output a report of items with a quantity less than or equal to 1000 to the
//    output file, Inventory Report
//  Input an update ID from the Update Data File
//  While the Update File has data
//    For each item in the inventory array that does not match the ID
//      Determine if the ID matches the update ID
//        Assign a new quantity to the items quantity
//        Calculate potential profit for the item
//        Calculate inventory value for the item
//        Assign match to true 
//    Input an update ID from the Update Data File      
//  Close Update File
//  Output the initial inventory data to the output file, inventoryReport
//  Calculate the total profit
//  Calculate the total inventory value
//  Output the total profit and the total inventory value to the output file,
//    Inventory Report
//  Close Inventory File and Inventory Report File
//-----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int DIVIDER_WIDTH = 75;
const int MAX_SIZE = 25;

//Inventory type struct
struct InventoryType {
	string id;
	double wholesaleCost;
	double markupPercent;
	double markupAmount;
	double retailPrice;
	double potentialProfit;
	double inventoryValue;
	int quantity;
};

void OutputDivider(ofstream& outputFile);
ifstream OpenInputFile(string fileName);
ofstream OpenOutputFile(string fileName);
void ProcessInventoryFile(ifstream& inventoryFile, InventoryType inventoryList[]);
InventoryType InitInventoryType(string id, double wholesaleCost, double markupPercent, int quantity);

int main()
{
	//variable to store inventory and update input files
	ifstream inventoryFile;
	ifstream updateFile;

	//inventory type array
	InventoryType inventoryList[MAX_SIZE];

	//open inventory file
	inventoryFile = OpenInputFile("Inventory.txt");

	//open update file
	updateFile = OpenInputFile("Update.txt");

	//process inventory file into inventory list
	ProcessInventoryFile(inventoryFile, inventoryList);

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
// ProcessInventoryFile - take in the inventory file and generate 
// InventoryType instances with data from file & calculated data
//-------------------------------------------------------------------
void  ProcessInventoryFile(ifstream& inventoryFile, InventoryType inventoryList[])
{
	//temporary variables to store values read from inventory file
	string id;
	char wholesaleCostTemp[9];
	char markupPercentageTemp[9];
	char quantityTemp[9];

	//discard variable
	char discard;

	//prime inventory file with peek
	inventoryFile.peek();

	//variable to set array locations
	int index;

	//initialize index to 0
	index = 0;

	while (!inventoryFile.eof() && index == MAX_SIZE)
	{
		//get id from file and ignore the comma
		getline(inventoryFile, id, ',');
		inventoryFile.ignore(1, ',');
		
		//get wholesale cost, markup percent and quantity
		inventoryFile.get(wholesaleCostTemp,9);
		inventoryFile.get(markupPercentageTemp, 9 );
		inventoryFile.get(quantityTemp, 9);

		//discard trailing whitespace
		inventoryFile.get(discard);

		//initialize inventory type and add to array
		inventoryList[index] = InitInventoryType(id, atof(wholesaleCostTemp), atof(markupPercentageTemp), atof(quantityTemp));
	
		//increment index
		index++;
	}
}

//-------------------------------------------------------------------
// InitInventoryType - initialize and return InventoryType struct
// including calculating values 
//-------------------------------------------------------------------
InventoryType InitInventoryType(string id, double wholesaleCost, double markupPercent, int quantity)
{
	//initialize inventory type struct
	InventoryType inventory = InventoryType();
	
	//set values based on parameters
	inventory.id = id;
	inventory.wholesaleCost = wholesaleCost;
	inventory.markupPercent = markupPercent;
	inventory.quantity = quantity;

	//calculate the markup amount
	inventory.markupAmount = inventory.wholesaleCost * inventory.markupPercent;

	//calculate the retail price
	inventory.retailPrice = inventory.wholesaleCost + inventory.markupAmount;
	
	return inventory;
}
