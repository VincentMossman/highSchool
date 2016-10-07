/*  Vincent Mossman
	Initials
	December 4, 2012
	To display initials in a cool way
	*/

#include <iostream>
#include <iomanip>
using namespace std;

void notmain()
{

	//Mr. Reeders stuff
	double a = 4000, b = 20;
	float c = double(b) / double(a);
	cout << c << endl << endl;

	//Me messing around

	int n = 3 + 4;
	int i = 1;
	n = n * n;
	cout << n << endl << endl;

	cout << "Please Enter an Integer: ";
	cin >> n ;
	cout << "Your integer is: " << n << endl << endl;


	//Formatting

	cout << '?' << setw(15) << 34 << '?' << endl << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << '?' << setw(15) << 34 << '?' << endl << endl;

	cout.setf(ios::showpoint | ios::fixed);
	cout << setprecision(2) << 1234.5678 << endl << endl;


	/*

	cout << "     VV        VV  TTTTTTTTTTTT  MMM        MMM" << endl;
	cout << "     VVV      VVV  TTTTTTTTTTTT  MMM        MMM" << endl;
	cout << "      VV      VV        TT       MMMM      MMMM" << endl;
	cout << "      VVV    VVV        TT       MMMM      MMMM" << endl;
	cout << "       VV    VV         TT       MMMMM    MMMMM" << endl;
	cout << "       VVV  VVV         TT       MM MM    MM MM" << endl;
	cout << "        VV  VV          TT       MM MMM  MMM MM" << endl;
	cout << "        VVVVVV          TT       MM  MM  MM  MM" << endl;
	cout << "         VVVV           TT       MM   MMMM   MM" << endl;
	cout << "          VV            TT       MM    MM    MM" << endl << endl << endl;

	*/

		system("pause");
}