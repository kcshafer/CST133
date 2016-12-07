//This program will Create a deck of cards

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

const int SIZE_DECK = 52;

//provided functions
void PrintACard(int rank, int suit);
void PrintTheRank(int rank);
void CreateTheDeck(int rank[], int suit[]);
void ShuffleTheDeck(int rank[], int suit[]);
void Swap(int& first, int& second);

//my functions
void MakeThreeColumns(int rank[], int suit[], int rankColumns[][7], int suitColumns[][7]);
void PrintTheColumns(int rankColumns[][7], int suitColumns[][7]);
void Swap(int rankColumns[][7], int suitColumns[][7], int columnChoice);
void Flatten(int mdArray[][7], int outputArray[]);

int main(void)
{
	//arrays for rank and suit
	int rank[SIZE_DECK];
	int suit[SIZE_DECK];

	//init variables to store the columns
	int rankColumns[3][7];
	int suitColumns[3][7];

	//loop control variable
	int index;

	//variable to store column choice
	int columnChoice;

	//generate true randomness
	srand((unsigned int)time(NULL));

	//create and shuffle the deck 
	CreateTheDeck(rank, suit);
	ShuffleTheDeck(rank, suit);

	//play a card trick


	for(index = 1; index <= 3; index++)
	{ 
		//make the columns
		MakeThreeColumns(rank, suit, rankColumns, suitColumns);

		//output the columns
		PrintTheColumns(rankColumns, suitColumns);

		cout << "Pick a card and tell me which column it's in" << endl;
		cin >> columnChoice;

		Swap(rankColumns, suitColumns, columnChoice);
		
		Flatten(rankColumns, rank);
		Flatten(suitColumns, suit);
	}

	cout << "Your card is <<< " << endl;

	PrintACard(rank[10], suit[10]);

	return 0;
}

//-------------------------------------------
// PrintACard - prints a card with provided
// rank and suit 
//-------------------------------------------
void PrintACard(int rank, int suit)
{
	PrintTheRank(rank);
	cout << static_cast<char>(suit);

}

//------------------------------------------
// PrintTheRank - translate numeric rank to 
// Ace,King,Queen,Jack
//------------------------------------------
void PrintTheRank(int rank)
{
	cout << setw(5);
	switch (rank)
	{
	case 14:
		cout << 'A';
		break;
	case 13:
		cout << 'K';
		break;
	case 12:
		cout << 'Q';
		break;
	case 11:
		cout << 'J';
		break;
	default:
		cout << rank;
	}

}

//------------------------------------------
//CreateTheDeck - creates a deck of cards in
// parallel arrays of rank & suit
//------------------------------------------
void CreateTheDeck(int rank[], int suit[])
{

	int suitIndex;
	int rankIndex;
	int cardIndex;

	suitIndex = 3;
	rankIndex = 2;

	for (cardIndex = 0; cardIndex < SIZE_DECK; cardIndex++)
	{
		rank[cardIndex] = rankIndex;
		suit[cardIndex] = suitIndex;

		rankIndex++;
		if (rankIndex == 15)
		{
			suitIndex++;
			rankIndex = 2;
		}

	}
}

//------------------------------------------
//ShuffleTheDeck - "shuffles" deck using rand
// to shift elements in rank, suit arrays
//------------------------------------------
void ShuffleTheDeck(int rank[], int suit[])
{
	int index;
	int randomNumber;
	int number;

	for (number = 0; number < 3; number++)
	{

		for (index = 0; index < SIZE_DECK; index++)
		{
			randomNumber = rand() % SIZE_DECK;

			Swap(rank[index], rank[randomNumber]);
			Swap(suit[index], suit[randomNumber]);

		}
	}

}

//------------------------------------------
//Swap - utility method to swap elements
//------------------------------------------
void Swap(int& first, int& second)
{
	int temp;

	temp = first;
	first = second;
	second = temp;
}

//------------------------------------------
//PrintThreeColumns - print the three columns
// of seven to use in the trick
//------------------------------------------
void MakeThreeColumns(int rank[], int suit[], int rankColumns[][7], int suitColumns[][7])
{
	//loop control variable
	int index;

	for (index = 0; index < 7; index++)
	{
		//get the three ranks
		rankColumns[0][index] = rank[index * 3];
		rankColumns[1][index] = rank[(index * 3) + 1];
		rankColumns[2][index] = rank[(index * 3) + 2];
		
		//get three suits
		suitColumns[0][index] = suit[index * 3];
		suitColumns[1][index] = suit[(index * 3) + 1];
		suitColumns[2][index] = suit[(index * 3) + 2];
	}
}

//------------------------------------------
// PrintTheColumns - print the three columns 
// to the terminal 
//------------------------------------------
void PrintTheColumns(int rankColumns[][7], int suitColumns[][7])
{
	//loop control variable
	int index;

	for (index = 0; index < 7; index++)
	{
		//print the card by index in each of the three columns
		PrintACard(rankColumns[0][index], suitColumns[0][index]);
		PrintACard(rankColumns[1][index], suitColumns[1][index]);
		PrintACard(rankColumns[2][index], suitColumns[2][index]);
		
		cout << endl;
	}
}

//------------------------------------------
//Swap - overload - swap chosen column to 
// center column in arrays
//------------------------------------------
void Swap(int rankColumns[][7], int suitColumns[][7], int columnChoice)
{
	//temp ints for rank and suit
	int tempRank;
	int tempSuit;

	//loop control variable
	int index;

	for (index = 0; index < 7; index++)
	{
		tempRank = rankColumns[1][index];
		tempSuit = suitColumns[1][index];

		rankColumns[1][index] = rankColumns[columnChoice][index];
		suitColumns[1][index] = suitColumns[columnChoice][index];

		rankColumns[columnChoice][index] = tempRank;
		suitColumns[columnChoice][index] = tempSuit;
	}

}

//------------------------------------------
// Flatten - make two dimensional array back
// into one dimensional
//------------------------------------------
void Flatten(int mdArray[][7], int outputArray[])
{
	//loop control variable
	int index;

	for (index = 0; index < 7; index++)
	{
		outputArray[index * 3] = mdArray[0][index];
		outputArray[index * 3 + 1] = mdArray[1][index];
		outputArray[index * +2] = mdArray[2][index];
	}
}

