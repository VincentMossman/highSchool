/*  Vincent Mossman
	Book Prices
	December 7, 2012
	*/

#include <iostream>
#include <iomanip>
using namespace std;

void notmainlol()
{
	double MathText, BiologyText, ComputerScienceText, Total, Average;
	MathText = 23.95;
	BiologyText = 27.50;
	ComputerScienceText = 19.95;
	Total = MathText + BiologyText + ComputerScienceText;
	Average =  Total / 3;

	cout.setf(ios::showpoint | ios::fixed);

	cout.setf(ios::left, ios::adjustfield);
	cout << "Text" << setw(15);
	cout.setf(ios::right, ios::adjustfield);
	cout << "Price" << endl << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << "Math" << setw(11);
	cout.setf(ios::right, ios::adjustfield);
	cout << '$' << setprecision(2) << MathText << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << "Biology" << setw(8);
	cout.setf(ios::right, ios::adjustfield);
	cout << '$' << setprecision(2) << BiologyText << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << "Comp. Sci." << setw(5);
	cout.setf(ios::right, ios::adjustfield);
	cout << '$' << setprecision(2) << ComputerScienceText << endl << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	cout << "Total:" << setw(9) << setprecision(2) << '$' << Total << endl;
	cout << "Average:" << setw(7) << setprecision(2) << '$' << Average << endl << endl << endl << endl;

	system("Pause");
}

