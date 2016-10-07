#include <iostream>
using namespace std;

void main()
{
	double grade;

	cout << "Enter percentage: ";
	cin >> grade;

	if (grade <= 50)
	{
		cout << "YOU FAIL";
	}
	else if (grade >= 60 && grade < 70)
	{
		cout << "D";
	}
	else if (grade >= 70 && grade < 80)
	{
		cout << "C";
	}
	else if (grade >= 80 && grade < 90)
	{
		cout << "B";
	}
	else
	{
		cout << "A";
	}

	cout << endl << endl;

	system("pause");
}