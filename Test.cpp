#include <iostream>
using namespace std;

void main()
{
	int years;
	cin >> years;

	if (!((years % 4) && (years % 400)))
	{
		cout << "This is a leap year";
	}
	else
	{
		cout << "This is not a leap year";
	}

	system("pause");
}