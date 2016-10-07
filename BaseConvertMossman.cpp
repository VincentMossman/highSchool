/// Vincent Mossman
/// Base Convert Project
/// April 2, 2013
/// This program will convert any user defined integer from a user defined base to an integer in 
///  another user defined base. For example, it will convert 10 (in binary) to 2 (in base 10).

#include <iostream>
#include <math.h>
using namespace std;

/// Prototypes:
int tobaseten(int orig_int, int orig_base);
int getdigits(int num);
bool validnum(int num, int base);
int changebase(int num, int base);

void main()
{
	char runagain = 'n';

	do
	{
		int num, base, baseto;
		cout << "Enter a number: ";
		cin >> num;
		cout << "Enter its base: ";
		cin >> base;
		cout << "Enter the base you would like to convert this number to: ";
		cin >> baseto;

		if (validnum(num, base))
			if ((changebase(tobaseten(num, base), baseto)) != -1)
				cout << endl << endl << "The number " << num << " in base " << base
				<< " converts to " << (changebase(tobaseten(num, base), baseto))
				<< " in base " << baseto << '.' << endl << endl << endl;
			else
				cout << endl << endl << "The base " << baseto << " is not compatible with this program."
				<< endl << endl;
		else
			cout << endl << base << " is not a valid base." << endl << endl << endl;

		cout << "Would you like to convert another number? (y/n) ";
		cin >> runagain;

		while ((runagain != 'n') && (runagain != 'N') && (runagain != 'y') && (runagain != 'n'))
		{
			cout << "That is not a valid choice. Would you like to convert another number? (y/n) ";
			cin >> runagain;
		}
		
		system("cls");

	} while ((runagain == 'y') || (runagain == 'Y'));
}

/// Converts integer of any base to integer of base 10.
int tobaseten(int orig_int, int orig_base)
{
	int baseten = 0;

	/// Complex algorithm that converts an int of any base to an int of base 10.
	for (int i = getdigits(orig_int) - 1; i >= 0; i--)
	{
		int temp = (orig_int - (orig_int % int(pow(10, double(i))))) / int(pow(10, double(i)));
		orig_int -= (orig_int - (orig_int % int(pow(10, double(i)))));
		baseten += temp * int(pow(orig_base, double(i)));
	}

	return baseten;
}

/// Returns the number of digits in an integer.
int getdigits(int num)
{
	int digits = 0;

	for (double temp = double(num); temp >= 1; temp /= 10)
		digits++;

	return digits;
}

/// Returns "true" if the integer is valid for its base.
/// Returns "false" if the integer is not valid for its base or has an incompatible base (below 2 or over 10).
bool validnum(int num, int base)
{
	bool validnum = true;

	if ((base < 2) || (base > 10))
		validnum = false;
	else
	{
		for (int i = getdigits(num) - 1; i >= 0; i--)
		{
			/// Same algorithm as used in base ten convert func, except used to find invalid numbers.
			int temp = (num - (num % int(pow(10, double(i))))) / int(pow(10, double(i)));
			num -= (num - (num % int(pow(10, double(i)))));
			if (temp >= base)
			{
				validnum = false;
				break;
			}
		}
	}

	return validnum;
}

/// Changes any integer from base 10 to any base between 2 and 10 inclusive.
/// Returns a -1 if base is not valid.
int changebase(int num, int base)
{
	int basechange = 0, temp = 0, i = 0;

	if ((base < 2) || (base > 10))
		basechange = -1;
	else
	{
		do
		{
			temp = num % base;
			basechange += temp * int(pow(10, double(i)));
			num = (num - temp) / base;

			i++;
		} while (num > 0);
	}

	return basechange;
}