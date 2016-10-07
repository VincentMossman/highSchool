#include <iostream>
using namespace std;

/* Overloading:
	Type
	Number
*/

void Swap( int &x, int &y);
void Swap(double &x, double &y);
void Swap( int &x, int &y, int &z);

void nonomain()
{
	int a = 1, b = 2, c = 3;
	double d = 2.3, e = 4.5;
	
	cout << a << " " << b << endl << endl;
	Swap(a, b);
	cout << a << " " << b << endl << endl;

	cout << d << " " << e << endl << endl;
	Swap(d, e);
	cout << d << " " << e << endl << endl;

	cout << a << " " << b << " " << c << endl << endl;
	Swap(a, b, c);
	cout << a << " " << b << " " << c << endl << endl;

	system("pause");
}


void Swap( int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void Swap(double &x, double &y)
{
	double temp;
	temp = x;
	x = y;
	y = temp;
}

void Swap( int &x, int &y, int &z)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
