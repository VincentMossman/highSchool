#include <iostream>
using namespace std;

const int NumRows = 3;
const int NumCols = 3;

void Display(char CharacterSquare[NumRows][NumCols]);
void FillArray(char CharacterSquare[NumRows][NumCols]);

void maint()
{
	char CharacterSquare[NumRows][NumCols] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};

	FillArray(CharacterSquare);
	Display(CharacterSquare); //Currently set to diagonal display

	system("pause");
}

void Display(char CharacterSquare[NumRows][NumCols])
{
	for (int i = 0; i <= (NumRows - 1); i++)
	{
		for (int k = 0; k <= (NumCols - 1); k++)
			if (i == k)
				cout << CharacterSquare[i][k] << ' ';
			else 
				cout << "  ";
		
		cout << endl;
	}

	cout << endl;
}

void FillArray(char CharacterSquare[NumRows][NumCols])
{
	cout << "Please enter 9 letters: ";
	
	for (int i = 0; i <= (NumRows - 1); i++)
	{
		for (int k = 0; k <= (NumCols - 1); k++)
			cin >> CharacterSquare[i][k];
	}

	cout << endl;
}