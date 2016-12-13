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

const int DIVIDER_WIDTH = 120;
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
void ProcessInventoryFile(ifstream& inventoryFile, InventoryType inventoryList[], int& inventoryCount);
void ProcessUpdateFile(ifstream& updateFile, InventoryType inventoryList[], int inventoryCount);
InventoryType InitInventoryType(string id, double wholesaleCost, double markupPercent, int quantity);
void OutputInventoryReport(ofstream& inventoryReport, string title, InventoryType inventoryList[], int inventoryCount);
double CalculateTotals(InventoryType inventoryList[], int inventoryCount, bool profitFlag);
void FindItemsByCharInId(InventoryType inventoryList[], int inventoryCount, char searchChar, InventoryType results[], int& resultsCount);
int FindItemById(InventoryType inventoryList[], int inventoryCount, string id);
void FindItemsByQuantity(InventoryType inventoryList[], int inventoryCount, int quantityLimit, InventoryType results[], int& resultsCount);
void OutputSearchReport(ofstream& inventoryReport,InventoryType results[], int resultsCount, string title);
double RoundUp(double amount);

int main()
{

	//variable to store inventory and update input files
	ifstream inventoryFile;
	ifstream updateFile;

	//variables to store output files
	ofstream inventoryReport;

	//inventory type array
	InventoryType inventoryList[MAX_SIZE];

	//array to store results of inventory x and b search
	InventoryType xResults[MAX_SIZE];
	InventoryType bResults[MAX_SIZE];

	//arrays to store results from greater than 10 and 1000 quantity search
	InventoryType quantityTenResults[MAX_SIZE];
	InventoryType quantityOneThousandResults[MAX_SIZE];

	//variable to store the length of the inventory list
	int inventoryCount;

	//variable to store the lengths of results arrays
	int xResultsCount;
	int bResultsCount;
	int quantityTenResultsCount;
	int quantityThousandResultsCount;

	//open inventory file
	inventoryFile = OpenInputFile("Inventory.txt");

	//open update file
	updateFile = OpenInputFile("Update.txt");
	
	//open inventory report file
	inventoryReport = OpenOutputFile("InventoryReport.txt");

	//set inventory report numeric precision
	inventoryReport << fixed << setprecision(2);

	//process inventory file into inventory list
	ProcessInventoryFile(inventoryFile, inventoryList, inventoryCount);

	//output the initial inventory to the report
	OutputInventoryReport(inventoryReport, "The Initial Inventory", inventoryList, inventoryCount);

	//find the inventory items with x in the id
	FindItemsByCharInId(inventoryList, inventoryCount, 'X', xResults, xResultsCount);

	//find the inventory items with b in the id
	FindItemsByCharInId(inventoryList, inventoryCount, 'B', bResults, bResultsCount);
	
	//find items with quantity greater than 10
	FindItemsByQuantity(inventoryList, inventoryCount, 10, quantityTenResults, quantityTenResultsCount);

	//find items with quantity greater than 1000
	FindItemsByQuantity(inventoryList, inventoryCount, 1000, quantityOneThousandResults, quantityThousandResultsCount);

	//output search for 'x' in id to inventory report
	OutputSearchReport(inventoryReport, xResults, xResultsCount, "X Item's List");

	//output search for 'b' in id to inventory report
	OutputSearchReport(inventoryReport, bResults, bResultsCount, "B Item's List");

	//output quantity search results to inventory report
	OutputSearchReport(inventoryReport, quantityTenResults, quantityTenResultsCount, "Low Stock Items - Less than or equal to 10");
	OutputSearchReport(inventoryReport, quantityOneThousandResults, quantityThousandResultsCount, "Low Stock Items - Less than or equal to 1000");
	
	//process update file to update inventory quantity
	ProcessUpdateFile(updateFile, inventoryList, inventoryCount);

	//output updated inventory report
	OutputInventoryReport(inventoryReport, "The Updated Inventory", inventoryList, inventoryCount);

	//close all the files
	inventoryFile.close();
	updateFile.close();
	inventoryReport.close();

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
void ProcessInventoryFile(ifstream& inventoryFile, InventoryType inventoryList[], int& inventoryCount)
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

	//initialize inventory count to 0
	inventoryCount = 0;

	while (!inventoryFile.eof() && inventoryCount != MAX_SIZE)
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
		inventoryList[inventoryCount] = InitInventoryType(id, atof(wholesaleCostTemp), atof(markupPercentageTemp), atof(quantityTemp));
	
		//increment index
		inventoryCount++;
	}
}

