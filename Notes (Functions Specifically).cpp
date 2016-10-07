/* 
A good program is broken into smaller pieces that perform simple tasks as compared to the whole problem. 
A module is code written to perform one well-defined task.

Function declaration is also called a function prototype.
Functions have to have a return type or void.
Function headings are the actual function blocks of code.
*/



#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int NumberSquared(int SUB_num); //Function declaration (function prototype)
int NumberCubed(int SUB_num);
void PrintOutput(int SUB_Num, int SUB_Square, int SUB_Cube);

void notmainlulul()
{
	int _num, _num_squared, _num_cubed;

	cout << "Please enter an integer: ";
	cin >> _num;

	_num_squared = NumberSquared(_num);
	_num_cubed = NumberCubed(_num);
	PrintOutput(_num, _num_squared, _num_cubed);

	system("pause");

}

/***********************************************************************
Pre-Condition: Function accepts a number from main
Post-Condition: Returns the number squared */
int NumberSquared(int SUB_num)
{
	return pow(double(SUB_num), 2.00);
}

//***********************************************************************//

/************************************************************************
Pre-Condition: Function accepts a number from main
Post-Condition: Returns the number cubed */
int NumberCubed(int SUB_num)
{
	return pow(double(SUB_num), 3.00);
}

//***********************************************************************//

/************************************************************************
Pre-Condition: Function takes in no values
Post-Condition: Displays erthang */
void PrintOutput(int SUB_Num, int SUB_Square, int SUB_Cube)
{
	cout << SUB_Num << " squared is " << SUB_Square << "." << endl << "And " << SUB_Num << " cubed is "
		<< SUB_Cube << "." << endl << endl;
}

//***********************************************************************//