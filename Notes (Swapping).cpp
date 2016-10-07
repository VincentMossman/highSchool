//You can put const in a functions arguments

#include <iostream>
#include <Windows.h>
using namespace std;

void Swap(double &NumOne, double &NumTwo);

void nomain()
{
	double Num1, Num2;

	cout << "Enter a number: ";
	cin >> Num1;
	cout << "Enter another number: ";
	cin >> Num2;
	cout << endl << endl;

	Swap(Num1, Num2);

	cout << "First number: " << Num1 << endl << "Second number: " << Num2 << endl << endl;
	cout << "SWAPIFICATION FUCNTION ACTIVATED" << endl << endl;
	Sleep(2000);
	cout << "First number: " << Num1 << endl << "Second number: " << Num2 << endl << endl;

	system("Pause");
}

void Swap(double &NumOne, double &NumTwo) //The & makes it able to change the actual variable. (byref)
{
	double temp;

	temp = NumOne;
	NumOne = NumTwo;
	NumTwo = temp;
}