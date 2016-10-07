#include <iostream>
#include <math.h>
using namespace std;

// can't be included in source files

class Ratio
{

	// Function initializations:
	friend Ratio Sum(Ratio x, Ratio y); // Keyword "friend" // Initializes function defined below
	friend Ratio operator+(Ratio x, Ratio y);
	friend Ratio operator-(Ratio x, Ratio y);
	friend Ratio operator*(Ratio, Ratio); // Guess you don't need x and y. LOL.
	friend Ratio operator/(Ratio, Ratio);
	friend istream& operator>>(istream& istr, Ratio& x);
	friend ostream& operator<<(ostream& ostr, Ratio& x);
	friend int gcd(int m, int n);

public:
	// Constructors have to have the name of the class:
	// They're just being initialized here:
	Ratio(int, int den); // Modifier (doesn't have to be in-line) // ITS NOT HERE ANYMORE WTF. It's down farther.
	Ratio(); // Default constuctor
	Ratio(const Ratio&);
	Ratio &operator=(const Ratio &r);
	

	// Class Methods
	void Print() const; // Accessor // Defined below.
	
	Ratio Sum(Ratio y)
	{
		int num = _num * y._den + y._num * _den;
		int den = _den * y._den;
		Ratio temp(num, den);
		return temp;
	}
	Ratio Difference(Ratio other)
	{
		int num = abs(_num * other._den - other._num * _den);
		int den = _den * other._den;
		Ratio temp(num, den);
		return temp;
	}

	// Variables private to the object:
private:
	void reduce(); //THIS
	int _num;
	int _den;
};

// ~~~~~ Constructors and Accessors:
// Don't have to be outside.

Ratio::Ratio(int num, int den): _num(num), _den(den) // <-- Initializer list. Can also be in {} things.
{
	cout << "You have called the constructor function with 2 arguments." << endl;
}

Ratio::Ratio(): _num(0), _den(1)
{
	 cout << "You have called the default constructor." << endl;
}

Ratio::Ratio(const Ratio& r)
{
	_num = r._num;
	_den = r._den;
	
	cout << "You have called the copy constructor." << endl; // LOL
}

// const so it doesn't effect private parts.
void Ratio::Print() const
{
	cout << _num << "/" << _den << endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ratio Sum(Ratio x, Ratio y)
{
	int num = x._num * y._den + y._num * x._den;
	int den = x._den * y._den;
	Ratio temp(num, den);
	return temp;
}

Ratio operator+(Ratio x, Ratio y)
{
	int num = x._num * y._den + y._num * x._den;
	int den = x._den * y._den;
	Ratio temp(num, den);
	temp.reduce(); // And THIS
	return temp;
}

Ratio operator-(Ratio x, Ratio y)
{
	int num = x._num * y._den - y._num * x._den;
	int den = x._den * y._den;
	Ratio temp(num, den);
	temp.reduce();
	return temp;
}

Ratio operator*(Ratio x, Ratio y)
{
	int num = x._num * y._num;
	int den = x._den * y._den;
	Ratio temp(num, den);
	temp.reduce();
	return temp;
}

Ratio operator/(Ratio x, Ratio y)
{
	int num = x._num * y._den;
	int den = x._den * y._num;
	Ratio temp(num, den);
	temp.reduce();
	return temp;
}

istream& operator>>(istream& istr, Ratio& x)
{
	char ch;
	istr >> x._num;
	if (istr.peek() == '/')
		istr >> ch >> x._den;
	else
		x._den = 1;

	return istr;
}

ostream& operator<<(ostream& ostr, Ratio& x)
{
	if (x._den == 1)
		ostr << x._num;
	else
		ostr << x._num << "/" << x._den;

	return ostr;
}

int gcd(int m, int n)
{
	int r;

	if (n > m)
	{
		int temp;
		temp = m;
		m = n;
		n = temp;
	}

	for(;;)
	{
		r = m % n;

		if (r == 0)
			break;

		m = n;
		n = r;
	}

	return n;
}

void Ratio::reduce()
{
	if (_num == 0 || _den == 0)
	{
		_num = 0;
		_den = 1;
		return;
	}

	if (_den < 0)
	{
		_num *= -1;
		_den *= -1;
	}

	int abs_num = (_num < 0 ? -_num : _num); // Check this out LOL. A way to do absolute value with a differnt if statement.
	int g = gcd(abs_num, _den);
	_num /= g;
	_den /= g;
}

Ratio &Ratio::operator=(const Ratio &r)
{
	_num = r._num;
	_den = r._den;


	return *this;
}