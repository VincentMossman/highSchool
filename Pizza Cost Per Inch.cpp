#include <iostream>
using namespace std;
#include <iomanip>

//Public variables and constants:
const double PI = 3.141592654;

//Prototypes:
void GetData(double &cost, int &diameter);
double Square(double diameter);
double Area(int diameter);
double PricePerSqIn(double cost, double area);
void Print(double cost, int diameter, double pricepersquareinch);

void isntmain()
{
	double Main_cost;
	int Main_diameter;

	GetData(Main_cost, Main_diameter);

	Print(Main_cost, Main_diameter, PricePerSqIn(Main_cost, Area(Main_diameter)));

	system("pause");
}

/*Function: GetData
Input: User enters size (diameter) and cost
Output: Returns size and cost (by reference)
*/
void GetData(double &cost, int &diameter)
{
	cout << "Enter the cost of the pizza: ";
	cin >> cost;
	cout << endl << endl;
	cout << "Enter the size of the pizza (diameter in inches): ";
	cin >> diameter;
	cout << endl << endl;
}

/*Function: PricePerSqIn
Input: Takes cost and area (in^2) from GetData function (by value)
Output: Cost per square inch is returned
*/
double PricePerSqIn(double cost, double area)
{
	return cost / area;
}

/*Function: Area
Input: The size of the pizza (diameter) (by value)
Output: Returns the area of the pizza
*/
double Area(int diameter)
{
	double radius = diameter / 2;
	return Square(radius) * PI;
}

/*Function: Square
Input: any value value sent (by value)
Output: the square of the value is returned
*/
double Square(double value)
{
	return value * value;
}

/*Function: Print
Input: Price per square inch
Output: none (just displays stuff)
*/
void Print(double cost, int diameter, double pricepersquareinch)
{
	cout.setf(ios::showpoint | ios::fixed);

	cout << "A pizza that costs $" << setprecision(2) << cost << " and has a" << endl
		<< "diameter of " << diameter << " inches has a " << endl
		<< "cost of $" << pricepersquareinch << " per square inch." << endl << endl;
}