//-------------------------------------------------------------------
//ProcessUpdateFile - read in updates from file, find the inv. type
// by id and update the quantity
//-------------------------------------------------------------------
void ProcessUpdateFile(ifstream& updateFile, InventoryType inventoryList[], int inventoryCount)
{

	//temporary variables to store values read from inventory file
	string id;
	char quantityTemp[9];

	//variable to store int quantity
	int quantity;

	//index of found inventory item by id
	int matchIndex;

	//discard variable
	char discard;
	
	//variable to store found inventory type 
	InventoryType inventoryType;

	//prime inventory file with peek
	updateFile.peek();

	while (!updateFile.eof())
	{
		//get id from file and ignore the comma
		getline(updateFile, id, ',');
		updateFile.ignore(1, ',');

		//get the quantity and discard trailing characters
		updateFile.get(quantityTemp, 9);
		updateFile.get(discard);

		//find the inventory type by id
		matchIndex = FindItemById(inventoryList, inventoryCount, id);
	
		//get inventory instance by match index
		inventoryType = inventoryList[matchIndex];

		//convert quantity temp to quantity int
		quantity = atof(quantityTemp);
		
		//update the quantity and put back in list
		inventoryType.quantity += quantity;

		//update the potential profit
		inventoryType.potentialProfit = inventoryType.markupAmount * inventoryType.quantity;

		//update inventory value
		inventoryType.inventoryValue = inventoryType.wholesaleCost * inventoryType.quantity;

		inventoryList[matchIndex] = inventoryType;

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
	inventory.markupAmount = RoundUp(inventory.wholesaleCost * inventory.markupPercent);

	//calculate the retail price
	inventory.retailPrice = inventory.wholesaleCost + inventory.markupAmount;
	
	//calculate the potential profit
	inventory.potentialProfit = inventory.markupAmount * inventory.quantity;

	//calculate inventory value
	inventory.inventoryValue = inventory.wholesaleCost * inventory.quantity;

	return inventory;
}

//-------------------------------------------------------------------
//OutputInventoryReport - output formatted inventory data to 
// InventoryReport.txt
//-------------------------------------------------------------------
void OutputInventoryReport(ofstream& inventoryReport, string title, InventoryType inventoryList[], int inventoryCount)
{
	//loop control variable
	int index = 0;

	//variables for total value and profit
	double totalValue;
	double totalProfit;

	OutputDivider(inventoryReport);
	
	//output the centered title
	inventoryReport << setfill(' ') << setw((120 + title.length()) / 2)<< title << endl;

	OutputDivider(inventoryReport);

	//output the headers 
	//TODO: pass this into a method that can handle the formating maybe?
	inventoryReport << "ID";
	inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 7) << " Markup %";
	inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << "Cost";
	inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 7) << "Markup Amount";
	inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << "Price";
	inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << "Profit";
	inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << "Value";
	inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << "Quantity" << endl;

	OutputDivider(inventoryReport);
	
	//loop through each inventory item
	for (index = 0; index < inventoryCount; index++)
	{
		//get inventory item instance by index
		InventoryType item = inventoryList[index];

		//output each item formatted to inventory report
		inventoryReport << item.id;
		inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << item.markupPercent;
		inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << item.wholesaleCost;
		inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << item.markupAmount;
		inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << item.retailPrice;
		inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << item.potentialProfit;
		inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << item.inventoryValue;
		inventoryReport << setfill(' ') << setw(DIVIDER_WIDTH / 8) << item.quantity << endl;
	}

	OutputDivider(inventoryReport);

	totalValue = CalculateTotals(inventoryList, inventoryCount, false);
	totalProfit = CalculateTotals(inventoryList, inventoryCount, true);

	//output the totals
	inventoryReport << "Total Profit" << setfill('.') << setw(60) << totalProfit << endl;
	inventoryReport << "Total Value" << setfill('.') << setw(61) << totalValue << endl;
}

