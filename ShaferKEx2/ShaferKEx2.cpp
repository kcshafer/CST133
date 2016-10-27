//----------------------------------------------------------------
//Programmer's Name: KC Shafer
//Program: Exercise 2
//Documentation Block
//Exercise 2
//Program Flow:
//Open the logical input file for Sequence.txt
//Open the logical output file for Ex2Output.txt
//Output the course heading to the output file
//Input the first value from the input file
//While there is data in the input file:
//	Output the first value read to the output file
//	Initialize the largest value and the largest position
//	While the value is not 1:
//		Calculate a new value based on whether the value is odd or even
//		Increment the line counter
//		Determine if 10 values have been printed to the output file and if so, move	
//		to the next line in the output file
//		Determine if the new calculated value is larger than the current largest. If it is, largest
//		is assigned to this value along with setting the position to this value's position in the
//		calculation
//	Output the largest value and the position of the largest value to the output file
//	Input the next value from the input file
//Close the logical input file for Sequence.txt
//Close the logical output file for Ex2Output.txt
//Grade:
//Comments:


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int DIVIDER_WIDTH = 75;

void writeSequenceCalculationBlock(int sequenceValue, int filePosition, ofstream &outputFile);

int main()
{	
	//initialize input file
	ifstream inputFile;
	inputFile.open("Txt\ Files/Sequence.txt");

	//initialize output file
	ofstream outputFile;
	outputFile.open("Txt\ Files/Ex2Output.txt");

	//initialize sequence number
	int sequenceValue;

	//initialize outer counter
	int outerCounter;

	//initialize the outerCounter to 0
	outerCounter = 1;

	//prime the loop
	inputFile >> sequenceValue;

	writeSequenceCalculationBlock(sequenceValue, outerCounter, outputFile);

	//outer loop through the numbers in the inoutFile
	while (!inputFile.eof())
	{
		inputFile >> sequenceValue;
		outerCounter++;
		writeSequenceCalculationBlock(sequenceValue, outerCounter, outputFile);
	}

	//close the input and output files
	inputFile.close();
	outputFile.close();
}

void writeSequenceCalculationBlock(int sequenceValue, int filePosition, ofstream &outputFile)
{
	//function variable to hold the calculations value for each iteration of the loop
	int calculatedValue;

	//variables to hold the largest value and position in the calculations
	int largestPosition;
	int largestValue;

	//variable to store the count of this loop which is the inner loop
	int innerCounter;

	//write start value to outputFile
	outputFile << filePosition << ".    Start Value is: " << sequenceValue << endl;
	outputFile << setfill('*') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
	//set sequenceValue to calculated value - used in the inner loop doing calculations
	calculatedValue = sequenceValue;

	//set largestValue to sequenceValue and largestPosition to 0
	largestValue = sequenceValue;
	largestPosition = 1;

	//initialize innerCounter to 1, accounting for the initial sequence value we are writing to the output file
	innerCounter = 1;

	//write the initial sequence value to the file
	outputFile << setw(10) << calculatedValue;
	cout << "Calculated Value" << calculatedValue << endl;
	//inner loop while the calculatedValue is not 1
	while (calculatedValue != 1)
	{
		//increment the inner counter
		innerCounter++;

		//if the calculatedValue is even divide by 2
		if (calculatedValue % 2 == 0)
		{
			calculatedValue = calculatedValue / 2;
		}
		//if the calculated value is odd multiply by 3 and add 1
		else if (calculatedValue % 2 == 1)
		{
			calculatedValue = calculatedValue * 3 + 1;
		}

		//compare calculatedValue to largestValue to see if it is the new largestValue
		if (calculatedValue > largestValue) {
			largestValue = calculatedValue;
			largestPosition = innerCounter;
		}

		//output the value to file and set the width between the numbers as 10
		outputFile << setw(10) << calculatedValue;

		//if the counter is at the tenth item or calculatedValue is 1 meaning it is the last number, so we don't leave a line unended
		if (innerCounter % 10 == 0 || calculatedValue == 1)
		{
			//end the line
			outputFile << endl;
		}
	}

	//output a newline between the calculated values and the largest read out
	outputFile << endl;

	//write the largest value & position and the bottom divider line
	outputFile << "The largest value in the sequence is:" << setw(20) << largestValue << endl;
	outputFile << "The position in the sequence of the largest value is:" << setw(4) << largestPosition << endl;
	outputFile << setfill('*') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
}