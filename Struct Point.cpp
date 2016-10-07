#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
	double x;
	double y;
};

void DisplayPoint(Point &temp);
double Slope(Point pointone, Point pointtwo);
double Distance(Point pointone, Point pointtwo);
Point Reflect(const Point &point);

int mainzz()
{
	Point One;
	Point Two;
	Point Three;

	cout << "Enter the x coordinate for a point: ";
	cin >> One.x;
	cout << "Enter the y coordinate for a point: ";
	cin	>> One.y;

	cout << "Enter the x coordinate for another point: ";
	cin >> Two.x;
	cout << "Enter the y coordinate for another point: ";
	cin	>> Two.y;

	cout << endl << "Your points: " << endl << endl;
	DisplayPoint(One);
	DisplayPoint(Two);
	if (Slope(One, Two) != 3.14159)
		cout << "Slope: " << Slope(One, Two) << endl;
	else
		cout << "Slope: That slope is undefined" << endl;
	cout << "Distance: " << Distance(One, Two) << endl;

	Three = Reflect(One);
	cout << "Point one reflected over the x axis is: ";
	DisplayPoint(Three);
	cout << endl << endl;

	system("pause");

	return 0;
}

void DisplayPoint(Point &temp)
{
	cout << '(' << temp.x << ", " << temp.y << ')' << endl << endl;
}

double Slope(Point pointone, Point pointtwo)
{
	double rise, run;

	rise = pointone.y - pointtwo.y;
	run = pointone.x - pointtwo.x;

	if (!run)
		return 3.14159;
	else
		return (rise / run);
}

double Distance(Point pointone, Point pointtwo)
{
	double distance;

	distance = sqrt(pow((pointone.x - pointtwo.x), 2) + pow((pointone.y - pointtwo.y), 2));

	return distance;
}

Point Reflect(const Point &point)
{
	Point Three;

	Three.x = point.x;
	Three.y = point.y * -1;

	return Three;
}