//-------------------------------------------------------------------
//CalculateTotals - aggregate totals of inventory type properties
//based on passed boolean
//-------------------------------------------------------------------
double CalculateTotals(InventoryType inventoryList[], int inventorySize, bool profitFlag)
{
	//variable to hold the total calculated
	double total;

	//initialize total to 0
	total = 0;

	//loop control variable
	int index;

	//variable to temporarily store inventory type
	InventoryType inventoryType;

	for (index = 0; index < inventorySize; index++)
	{
		//get inventory type by index
		inventoryType = inventoryList[index];

		//if the profit flag is set to true we are totaling profit, otherwise total inventoryValue
		if (profitFlag)
		{
			total += inventoryType.potentialProfit;
		}
		else {
			total += inventoryType.inventoryValue;
		}
	}

	return total;
}

//-------------------------------------------------------------------
// FindItemsByCharInId - find inventory items by passed character
// in id and return them in new referenced array
//-------------------------------------------------------------------
void FindItemsByCharInId(InventoryType inventoryList[], int inventoryCount, char searchChar, InventoryType results[], int& resultsCount)
{
	//loop control variable
	int index;

	//initialize result count to 0
	resultsCount = 0;

	//variable to retrieve inventory item
	InventoryType inventoryType;

	//loop through inventory items
	for (index = 0; index < inventoryCount; index++)
	{
		//retrieve inventory item
		inventoryType = inventoryList[index];

		//check if id contains character
		if (inventoryType.id.find(searchChar) != string::npos)
		{
			results[resultsCount] = inventoryType;
			resultsCount++;
		}
	}

}

//-------------------------------------------------------------------
//FindItemsByQuantity - find items with less than quantity and return 
// them as results reference parameter
//-------------------------------------------------------------------
void FindItemsByQuantity(InventoryType inventoryList[], int inventoryCount, int quantityLimit, InventoryType results[], int& resultsCount)
{
	//loop control variable
	int index;

	//initialize results count to 0
	resultsCount = 0;

	//temporary inventory type variable
	InventoryType inventoryType;

	for (index = 0; index < inventoryCount; index++)
	{
		//get inventory type by index
		inventoryType = inventoryList[index];
	
		//check if inventory type quantity is greater than quantity limit
		if (inventoryType.quantity <= quantityLimit)
		{
			results[resultsCount] = inventoryType;
			resultsCount++;
		}
	}
}

//-------------------------------------------------------------------
//FindItemById - find item in inventory array by id, and return index
// of match
//-------------------------------------------------------------------
int FindItemById(InventoryType inventoryList[], int inventoryCount, string id)
{
	//loop control variable
	int index;

	//temporary inventory type
	InventoryType inventoryType;

	//boolean variable to  mark true if id found
	bool isFound;

	//set isFound to false
	isFound = false;
	
	//loop through inventory types
	for (index = 0; index < inventoryCount && !isFound; index++)
	{
		//get inventory type by index
		inventoryType = inventoryList[index];

		//check if the id matches the current inventory type
		if (inventoryType.id == id)
		{
			//set is found to true to exit the loop
			isFound = true;
		}
	}

	//return the index of the matching inventory type
	return index - 1;
}

//-------------------------------------------------------------------
//OutputSearchReports - output the results of a search to inventory
// report file
//-------------------------------------------------------------------
void OutputSearchReport(ofstream& inventoryReport, InventoryType results[], int resultsCount, string title)
{
	//loop control variable 
	int index;

	//variable to store temporary inventory type
	InventoryType inventoryType;

	OutputDivider(inventoryReport);

	//output title of search report
	inventoryReport << setfill(' ') << setw(30) <<  title << endl;

	//output headers
	inventoryReport << "ID";
	inventoryReport << setfill(' ') << setw(20) << "Quantity" << endl;

	OutputDivider(inventoryReport);

	for (index = 0; index < resultsCount; index++)
	{
		//retrieve inventory type by index
		inventoryType = results[index];

		//output id and quantity
		inventoryReport << inventoryType.id;
		inventoryReport << setfill(' ') << setw(15) << inventoryType.quantity << endl;
	}
}

//-------------------------------------------------------------------
//RoundUp - function provided to accurately round the amount up
//-------------------------------------------------------------------
double RoundUp(double amount)
{
	int intAmount;
	int tempInt;
	int testDigit;

	//Calculate the int value of the amount
	intAmount = (int)(amount * 1000);

	//Calculate the int value of 3 places
	tempInt = (int)(amount * 100);

	//Calculate the digit to test
	testDigit = intAmount - tempInt * 10;

	//if this value is 5 or greater, round up the number
	if (testDigit >= 5)
	{
		amount = amount + 0.005;
	}

	//return the amount
	return amount;
}