/*  Vincent Mossman
	Reverse Digits
	December 19, 2012
	The user will enter a 6-digit integer and it will return the mirror of the input
	*/

//May not use all of these. But just in case:
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int DigitFlip(int SUB_UserInput); //Function prototype

void main()
{
	//Function variables
	double UserInput;
	int FlippedDigit;

	cout << "Please enter a 6-digit positive integer: ";
	cin >> UserInput; //By the way. Don't enter a char[] type. You get a nasty runtime loop.

	//I like robustness
	if (UserInput > 999999) { //Checks for invalid entry
		cout << endl << "WARNING: That is not a valid number! The number must be a 6-digit integer." << endl << endl; 
		main(); //Main is called and the user has a chance to input a valid integer
	}
	else if (UserInput < 100000) { //Checks for invalid entry
		cout << endl << "WARNING: That is not a valid number! The number must be a 6-digit integer." << endl << endl;
		main(); //Main is called and the user has a chance to input a valid integer
	}
	else if (fmod(UserInput, 1) != 0) { //Checks for invalid entry. fmod is a mod for doubles.
		cout << endl << "WARNING: That is not a valid number! The number cannot be a decimal." << endl << endl;
		main(); //Main is called and the user has a chance to input a valid integer
	}
	else {
		FlippedDigit = DigitFlip(int(UserInput)); //Type casts the double to an integers then calls DigitFlip function
		cout << endl << "The integer " << UserInput << " reversed is " << FlippedDigit << endl << endl;
		system("Pause");
	}
}

//Pre-con: Function accepts a 6 digit integer
//Post-con: Function returns the mirror of accepted 6 digit integer
int DigitFlip(int SUB_UserInput)
{
	//Function variables
	int temp = SUB_UserInput;
	int _1, _2, _3, _4, _5, _6;

	//Extract Numbers
	_1 = temp % 10;
	temp = temp - _1;
	_2 = temp % 100;
	temp = temp - _2;
	_3 = temp % 1000;
	temp = temp - _3;
	_4 = temp % 10000;
	temp = temp - _4;
	_5 = temp % 100000;
	temp = temp - _5;
	_6 = temp % 1000000;
	//****************

	//Replace-erize Numbers
	_1 = _1 * 100000;
	_2 = _2 * 1000;
	_3 = _3 * 10;
	_4 = _4 / 10;
	_5 = _5 / 1000;
	_6 = _6 / 100000;
	//****************

	//Rewrite Numbers
	temp = _1 + _2 + _3 + _4 + _5 + _6;
	//****************

	return temp; //Returns the final mirrored integer
}