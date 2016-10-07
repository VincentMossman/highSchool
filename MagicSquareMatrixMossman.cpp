/// Vincent Mossman
/// Magic Square Matrix Project
/// March 18, 2013
/// Program builds and initializes a matrix, fills this matrix with a
///  "Magic Square," then displays and checks this magic square.
/// Also, I've changed my commenting style a bit, hopefully
///  making things feel a bit less cluttered. Personally,
///  I like it already.

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

/// Constomizable options:
const int ARRAYSIZE = 17; // Magic Square matrix size will be ARRAYSIZE x ARRAYSIZE.
const bool PAUSE_BETWEEN_CHECKS = false; // Set to true to match project requirements, false for speed.

/// Prototypes:
void CheckArraySize();
void InitializeMatrix(int Matrix[ARRAYSIZE][ARRAYSIZE]); 
void DisplayMatrix(int Matrix[ARRAYSIZE][ARRAYSIZE]);
void BuildMagicSquare(int Matrix[ARRAYSIZE][ARRAYSIZE]);
void CheckMagicSquare(int Matrix[ARRAYSIZE][ARRAYSIZE]);

void main()
{
	char userchoice = 'x';

	do
	{
		int MagicSquare[ARRAYSIZE][ARRAYSIZE];

		cout << "Checking for valid size..." << endl; 
		CheckArraySize();
		Sleep(750); // For dramatic effect.

		cout << "Initializing Magic Square..." << endl;
		InitializeMatrix(MagicSquare);
		Sleep(750);

		cout << "Un-filled Magic Square:" << endl << endl;
		DisplayMatrix(MagicSquare);
		Sleep(750);

		cout << endl << "Building Magic Square..." << endl;
		BuildMagicSquare(MagicSquare);
		Sleep(750);

		cout << "Filled Magic Square: " << endl << endl;
		DisplayMatrix(MagicSquare);
		Sleep(750);

		cout << endl << "Checking Magic Square: " << endl;
		CheckMagicSquare(MagicSquare);
	
		cout << endl << endl << "\t\t Would you like to run the program again? (y/n) ";
		cin >> userchoice;

		while ((userchoice != 'n') && (userchoice != 'N') && (userchoice != 'y') && (userchoice != 'Y'))
		{
			cout << "\t\t Invalid entry. Please try again: (y/n) ";
			cin >> userchoice;
		}

		system("cls");
	} while ((userchoice != 'n') && (userchoice != 'N'));
}

/// Checks ARRAYSIZE for valid number (must be odd).
/// If odd, the function notifies the user and automatically exits the
///  program in 10 seconds. (using the <stdlib.h> exit() and 
///  <windows.h> Sleep() functions respectively).
/// If ARRAYSIZE is greater than 31 (whose power of 2
///  would be more than 1000) program is terminated.
/// If ARRAYSIZE is greater than 17 (which causes formatting issues)
///  user is asked if they want to continue regardless.
void CheckArraySize()
{
	cout << endl << "\tNotice: The Magic Square size is static and must be changed in the" << endl 
		<< "\t\t code itself."	<< endl << endl;

	if (!(ARRAYSIZE % 2))
	{
		cout << endl << "\tWARNING: The set array size (" << ARRAYSIZE << ") is not compatible." 
			<< endl << "\t\t Please change ARRAYSIZE to an odd number." << endl << endl << endl 
			<< "\t\t Program will automatically terminate in 15 seconds...";
		Sleep(15000);
		exit(EXIT_SUCCESS);
	}

	if (pow(double(ARRAYSIZE), 2) > 1000)
	{
		cout << endl << "\tWARNING: The set array size (" << ARRAYSIZE << ") is not compatible." 
			<< endl << "\t\t Please change ARRAYSIZE to a number less than 32." << endl << endl << endl 
			<< "\t\t Program will automatically terminate in 15 seconds...";
		Sleep(15000);
		exit(EXIT_SUCCESS);
	}

	if (ARRAYSIZE > 17)
	{
		char userchoice = 'x';
		cout << endl << "\tWARNING: The set array size (" << ARRAYSIZE << ") is known to have formatting" 
			<< endl << "\t\t issues on standard sized console windows." << endl << endl;

		cout << "\t\t Would you like to continue anyway? (y/n) ";

		do
		{
			cin >> userchoice;
			
			if ((userchoice == 'n') || (userchoice == 'N'))
				exit(EXIT_SUCCESS);
			else if ((userchoice != 'n') && (userchoice != 'N') && (userchoice != 'y') && (userchoice != 'Y'))
				cout << endl << "\t\t Invalid entry. Please try again: (y/n) ";
			else if ((userchoice == 'y') || (userchoice == 'Y'))
				break;
		} while ((userchoice != 'y') || (userchoice != 'Y'));

		cout << endl;
	}
}

