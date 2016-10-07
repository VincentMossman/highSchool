#include <iostream>
using namespace std;

int Area(int &SUB_length, int &SUB_width);
int GetData(int &SUBLength, int &SUBWidth);

void main()
{
	int MainLength, MainWidth, MainArea;

	GetData(MainLength, MainWidth);
	MainArea = Area(MainLength, MainWidth);

	cout << "The area is: " << MainArea << endl << endl;

	system("Pause");

}

//Pre-con: function takes in the length and width of a rectangle from main
//Post-con: function returns the area of the rectngle
int Area(int &SUB_length, int &SUB_width)
{
	int Product;

	Product = SUB_length * SUB_width;

	return Product;
}

int GetData(int &SUBLength, int &SUBWidth)
{
	cout << "Enter the length of a rectangle: ";
	cin >> SUBLength;
	cout << "Enter the width of a rectangle: ";
	cin >> SUBWidth;

	return 0;
}
