/*  Vincent Mossman
	Arrays
	March 11, 2013
	User is prompted for filename of file containing list of 25 integers and several operations are performed.
	*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

//Constants:
const int ARRAY_SIZE = 25;
const int FILENAME_SIZE = 45; /* Should be more than big enough for normal named text files */

//Prototypes:
void FillArray(int QuieriedArray[]);
int GetFileSize(char QuieriedFile[]);
void DisplayArray(int Array[]);
int ArrayMax(int Array[]);
int ArrayMin(int Array[]);
int ArraySum(int Array[]);
int SearchArray(int Array[]);
void NumberSuffix(char NumSuffix[], int Num); /* Just for fun */

void main()
{
	int NumArray[ARRAY_SIZE];
	char NumSuffix[2]; /* suffix for after index number, just for fun */
	int SearchIndex;
	cout.setf(ios::showpoint | ios::fixed);

	FillArray(NumArray);
	DisplayArray(NumArray);

	cout << "  Maximum Value: " << ArrayMax(NumArray) << endl;
	cout << "  Minimum Value: " << ArrayMin(NumArray) << endl;
	cout << "  Sum of Values: " << ArraySum(NumArray) << endl;
	cout << "  Average of Values: " << setprecision(2) << double(ArraySum(NumArray)) / double(ARRAY_SIZE) << endl;

	SearchIndex = SearchArray(NumArray);

	if (SearchIndex != -1)
	{
		cout << endl << "  Your value was found at index " << SearchIndex << '.' << endl;
		NumberSuffix(NumSuffix, (SearchIndex + 1)); // fills suffix array
		cout << "  In other words, it is the " << SearchIndex + 1 << NumSuffix[0] << NumSuffix[1] 
			<< " number in the list." << endl;
	}
	else
		cout <<  endl << "  Your value could not be found." << endl;

	cout << endl << endl << endl;

	system("pause");
}

//Pre-con: Requires a variable containing an array to be filled.
//Post-con: Fills array from location defined by user.
/*Other: If the file defined by the user contains a different amount of integers than the defined array size, the
	function will notify the user and ask for a different file. Also, if the file does not exist, the function will
	notify the user. */
void FillArray(int QuieriedArray[])
{
	ifstream InFile;
	char FileName[FILENAME_SIZE];

	//Nested loop for robust file retrieving:
	do
	{
		cout << endl << '\t' << "Please enter the name of the file: ";
		cin >> FileName;
	
		system("cls");

		InFile.open(FileName);

		while (InFile.fail())
		{
			cout << endl << '\t' << "WARNING: File '" << FileName << "' does not exist." << endl << endl;
			cout << '\t' << "Please enter the name of the file: ";
			cin >> FileName;

			system("cls");

			InFile.open(FileName);
		}

		system("cls");

		if (GetFileSize(FileName) != ARRAY_SIZE)
		{
			cout << endl << '\t' << "WARNING: The number of integers (" << GetFileSize(FileName)
				<< ") in this file is unsupported by" << endl << "\t\t"
				<< "this program. Please choose a different file." << endl << endl;
			InFile.close();
		}
	} while (GetFileSize(FileName) != ARRAY_SIZE);

	//Retrieves and fills array:
	for (int i = 0; i < ARRAY_SIZE; i++)
		InFile >> QuieriedArray[i];
}

//Info: Simple function that returns the number of numbers inside a given file, simply for robustness
//Pre-con: Filename
//Post-con: Returns number of numbers
int GetFileSize(char QuieriedFile[])
{
	int temp;
	int num_of_nums = 0;

	ifstream InFile;
	InFile.open(QuieriedFile);

	InFile >> temp;

	while (!InFile.eof())
	{
		num_of_nums++;
		InFile >> temp;
	}

	return num_of_nums;
}

//Pre-con: Array to be displayed
//Post-con: Displays array
void DisplayArray(int Array[])
{
	cout << endl << "\tYour Numbers:" << endl << '\t';

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << Array[i];
		if (i < (ARRAY_SIZE - 1))
			cout << ", ";
		if (i == 15)
			cout << endl << '\t';
	}

	cout << endl << endl;
}

//Pre-con: Array to find maximum value of
//Post-con: Returns maximum value
int ArrayMax(int Array[])
{
	int temp = Array[0]; /* since its possible for the array to contain negative numbers its better to start
						 with the first value of the array than zero */

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (Array[i] >= temp)
			temp = Array[i];
	}

	return temp;
}

//Pre-con: Array to find minimum value of
//Post-con: Returns minimum value
int ArrayMin(int Array[])
{
	int temp = Array[0]; /* since its possible for the array to contain negative numbers its better to start
						 with the first value of the array than zero */

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (Array[i] <= temp)
			temp = Array[i];
	}

	return temp;
}

//Pre-con: Array to find sum of
//Post-con: Returns sum
int ArraySum(int Array[])
{
	int temp = 0;

	for (int i = 0; i < ARRAY_SIZE; i++)
		temp += Array[i];

	return temp;
}

//Pre-con: Array to search
//Post-con: Returns index value of number if it is found, if it is not found returns a -1.
/*Other: DOES NOT account for duplicate entries, so if number searched for appears more than once, it only returns
	the index value of the first instance */
int SearchArray(int Array[])
{
	int ValToFind;
	int temp = -1; /* if no matching value is found in the loop below, temp will remain as -1 */

	cout << endl << "\tEnter the value you would like to search for: ";
	cin >> ValToFind;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (ValToFind == Array[i])
		{
			temp = i;
			break;
		}
	}

	return temp;
}

//Pre-con: 2 slot char array to fill / Number to find suffix of
//Post-con: Fills 2 slot char array with appropriate suffix
void NumberSuffix(char NumSuffix[], int Num)
{
	switch (Num)
	{
	case 1:
	case 21:
		{
			NumSuffix[0] = 's';
			NumSuffix[1] = 't';
		}
		break;
	case 2:
	case 22:
		{
			NumSuffix[0] = 'n';
			NumSuffix[1] = 'd';
		}
		break;
	case 3:
	case 23:
		{
			NumSuffix[0] = 'r';
			NumSuffix[1] = 'd';
		}
		break;
	default:
		{
			NumSuffix[0] = 't';
			NumSuffix[1] = 'h';
		}
	}
}