#include <iostream>
using namespace std;

struct StudentInfo
{
	char FirstName[10];
	char LastName[10];
	int Age;
	int Grade;
};

void mainnotwithme()
{
	StudentInfo StudInfo_Array[2];
	
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter student " << i + 1 << "'s first name: ";
		cin >> StudInfo_Array[i].FirstName;
		cout << "Enter student " << i + 1 << "'s last name: ";
		cin >> StudInfo_Array[i].LastName;
		cout << "Enter student " << i + 1 << "'s age: ";
		cin >> StudInfo_Array[i].Age;
		cout << "Enter student " << i + 1 << "'s grade: ";
		cin >> StudInfo_Array[i].Grade;
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "Student " << i + 1 << "'s first name: ";
		cout << StudInfo_Array[i].FirstName << endl;
		cout << "Student " << i + 1 << "'s last name: ";
		cout << StudInfo_Array[i].LastName << endl;
		cout << "Student " << i + 1 << "'s age: ";
		cout << StudInfo_Array[i].Age << endl;
		cout << "Student " << i + 1 << "'s grade: ";
		cout << StudInfo_Array[i].Grade << endl;
		cout << endl;
	}
	
	cout << endl << endl;

	system("pause");
}