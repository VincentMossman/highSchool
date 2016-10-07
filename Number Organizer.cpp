//This program will get two integers from the user and display them from largest to smallest

#include <iostream>
using namespace std;

void GetData(int &first, int &second);
void DetermineLarger(int &min, int &max);
void PrintResults(int min, int max);

void main()
{
	int one, two;
	GetData(one, two);
	DetermineLarger(one, two);
	PrintResults(one, two);

	system("pause");
}

void GetData(int &first, int &second)
{
	cout << "Enter the first integer: ";
	cin >> first;
	cout << "Enter the second integer: ";
	cin >> second;
	cout << endl;
}

void DetermineLarger(int &min, int &max)
{
	int temp;

	if (min < max)
	{ 
		temp = min;
		min = max;
		max = temp;
	}
}

void PrintResults(int min, int max)
{
	cout << "\tLarger Number\t\tSmaller Number" << endl;
	cout << "\t-------------\t\t--------------" << endl;
	cout << "\t\t" << min << "\t\t\t" << max << endl << endl;
}
