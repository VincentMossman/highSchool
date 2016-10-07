#include <iostream>
using namespace std;

void swap(double*&, double*&);
double *GrabMemory();

void maintilt()
{
	double *s;

	s = GrabMemory();

	cout << s << endl;
	cout << *s << endl;

	cout << endl << endl;

	system("pause");


	/*
	char test, *ptest = &test;

	if (test == NULL)
		cout << "yeah" << endl;

	system("pause");
	*/

	/*
	int *y = new int;
	if(!y)
		cout << "No memory available." << endl;

	cout << endl << endl;
	system("pause");
	*/

	/*
	int *t(new int), n(100), *s;
	*t = n; // Address of t contains a copy of n
	s = &n;
	cout << "Pointer 't' is pointing to address: " << t << endl;
	cout << "t's address contains: " << *t << endl;
	cout << "Pointer 's' is pointing to address: " << s << endl;
	cout << "s's address contains: " << *s << endl;

	cout << endl;

	system("pause");
	*/

	/*
	int n(100), *p;
	p = new int;
	p = &n;
	cout << p << endl;

	system("pause");
	*/

	/*
	int *ptr, n(5);
	ptr = &n;

	if(!ptr)
		cout << "The pointer is pointing to NULL." << endl;
	else
		cout << "The pointer is pointing to a value: " << *ptr << endl;

	cout << endl << endl;

	system("pause");
	*/

	/*
	double x = 3.24, y = 5.78;
	cout << x << '\t' << y << endl;

	double *px = &x, *py = &y; 

	swap(px, py);
	cout << *px << '\t' << *py << endl;
	
	cout << endl << endl;
	system("pause");
	*/

	/*
	char aVar = 'A', bVar = 'B';
	char *p = &aVar;

	cout << *p << endl << endl;

	p = &bVar;

	cout << *p << endl << endl;

	*p = 'Z';

	cout << *p << endl << endl;
	cout << bVar << endl << endl;

	char *q = p;
	
	cout << *p << endl << endl;
	cout << *q << endl << endl;


	system("pause");
	*/
}

void swap(double*& px, double*& py)
{
	double *temp;
	temp = px;
	px = py;
	py = temp;
}

double *GrabMemory()
{
	double n = 3.24;
	double* p;
	p = new double;

	p = &n;

	cout << p << endl;
	cout << *p << endl;

	return p;
}