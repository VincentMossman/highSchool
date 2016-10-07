#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
using namespace std;

/*
3 types of loops:
	for loop
	while loop
	do loop

General Form:

for (int i = 0; i < 100; i++)
{
	statement1;
	statement2;
}
statement3;
*/

/*
for loop:

void main()
{

	cout.setf(ios::showpoint | ios::fixed);

	for (int i = 20; i >=10; i--)
	{
		cout << setw(i) << "*" << setw((20-i) + (20-i) + 1) << "*" << endl;
	}

	cout << endl;

	system("pause");
}

*/

/* 
while loop:

void main ()
{
	int EvenNumber;

	cout << "Enter an even number: ";
	cin >> EvenNumber;

	while (EvenNumber % 2)
	{
		cout << "Enter an EVEN number: ";
		cin >> EvenNumber;
	}

	cout << EvenNumber << endl << endl;

	system("pause");
}
*/

/* do loop


const double ACCURACY = 0.0001;

void maisdf  n()
{
	char Again = 'y';

	double number, old_guess, new_guess;

	do 
	{
		cout << "Enter a number to squarerootify: ";
		cin >> number;
	
		old_guess = rand() % RAND_MAX;
	
		new_guess = 1.0 / 2.0 * (old_guess + number / old_guess);
	
		do
		{
			old_guess = new_guess;
			new_guess = 1.0 / 2.0 * (old_guess + number / old_guess);
			cout << new_guess << endl;
	
		} while (fabs(new_guess - old_guess) >= ACCURACY);
	
		cout.setf(ios::showpoint | ios::fixed);
		cout << setprecision(4);
		cout << new_guess << endl;
	
		system("pause");

		cout << "Do you want to continue? (Y/N) ";
		cin >> Again;
		system("CLS");
	} while (Again == 'y' || Again == 'Y');
}

*/

void mainballs()
{
	int k, j, rows;

	cout.setf(ios::showpoint | ios::fixed);

	do 
	{
		cout << "How many rows of stars do you want? ";
		cin >> rows;
		for (k = rows; k >= 1; k--)
		{
			cout << setw(k);
				
				for (j = 1; j <= ((rows + 1) - k); j++)
				{
					cout << '*';
				}
	
				for (j = (rows * 2); j >= ((rows + 1) + k); j--)
				{
					cout << '*';
				}
	
				cout << endl;
		}
		cout << endl << endl;
	} while (rows != -999);
}