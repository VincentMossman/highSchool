#include <iostream>
using namespace std;
#include <string>

void mainlol()
{
	char FirstName[10] = "McMartin";
	char LastName[] = "McMartin";
	char Name[15];

	cout << "The length is: " << strlen(FirstName) << endl << endl;

	strcpy(Name, strcat(FirstName, LastName));

	int result;
	result = strcmp(FirstName, LastName);

	cout << result << endl << endl;

	/*
	cout << "Enter your first name: ";
	cin >> FirstName;

	cout << endl << "Enter your last name: ";
	cin >> LastName;

	cout << endl << FirstName << ' ' << LastName;

	cout << endl << endl;
	*/

	system("pause");
}