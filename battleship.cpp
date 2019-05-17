#include <iostream>		// Terry Alexander
#include <iomanip>		// 3/14/19
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
#pragma comment(lib, "winmm.lib")

int convertCoordinateToInt(string sInput);
void sorLowToHi(int arr[], int size);
bool addToUsedArr(int iAdd, int arr[], int size); // return false if iAdd is already in arr
bool isToUsedArrFull(int arr[], int size);
bool isNumInArr(int arr[], int size, int iNum);
int main()
{
	bool bCarrier = true, bDestroyer = true, bCruiser = true;
	string sGrid, sCoordinates, sInstructionsGrid, sStatus=""; //users input;
	int iMove = 0, iGameOver = 0, iCounter, iCoordinates, iNumOfTurns=0;
	const int iArrLength = 36;
	const int iShipsArrLength = 9;
	int aiShips[iShipsArrLength] = {0, 1, 2, 3, 5, 11, 17, 18, 19}; //location of ships
	int aiGridLocations[iArrLength]; //posible locations on grid
	int aiUsedCoordinates[iArrLength]; //keep track of which coordinates have been guessed
	int iSeed = time(NULL), iRandNum;//for random number
	int max_rand = 35; // Choose your maximum
	int min_rand = 0; // Choose your minimum
	char cPlaceholder = ' ';   //Placeholder variable for cin.get()
	string sPlaceholder; //Placeholder variable for clearing cin
	int iInputCounter = 0;	//Loop counters

	iSeed = time(NULL);
	srand(iSeed);
	iRandNum = rand() % (max_rand + 1 - min_rand) + min_rand;// create random number

//	sInstructionsGrid = "+---+---+---+---+---+---+\n| 1 | 2 | 3 | 4 | 5 | 6 |\n+---+---+---+---+---+---+\n| 7 | 8 | 9 | 4 | 5 | 6 |\n+---+---+---+---+---+---+\n| 7 | 8 | 9 | 7 | 8 | 9 |\n+---+---+---+---+---+---+\n";
	sInstructionsGrid = "****Terry's Battleship****\nInstructions: Enter gird coordinate to fire, example: a4\n";
	// sGrid with 'o' to fill aiGridLocations array
	sGrid = " +-1-+-2-+-3-+-4-+-5-+-6-+\nA| o | o | o | o | o | o |\n+---+---+---+---+---+---+\nB| o | o | o | o | o | o |\n+---+---+---+---+---+---+\nC| o | o | o | o | o | o |\n+---+---+---+---+---+---+\nD| o | o | o | o | o | o |\n+---+---+---+---+---+---+\nE| o | o | o | o | o | o |\n+---+---+---+---+---+---+\nF| o | o | o | o | o | o |\n+---+---+---+---+---+---+\n";
	iCounter = 0;//counter to fill aiGridLocations
	for (int i = 0; i < sGrid.length(); i++) //used to find locations in sGrid to place O's and X's
	{
		if (sGrid[i] == 'o')
			if (iCounter < iArrLength) //make sure not to overstep array length
			{
				aiGridLocations[iCounter] = i;
				iCounter++;
			} 
	}
	for(int i=0;i<iArrLength;i++)// fill aiUsedCoordinates with 36s, 36 means empty spot
		aiUsedCoordinates[i] = 36;
	//clear sGrid, ready to play
	sGrid = " +-1-+-2-+-3-+-4-+-5-+-6-+\na|   |   |   |   |   |   |\n+---+---+---+---+---+---+\nb|   |   |   |   |   |   |\n+---+---+---+---+---+---+\nc|   |   |   |   |   |   |\n+---+---+---+---+---+---+\nd|   |   |   |   |   |   |\n+---+---+---+---+---+---+\ne|   |   |   |   |   |   |\n+---+---+---+---+---+---+\nf|   |   |   |   |   |   |\n+---+---+---+---+---+---+\n";

	while (!iGameOver)
	{
		cout << sInstructionsGrid;
		cout << sStatus << endl;
		cout << sGrid;
		cout << "Fire at: ";
		getline(cin, sCoordinates);

		while (sCoordinates[0] < 'a' || sCoordinates[0] > 'f'// || sCoordinates[0] < 'A'// || sCoordinates[0] > 'F'
				|| sCoordinates[1] < '1' || sCoordinates[1] > '6')
		{
			sStatus = "Invalid input! a-f 1-6 only.";
			system("cls");
			cout << sInstructionsGrid;
			cout << sStatus << endl;
			cout << sGrid;
			cout << "Fire at: ";
			getline(cin, sCoordinates);
		}

		iCoordinates = convertCoordinateToInt(sCoordinates);
		//NEED TO STOP REPEATED ENTRIES
		if (!addToUsedArr(iCoordinates, aiUsedCoordinates, iArrLength))
		{
			sStatus = "Coordinate already tried.";
		}
		else
		{
			iNumOfTurns++;
			for (int i = 0; i < iShipsArrLength; i++)
			{
				if (iCoordinates == aiShips[i])
				{	//hit
					aiShips[i] = 37;// marked as hit
					sGrid.replace(aiGridLocations[iCoordinates], 1, "X");
					i = iArrLength; //found hit jump out of for loop
					sStatus = "A hit!";
					PlaySound(TEXT("Explosion+5.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
					Sleep(1000);
				}
				else
				{	//miss
					sGrid.replace(aiGridLocations[iCoordinates], 1, "O");
					sStatus = "A miss!";
				}
			}
		}
		if (bCarrier && aiShips[0] == 37 && aiShips[1] == 37 && aiShips[2] == 37 && aiShips[3] == 37)//check if Carrier was sunk
		{
			sStatus += " Enemy Carrier sunk!";
			PlaySound(TEXT("bubble7.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
			bCarrier = false;
		}
		if (bDestroyer && aiShips[4] == 37 && aiShips[5] == 37 && aiShips[6] == 37)//check if Destroyer was sunk
		{
			sStatus += "Enemy Destroyer sunk!";
			PlaySound(TEXT("bubble7.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
			bDestroyer = false;
		}
		if (bCruiser && aiShips[7] == 37 && aiShips[8] == 37)//check if Cruiser was sunk
		{
			sStatus += "Enemy Cruiser sunk!";
			PlaySound(TEXT("bubble7.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
			bCruiser = false;
		}

		if (!bCarrier && !bDestroyer && !bCruiser)
		{
			iGameOver = 1;
			system("cls");
			cout << sInstructionsGrid;
			cout << sStatus << endl;
			cout << sGrid;
		}
		
		if(!iGameOver)
			system("cls");
	}//Game over!
	
	cout << "All enemy ships have been sunk in " << iNumOfTurns << " turns." << endl;
	system("pause");
	return 0;
}

int convertCoordinateToInt(string sInput)
{
	//convert input coordinate into aiShips array coordinates, ie a number between 0-35
	int iCoord=0;

	switch (sInput[0])
	{
	case 'a':
		switch (sInput[1])
		{
		case '1':
			iCoord = 0;
			break;
		case '2':
			iCoord = 1;
			break;
		case '3':
			iCoord = 2;
			break;
		case '4':
			iCoord = 3;
			break;
		case '5':
			iCoord = 4;
			break;
		case '6':
			iCoord = 5;
			break;
		}
		break;
	case 'b':
		switch (sInput[1])
		{
		case '1':
			iCoord = 6;
			break;
		case '2':
			iCoord = 7;
			break;
		case '3':
			iCoord = 8;
			break;
		case '4':
			iCoord = 9;
			break;
		case '5':
			iCoord = 10;
			break;
		case '6':
			iCoord = 11;
			break;
		}
		break;
	case 'c':
		switch (sInput[1])
		{
		case '1':
			iCoord = 12;
			break;
		case '2':
			iCoord = 13;
			break;
		case '3':
			iCoord = 14;
			break;
		case '4':
			iCoord = 15;
			break;
		case '5':
			iCoord = 16;
			break;
		case '6':
			iCoord = 17;
			break;
		}
		break;
	case 'd':
		switch (sInput[1])
		{
		case '1':
			iCoord = 18;
			break;
		case '2':
			iCoord = 19;
			break;
		case '3':
			iCoord = 20;
			break;
		case '4':
			iCoord = 21;
			break;
		case '5':
			iCoord = 22;
			break;
		case '6':
			iCoord = 23;
			break;
		}
		break;
	case 'e':
		switch (sInput[1])
		{
		case '1':
			iCoord = 24;
			break;
		case '2':
			iCoord = 25;
			break;
		case '3':
			iCoord = 26;
			break;
		case '4':
			iCoord = 27;
			break;
		case '5':
			iCoord = 28;
			break;
		case '6':
			iCoord = 29;
			break;
		}
		break;
	case 'f':
		switch (sInput[1])
		{
		case '1':
			iCoord = 30;
			break;
		case '2':
			iCoord = 31;
			break;
		case '3':
			iCoord = 32;
			break;
		case '4':
			iCoord = 33;
			break;
		case '5':
			iCoord = 34;
			break;
		case '6':
			iCoord = 35;
			break;
		}
		break;
	}
	return iCoord;
}
void sorLowToHi(int arr[], int size)
{
	int iStorage = 0;

	for (int j = 0; j < size - 1; j++)
	{
		if (!(j == size - 1)) //don't let j go pass end of array length
			if (arr[j] > arr[j + 1])
			{
				iStorage = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = iStorage;
				j = -1;
			}
	}
}
bool addToUsedArr(int iAdd, int arr[], int size) // return flase if iAdd is already in arr
{
	bool bAddNotInArr = true;
	int iNext=0; // storge next place in arr to store to

	for (int i = 0; i < size; i++)
		if (arr[i] == iAdd) //iAdd is in arr already
		{
			bAddNotInArr = false;
			i = size + 1; // end for loop
		}
		else if (arr[i] == 36) //36 is empty
		{
			iNext = i; //keep next available spot in arr
			i = size + 1; // end for loop
		}
	if (bAddNotInArr) //add iAdd is not in arr add it to arr
		arr[iNext] = iAdd;
	return bAddNotInArr;
}
bool isToUsedArrFull(int arr[], int size)
{
	bool bArrFull = false;
	for (int i = 0; i < size; i++)
		if (arr[i] != 36) //36 indicates empty
			bArrFull = true;
	return bArrFull;
}
bool isNumInArr(int arr[], int size, int iNum)
{
	bool bInArr = false;
	for (int i = 0; i < size; i++)
		if (arr[i] == iNum) //iNum is in arr
			bInArr = true;
	return bInArr;
}