/// Initializes all elements of passed matrix to 0.
/// Passed matrix must be square (n x n). More
///  specifically (ARRAYSIZE x ARRAYSIZE).
void InitializeMatrix(int Matrix[ARRAYSIZE][ARRAYSIZE])
{
	for (int i = 0; i < ARRAYSIZE; i++)
		for (int j = 0; j < ARRAYSIZE; j++)
			Matrix[i][j] = 0;
}

/// Displays ARRAYSIZEd matrix.
/// Passed matrix must be ARRAYSIZE x ARRAYSIZE.
/// Is intelligent in that it resizes for matricies
///  containing integers exceeding one digit in
///  length.
void DisplayMatrix(int Matrix[ARRAYSIZE][ARRAYSIZE])
{
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		cout << '\t';

		for (int j = 0; j < ARRAYSIZE; j++)
		{
			if (pow(double(ARRAYSIZE), 2) < 10)
				cout << Matrix[i][j] << ' ';
			else if ((pow(double(ARRAYSIZE), 2) >= 10) && (pow(double(ARRAYSIZE), 2) < 100))
			{
				if (Matrix[i][j] < 10)
					cout << Matrix[i][j] << "  "; // Extra space for non-two-digit integer.
				else
					cout << Matrix[i][j] << ' ';
			}
			else if ((pow(double(ARRAYSIZE), 2) >= 100) && (pow(double(ARRAYSIZE), 2) < 1000))
			{
				if (Matrix[i][j] < 10)
					cout << Matrix[i][j] << "   "; // Extra spaces for non-three-digit integer.
				else if ((Matrix[i][j] >= 10) && (Matrix[i][j] < 100))
					cout << Matrix[i][j] << "  "; // Extra space for non-three-digit integer.
				else
					cout << Matrix[i][j] << ' ';
			}
		}

		cout << endl;
	}
}

/// Constructs Magic Square as defined in project requirements
/// Passed matrix must be ARRAYSIZE x ARRAYSIZE.
void BuildMagicSquare(int Matrix[ARRAYSIZE][ARRAYSIZE])
{
	int startpoint = (ARRAYSIZE / 2);
	int row = 0, col = startpoint; // A little redundant I suppose.
	int i = 1;
	
	while (i <= pow(double(ARRAYSIZE), 2))
	{
		Matrix[row][col] = i++;

		int temprow = row, tempcol = col; // In case next position is occupied;

		row--;
		col++;
		
		if (row < 0)
			row = ARRAYSIZE - 1;

		if (col > (ARRAYSIZE - 1))
			col = 0;

		if (Matrix[row][col] != 0)
		{
			row = temprow + 1;
			col = tempcol;
		}
	}
}

/// Checks Magic Square for correct construction.
/// Passed matrix must be ARRAYSIZE x ARRAYSIZE.
void CheckMagicSquare(int Matrix[ARRAYSIZE][ARRAYSIZE])
{
	int magicnumber, counter = 0;
	magicnumber = int(((ARRAYSIZE * (pow(double(ARRAYSIZE), 2) + 1)) / 2));

	cout << "Magic number: " << magicnumber << endl << endl;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		cout << "Checking row " << i << ':' << endl;
		for (int j = 0; j < ARRAYSIZE; j++)
		{
			if (j < (ARRAYSIZE - 1))
				cout << Matrix[i][j] << " + ";
			else
				cout << Matrix[i][j] << " = ";
			counter += Matrix[i][j];
		}
		cout << counter << endl;
		if (PAUSE_BETWEEN_CHECKS == true)
			system("pause");
		counter = 0;
	}

	for (int j = 0; j < ARRAYSIZE; j++)
	{
		cout << "Checking column " << j << ':' << endl;
		for (int i = 0; i < ARRAYSIZE; i++)
		{
			if (i < (ARRAYSIZE - 1))
				cout << Matrix[i][j] << " + ";
			else
				cout << Matrix[i][j] << " = ";
			counter += Matrix[i][j];
		}
		cout << counter << endl;
		if (PAUSE_BETWEEN_CHECKS == true)
			system("pause");
		counter = 0;
	}

	cout << "Checking upper left to lower right diagonal:" << endl;
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		if (i < (ARRAYSIZE - 1))
			cout << Matrix[i][i] << " + ";
		else
			cout << Matrix[i][i] << " = ";
		counter += Matrix[i][i];
	}
	cout << counter << endl;
	counter = 0;

	if (PAUSE_BETWEEN_CHECKS == true)
			system("pause");

	cout << "Checking lower left to upper right diagonal:" << endl;
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		if (i < (ARRAYSIZE - 1))
			cout << Matrix[(ARRAYSIZE - 1) - i][i] << " + ";
		else
			cout << Matrix[(ARRAYSIZE - 1) - i][i] << " = ";
		counter += Matrix[i][i];
	}
	cout << counter << endl;
	counter = 0;
}