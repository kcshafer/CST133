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

	//initialize calculated value - will be used in the inner while loop to hold the calculations done with the sequenceValue
	int calculatedValue;

	//initialize outer and inner loop counters
	int outerCounter;
	int innerCounter;

	//initialize the outerCounter to 0
	outerCounter = 1;

	//prime the loop
	inputFile >> sequenceValue;

	//output the first value to the output filec	
	outputFile << outerCounter << ".    Start Value is: " << sequenceValue << endl;
	outputFile << setfill('*') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

	while (!inputFile.eof())
	{
		//set sequenceValue to calculated value - used in the inner loop doing calculations
		calculatedValue = sequenceValue;
		
		//initialize innerCounter to 0
		innerCounter = 0;

		//while (calculatedValue != 1)
		//{

		//}

		//increment the outerCounter
		outerCounter++;
		//retrieve the next sequenceValue
		inputFile >> sequenceValue;

		//write start value to outputFile
		outputFile << outerCounter << ".    Start Value is: " << sequenceValue << endl;
		outputFile << setfill('*') << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;

		cout << sequenceValue << endl;
	}

	//close the input and output files
	inputFile.close();
	outputFile.close();
}