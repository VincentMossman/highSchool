/*  Vincent Mossman
	Fraction Action
	January 27, 2013
	Adds, Subtracts, Multiplys, or Divides two fractions
	*/

#include <iostream>
#include <iomanip>
using namespace std;

//Prototypes:
void InfoLoad();
void GetFractions(int &numerator1, int &denominator1, int &numerator2, int &denominator2);
char Menu();
void AddFractions(int numerator1, int denominator1, int numerator2, int denominator2);
void SubtractFractions(int numerator1, int denominator1, int numerator2, int denominator2);
void MultiplyFractions(int numerator1, int denominator1, int numerator2, int denominator2);
void DivideFractions(int numerator1, int denominator1, int numerator2, int denominator2);

void main()
{
	char UserChoice; // A = Add, B = Subtract, C = Multiply, D = Divide, E = Exit

	int numerator1, denominator1, numerator2, denominator2;

	InfoLoad();
	GetFractions(numerator1, denominator1, numerator2, denominator2);

	do 
	{
		UserChoice = Menu();

		if ((UserChoice == 'A') || (UserChoice == 'a'))
		{
			AddFractions(numerator1, denominator1, numerator2, denominator2);
			system("pause");
		}
		else if ((UserChoice == 'B') || (UserChoice == 'b'))
		{
			SubtractFractions(numerator1, denominator1, numerator2, denominator2);
			system("pause");
		}
		else if ((UserChoice == 'C') || (UserChoice == 'c'))
		{
			MultiplyFractions(numerator1, denominator1, numerator2, denominator2);
			system("pause");
		}
		else if ((UserChoice == 'D') || (UserChoice == 'd'))
		{
			DivideFractions(numerator1, denominator1, numerator2, denominator2);
			system("pause");
		}
		
		system("CLS");
	} while (!((UserChoice == 'E') || (UserChoice == 'e')));

	system("exit");
}


//Pre-con: None
//Post-con: Displays basic information
void InfoLoad()
{
	cout << endl << "Fraction Calculator" << endl << "Version 1.0" << endl << "By: Vincent Mossman" << endl << endl 
		<< endl;
}

//Pre-con: Accepts four integer variables that represent fractions byref 
//Post-con: Returns four integer variables that represent fractions byref
//Other: Doesn't let user enter 0 for a denominator
void GetFractions(int &numerator1, int &denominator1, int &numerator2, int &denominator2)
{
	//Get first fraction:
	cout << "Please enter the NUMERATOR for your FIRST fraction: ";
	cin >> numerator1;
	cout << "Please enter the DENOMINATOR for your FIRST fraction: ";
	cin >> denominator1;
	while (denominator1 == 0)
	{
		cout << "Zero is not a valid denominator. Please enter a non-zero number: ";
		cin >> denominator1;
	}

	//Get second fraction:
	cout << endl << "Please enter the NUMERATOR for your SECOND fraction: ";
	cin >> numerator2;
	cout << "Please enter the DENOMINATOR for your SECOND fraction: ";
	cin >> denominator2;
	while (denominator2 == 0)
	{
		cout << "Zero is not a valid denominator. Please enter a non-zero number: ";
		cin >> denominator2;
	}
}

//Pre-con: None
//Post-con: Outputs a menu with the five options
//Other: Forces user to enter a valid choice
char Menu()
{
	char UserChoice;

	for (int Tries = 0; (UserChoice != 'A') && (UserChoice != 'a') && (UserChoice != 'B') && (UserChoice != 'b')
		&& (UserChoice != 'C') && (UserChoice != 'c') && (UserChoice != 'D') && (UserChoice != 'd')
		&& (UserChoice != 'E') && (UserChoice != 'e'); Tries++)
	{
		system("CLS");

		cout << endl << "\t************************************************" << endl;
		cout << "\t*****           Select an Option           *****" << endl;
		cout << "\t*****                                      *****" << endl;
		cout << "\t*****	A.) Add the two fractions          *****" << endl;
		cout << "\t*****	B.) Subtract the two fractions     *****" << endl;
		cout << "\t*****	C.) Multiply the two fractions     *****" << endl;
		cout << "\t*****	D.) Divide the two fractions       *****" << endl;
		cout << "\t*****	E.) Quit                           *****" << endl;
		cout << "\t*****                                      *****" << endl;
		cout << "\t************************************************" << endl;
		cout << endl << endl;
		if (Tries > 0)
		{
			cout << "WARNING: '" << UserChoice << "' is not a valid choice." << endl;
		}
		cout << "Enter your choice (A, B, C, D, or E): ";
		cin >> UserChoice;
	}

	return UserChoice;
}

//Pre-con: Function accepts four integer variables
//Post-con: Function displays addition of two fractions
void AddFractions(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int FinalNumerator, FinalDenominator;

	if (denominator1 == denominator2)
	{
		FinalNumerator = numerator1 + numerator2;
		FinalDenominator = denominator1;
	}
	else
	{
		FinalNumerator = (numerator1 * denominator2) + (numerator2 * denominator1);
		FinalDenominator = denominator1 * denominator2;
	}

	cout << endl << endl;
	cout << '\t' << numerator1 << '\t' << numerator2 << '\t' << FinalNumerator << endl;
	cout << "       ---  +  ---  =  ---" << endl;
	cout << '\t' << denominator1 << '\t' << denominator2 << '\t' << FinalDenominator << endl << endl;
}

//Pre-con: Function accepts four integer variables
//Post-con: Function displays subtraction of two fractions
void SubtractFractions(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int FinalNumerator, FinalDenominator;

	if (denominator1 == denominator2)
	{
		FinalNumerator = numerator1 - numerator2;
		FinalDenominator = denominator1;
	}
	else
	{
		FinalNumerator = (numerator1 * denominator2) - (numerator2 * denominator1);
		FinalDenominator = denominator1 * denominator2;
	}

	cout << endl << endl;
	cout << '\t' << numerator1 << '\t' << numerator2 << '\t' << FinalNumerator << endl;
	cout << "       ---  -  ---  =  ---" << endl;
	cout << '\t' << denominator1 << '\t' << denominator2 << '\t' << FinalDenominator << endl << endl;
}

//Pre-con: Function accepts four integer variables
//Post-con: Function displays multiplication of two fractions
void MultiplyFractions(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int FinalNumerator, FinalDenominator;

	FinalNumerator = numerator1 * numerator2;
	FinalDenominator = denominator1 * denominator2;

	cout << endl << endl;
	cout << '\t' << numerator1 << '\t' << numerator2 << '\t' << FinalNumerator << endl;
	cout << "       ---  *  ---  =  ---" << endl;
	cout << '\t' << denominator1 << '\t' << denominator2 << '\t' << FinalDenominator << endl << endl;
}

//Pre-con: Function accepts four integer variables
//Post-con: Function displays division of two fractions
void DivideFractions(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int FinalNumerator, FinalDenominator;


	FinalNumerator = numerator1 * denominator2;
	FinalDenominator = denominator1 * numerator2;

	cout << endl << endl;
	cout << '\t' << numerator1 << '\t' << numerator2 << '\t' << FinalNumerator << endl;
	cout << "       ---  /  ---  =  ---" << endl;
	cout << '\t' << denominator1 << '\t' << denominator2 << '\t' << FinalDenominator << endl << endl;
}