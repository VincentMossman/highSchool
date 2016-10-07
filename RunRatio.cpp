#include <iostream>
#include <math.h>
#include "Ratio.cpp"
using namespace std;

void mainfieic()
{
	Ratio r, s, t;

	cout << "Enter two fractions: " << endl;
	cin >> r >> s;

	cout << endl;

	t = r + s;

	cout << r << " + " << s << " = " << t << endl << endl;

	t = r - s;

	cout << r << " - " << s << " = " << t << endl << endl;

	t = r / s;

	cout << r << " / " << s << " = " << t << endl << endl;

	t = r * s;

	cout << r << " * " << s << " = " << t << endl << endl;

	Ratio z(t);

	cout << z << endl;

	cout << endl << endl;

	system("pause");
}
