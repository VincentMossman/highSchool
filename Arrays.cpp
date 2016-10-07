#include <iostream>
using namespace std;

const int ArraySize = 17;

void FillArraylol(int Num[]);
void DoubleArray(int Num[]);
void DisplayArray(int Num[]);

void maintz()
{
	int List[ArraySize];
	FillArraylol(List);
	DoubleArray(List); 
	DisplayArray(List);
	
	/*
	for (int i = 0; i < ArraySize; i++)
	{
		cout << "Enter an integer: ";
		cin >> List[i];
	}

	for (int i = 0; i < ArraySize; i++)
	{
		cout << List[i] << endl;
	}
	*/

	system("pause");
}

void FillArraylol(int Num[])
{
	int a = 3;

	for (int j = 0; j < ArraySize; j++)
		Num[j] = a + j;
}

void DisplayArray(int Num[])
{
	for (int i = 0; i < ArraySize; i++)
		cout << Num[i] << endl;
}

void DoubleArray(int Num[])
{
	for (int i = 0; i < ArraySize; i++)
		Num[i] *= 2;
}