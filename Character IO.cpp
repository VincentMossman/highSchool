#include <iostream>
#include <fstream>
using namespace std;

const char sentinel = 'Q';

void mainhjk()
{
	char data;
	ifstream InFile;
	ofstream OutFile;

	//InFile.open("TextIn.txt");
	OutFile.open("TextIn.txt");

	cout << "Enter a character: (Q to quit) ";
	cin >> data;

	cout << data << endl;

	while (data != sentinel)
	{
		OutFile.put(data);

		cout << "Enter a character: (-999 to quit) ";
		cin >> data;

		cout << data << endl; 
	}

	OutFile.close();

	/*
	if (InFile.fail())
		cout << "File could not be found. Make sure you have entered the write filename. " << endl;
	else
	{
		while (InFile.get(data))
		{
			// InFile.ignore(17);

			if (data == '\n')
				cout << " END OF LINE";
			else if (data == '\t')
			{
				cout << " TAB ";
				continue;
			}

			cout << data;
		}

		cout << endl << endl << "Done" << endl << endl;
	}

	InFile.close();

	*/

	// system("pause");
}