#include <iostream>
#include "Complex.cpp"
using namespace std;

void mainyall()
{
	for(;;)
	{
		Complex i, k;
		char choice;

		cout << "Enter a complex number: ";
		cin >> k;
		cout << "Enter another complex number: ";
		cin >> i;

		cout << endl << "What do you wanna do?\n\nAdd (a)\nSubtract (s)\nMultiply (m)\nDivide (d)\n\nYour Choice: ";
		cin >> choice;
		cout << endl << endl;

		if (choice == 'a')
		{
			k = k + i;
			cout << k << endl;
			k.Print();
			cout << endl << endl;
		}
		else if (choice == 's')
		{
			k = k - i;
			cout << k << endl;
			k.Print();
			cout << endl << endl;
		}
		else if (choice == 'm')
		{
			k = k * i;
			cout << k << endl;
			k.Print();
			cout << endl << endl;
		}
		else if (choice == 'd')
		{
			k = k / i;
			cout << k << endl;
			k.Print();
			cout << endl << endl;
		}

		system("pause");
		system("cls");
	}

	system("pause");
}