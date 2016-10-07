#include <iostream>
using namespace std;



void mains()
{
	/*
	int score;
	char grade;

	cout << "Enter your score: ";
	cin >> score;

	switch (score)
	{
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
	case 7:
		grade = 'B';
		break;
	case 6:
	case 5: 
		grade = 'C';
		break;
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		grade = 'F';
	}

	cout << grade << endl;
	*/

	
	char choice;
	int a, b;

	cout << "Enter two numbers: " << endl;
	cin >> a >> b;

	cout << "******************************************" << endl;
	cout << "*******            MENU            *******" << endl;
	cout << "*******                            *******" << endl;
	cout << "*******   Press A to add           *******" << endl;
	cout << "*******   Press S to subtract      *******" << endl;
	cout << "*******   Press M to multiply      *******" << endl;
	cout << "*******   Press D to divide        *******" << endl;
	cout << "*******   Press Q to quit          *******" << endl;
	cout << "*******                            *******" << endl;
	cout << "******************************************" << endl;

	cin >> choice;

	switch (choice)
	{
	case 'A':
	case 'a':
		cout << a + b << endl;
		break;
	case 'S':
	case 's':
		cout << a - b << endl;
		break;
	case 'M':
	case 'm':
		cout << a * b << endl;
		break;
	case 'D':
	case 'd':
		cout << a / b << endl;
		break;
	case 'Q':
	case 'q':
		break;
	}


	system("pause");

}