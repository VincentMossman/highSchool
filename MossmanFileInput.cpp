/*  Vincent Mossman
	File Input
	February 23, 2013
	This program analyzes a text file and prints a histogram showing the amounts of each character in the file
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <stdlib.h>
using namespace std;

//Prototypes:
int GetChar(char desired_char);
void DisplayFile();
void CharHistogram();

void main()
{
	DisplayFile();
	CharHistogram();

	cout << endl << endl;

	system("pause");
}

//Pre-Con: Function must recieve the desired char
//Post-Con: Returns number of how many of that char is in the text file
//Other: Current file to open is "TextIn.txt" and the function also handles upper and lower case.
//	     Notifies user and exits program if file does not exist.
int GetChar(char desired_char)
{
	char data, uppercase_char, lowercase_char;
	int num_of_desired_char = 0;

	//Makes an upper and lower case version of the desired char to be counted:
	uppercase_char = toupper(desired_char);
	lowercase_char = tolower(desired_char);

	ifstream InFile;
	InFile.open("TextIn.txt");
	
	if (InFile.fail())
	{
		cout << endl << "Error" << endl << endl << "That file does not exist." << endl << endl;
		system("pause");
		exit(EXIT_SUCCESS);
	}
	else
	{
		while (InFile.get(data))
		{
			if ((data == uppercase_char) || (data == lowercase_char))
				num_of_desired_char++;
		}

		InFile.close();
	}

	return num_of_desired_char;
}

//Pre-con: None
//Post-con: Displays "TextIn.text" contents
//Other: Current file to open is "TextIn.txt" and prints a horizontal line after file.
//		 Notifies user if file does not exist.
void DisplayFile()
{
	char data;

	ifstream InFile;
	InFile.open("TextIn.txt");

	if (InFile.fail())
	{
		cout << endl << "Error" << endl << endl;
	}
	else 
	{
		while (InFile.get(data))
			cout << data;

		InFile.close();
	}

	//Horizontal line:
	cout << endl;
	for (int i = 1; i <= 40; i++)
		cout << '_';
}

//Pre-con: None
//Post-con: Counts and displays histogram of the number of characters.
void CharHistogram()
{
	int num;

	cout << endl << endl << "Letters:" << endl;

	for (char i = 'a'; i <= 'z'; i++)
	{
		num = GetChar(i);
		if (num > 0)
		{
			cout << i << "'s\t";
			for (int i = 1; i <= num; i++)
				cout << '*';
			cout << endl;
		}
	}
}