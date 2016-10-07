/*  Vincent Mossman
	Employee Payroll
	January 21, 2013
	User enters number of hours worked for an employee as well as the number of dependents this 
		employee has and a pay statement is generated.
	*/

#include <iostream>
using namespace std;
#include <iomanip>
#include <math.h>

//Constants:
const double HOURLY_RATE = 16.78, OVERTIME_RATE = 1.5;
const double SS_TAX = 0.06, FED_INCOME_TAX = 0.14, STA_INCOME_TAX = 0.05;
const double UNION_DUES = 10.00, HEAL_INSUR = 35.00;

//Prototypes:
void LoadEntryLayout();
int GetDependents();
double GetHours();
bool CheckDependentCharge(int dependents);
double GrossPay(double hours);
double CalcSSTax(double gross_pay);
double CalcFedIncTax(double gross_pay);
double CalcStaIncTax(double gross_pay);
void LoadFinalDisplay(double hours, int dependents, double gross_pay, double ss_tax, double fed_inc_tax, 
	double sta_inc_tax);

void main()
{
	//Useful variables:
	double hours;
	int dependents;
	double gross_pay;
	double ss_tax, fed_inc_tax, sta_inc_tax;

	LoadEntryLayout();

	hours = GetHours();
	dependents = GetDependents();
	gross_pay = GrossPay(hours);
	ss_tax = CalcSSTax(gross_pay);
	fed_inc_tax = CalcFedIncTax(gross_pay);
	sta_inc_tax = CalcStaIncTax(gross_pay);
		
	LoadFinalDisplay(hours, dependents, gross_pay, ss_tax, fed_inc_tax, sta_inc_tax);

	system("pause");
}

//Pre-con: None
//Post-con: Handles the data entry layout
void LoadEntryLayout()
{
	//WIDTH: 71

	cout << endl << "***************************     PAYROLL     ***************************" << endl << endl;

	cout.setf(ios::right, ios::adjustfield);
	cout << setw(29) << "PLEASE NOTE:" << endl << setw(71) << "*Any hours entered over 40 will be considered overtime."
		<< endl << setw(68) << "*Also, employees with 3 or more dependents will have" << endl 
		<< setw(64) << "an extra deduction to cover the cost of" << endl
		<< setw(42) << "health insurance."
		<< endl << endl << endl;
}

//Pre-con: Function accepts integer variable
//Post-con: Function returns integer
//Other: Function will check for invalid data entry (such as a double) and notify the user
int GetDependents()
{
	double dependents;
	
	cout << "Please enter number of dependents: ";
	cin >> dependents;
	cout << endl;

	//Will check for valid entry and gives user another chance to enter good data:
	while ((fmod(dependents, 1) != 0) || (dependents < 0))
	{
		if (fmod(dependents, 1) != 0)
		{
			cout << "You can not have fractions of people. Please enter a valid number: ";
			cin >> dependents;
			cout << endl;
		}
		else if (dependents < 0)
		{
			cout << "You can not have less than zero dependents. Please enter a valid number: ";
			cin >> dependents;
			cout << endl;
		}
	}

	return int(dependents);
}

//Pre-con: Function accepts double variable
//Post-con: Function returns double variable
//Other: Function will check for invalid data entry and notify the user
double GetHours()
{
	double hours;

	cout << "Please enter the number of hours worked: ";
	cin >> hours;
	cout << endl;

	while ((hours < 0) || (hours > 168))
	{
		if (hours < 0)
		{
			cout << "You can not work less than zero hours. Please enter a valid number: ";
			cin >> hours;
			cout << endl;
		}
		else if (hours > 168)
		{
			cout << "There are 168 hours in a week. Please enter a valid number: ";
			cin >> hours;
			cout << endl;
		}
	}

	return hours;
}

//Pre-con: Function accepts int number of dependents from main
//Post-con: Returns boolean weather the number is equal to or greater than three
bool CheckDependentCharge(int dependents)
{
	bool OverThree;

	if (dependents >= 3)
	{
		OverThree = true;
	}
	else
	{
		OverThree = false;
	}

	return OverThree;
}

//Pre-con: Function accepts double num of hours
//Post-con: Returns gross pay as a double
double GrossPay(double hours)
{
	double regular_hours;
	double overtime_hours;
	double gross_pay;

	if (hours > 40)
	{
		overtime_hours = hours - 40;
		regular_hours = 40;
	}
	else
	{
		regular_hours = hours;
	}
	
	gross_pay = ((regular_hours * HOURLY_RATE) + (overtime_hours * HOURLY_RATE * OVERTIME_RATE));

	return gross_pay;
}

//Pre-con: Function accepts double gross pay
//Post-con: Returns SS tax withholding
double CalcSSTax(double gross_pay)
{
	double ss_tax;

	ss_tax = (SS_TAX * gross_pay);

	return ss_tax;
}

//Pre-con: Function accepts double gross pay
//Post-con: Function returns Federal Income Tax withholding
double CalcFedIncTax(double gross_pay)
{
	double fed_inc_tax;

	fed_inc_tax = (FED_INCOME_TAX * gross_pay);

	return fed_inc_tax;
}

//Pre-con: Function accepts double gross pay
//Post-con: Function returns State Income Tax withholding
double CalcStaIncTax(double gross_pay)
{
	double sta_inc_tax;

	sta_inc_tax = (STA_INCOME_TAX * gross_pay);

	return sta_inc_tax;
}

//Pre-con: Function accepts all calculated data
//Post-con: Displays all data neatly
void LoadFinalDisplay(double hours, int dependents, double gross_pay, double ss_tax, double fed_inc_tax, 
	double sta_inc_tax)
{
	//Width: 60

	cout.setf(ios::showpoint | ios::fixed);
	bool health_insurance;
	double net_pay;
	
	//Checks if there are three or more dependents:
	health_insurance = CheckDependentCharge(dependents);

	system("CLS");

	cout << endl << "*****   STATEMENT OF EARNINGS, TAXES, AND DEDUCTIONS   *****" << endl << endl << endl;
	cout << "\tDescription\t\tValue" << endl;
	cout << "\t-----------\t\t-----\t" << endl;
	cout << "\tGross Pay\t\t" << setprecision(2) << gross_pay << "\t(" << hours << " hours)" << endl << endl;
	cout << "\tSocial Security\t\t" << '-' << ss_tax << endl;
	cout << "\tIncome Tax (Federal)\t" << '-' << fed_inc_tax << endl;
	cout << "\tIncome Tax (State)\t" << '-' << sta_inc_tax << endl;
	cout << "\tUnion Dues\t\t" << '-' << UNION_DUES << endl;
	if (health_insurance == true)
	{
		cout << "\tHealth Insurance\t" << '-' << HEAL_INSUR << '\t' << '(' << dependents << " dependents)" << endl;
		net_pay = gross_pay - (ss_tax + fed_inc_tax + sta_inc_tax + UNION_DUES + HEAL_INSUR);
		cout << endl << endl << "\tNet Pay\t\t" << "\t$" << net_pay;
	}
	else
	{
		cout << "\tHealth Insurance\t" << "N/A" << '\t' << '(' << dependents << " dependents)" << endl;
		net_pay = gross_pay - (ss_tax + fed_inc_tax + sta_inc_tax + UNION_DUES);
		cout << endl << endl << "\tNet Pay\t\t" << "\t$" << net_pay;
	}
	cout << endl << endl << endl << "************************************************************" << endl << endl;
}