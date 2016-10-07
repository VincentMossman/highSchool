#include <fstream>
#include <iostream>
using namespace std;

const int Sentinel = -999;

void haleymain()
{
	int data;

	//Write to file:

	ofstream OutFile;  /*"OutFile" be anything*/

	OutFile.open("GoingOut.txt");
	cout << "Enter an integer: (-999 to go to next step)";
	cin >> data;

	while (data != Sentinel)
	{
		OutFile << data << endl;
		cout << "Enter an integer: ";
		cin >> data;
	}

	OutFile.close();

	//***********************************

	//Read from file:

	ifstream InFile;

	InFile.open("GoingOut.txt");
	OutFile.open("GoingOut2.txt");
	
	if (InFile.fail())
	{
		cout << "File does not exist." << endl;
	}
	else
	{
		InFile >> data;

		while (!InFile.eof())
		{
			data = data * 2;
			OutFile << data << endl;
			InFile >> data;
		}

		InFile.close();
		OutFile.close();
	}

	//********************************
}