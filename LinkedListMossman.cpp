/// Vincent Mossman
/// Linked Lists - "Graded" - Project
/// May 6, 2013
/// This project creates a primitive student data base utilizing linked list data structure. A message is
///  displayed giving the user options; Create First Student, Add a Student, Remove a Student, Display all Students
///  Display Average GPA for all Students, Display all Students in a Certain Grade, and Quit.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct NODE
{
	string firstname, lastname;
	int studentnum, grade;
	double gpa;
	NODE *next;
};

/// Function Declarations
void DisplayMenu();
void CreateFirstStudent(NODE*&);
void AddAStudent(NODE*&);
void DisplayAllStudents(NODE*&);
void RunMenu(NODE*&);
void RemoveAStudent(NODE*&);
void DisplayAverageGPA(NODE*&);
void DisplayAllStudentsInACertainGrade(NODE*&);
void Quit();

void main()
{
	NODE *HeadPtr(NULL);

	for(;;) { DisplayMenu(); RunMenu(HeadPtr); }
}

/// Displays a nice menu for the user to choose from. No arguments.
void DisplayMenu()
{
	system("cls");

	cout << endl << "\t************************************************************" << 
		endl << "\t************************************************************" <<
		endl << "\t*****                                                  *****" <<
		endl << "\t*****   1.)  Create First Student                      *****" <<
		endl << "\t*****   2.)  Add a Student                             *****" <<
		endl << "\t*****   3.)  Remove a Student                          *****" <<
		endl << "\t*****   4.)  Display all Students                      *****" <<
		endl << "\t*****   5.)  Display Average GPA for all Students      *****" <<
		endl << "\t*****   6.)  Display all Students in a Certain Grade   *****" <<
		endl << "\t*****   7.)  Quit                                      *****" <<
		endl << "\t*****                                                  *****" <<
		endl << "\t************************************************************" <<
		endl << "\t************************************************************" <<
		endl << endl;
}

/// Contains the input code to run the menu effectively
/// Must pass Head Pointer so function can get access to the other functions
void RunMenu(NODE*& HeadPtr)
{
	int UserChoice(0);

	cout << endl << "\tPlease enter your choice: ";
	cin >> UserChoice;

	switch(UserChoice)
	{
	case 1: { CreateFirstStudent(HeadPtr); system("pause"); break; }
	case 2: { AddAStudent(HeadPtr); system("pause"); break; }
	case 3: { RemoveAStudent(HeadPtr); system("pause"); break; }
	case 4: { DisplayAllStudents(HeadPtr); system("pause"); break; }
	case 5: { DisplayAverageGPA(HeadPtr); system("pause"); break; }
	case 6: { DisplayAllStudentsInACertainGrade(HeadPtr); system("pause"); break; }
	case 7: { Quit(); break; }
	default: { cout << endl << endl << "\tThat choice is not valid." << endl << endl; system("pause"); }
	}
}

/// Must pass the function the head pointer so the function can check to see if it is already instantiated
///  as a safe guard against losing the correct head pointer or to instantiate a populated version if need be
/// Creates a new student with user entered data and returns its pointer
void CreateFirstStudent(NODE*& HeadPtr)
{	
	system("cls");

	cout << endl << "\t-- Create First Student --" << endl << endl;

	if(HeadPtr)
		cout << "\tYou have already created the first student." << endl;
	else
	{
		HeadPtr = new NODE;
		HeadPtr -> next = NULL;
	
		cout << endl << "\tEnter student's first name: ";
		cin >> HeadPtr -> firstname;
		cout << "\tEnter student's last name: ";
		cin >> HeadPtr -> lastname;
		cout << "\tEnter student's ID number: ";
		cin >> HeadPtr -> studentnum;
		cout << "\tEnter student's GPA: ";
		cin >> HeadPtr -> gpa;
		cout << "\tEnter student's grade: ";
		cin >> HeadPtr -> grade;
		while(HeadPtr -> grade < 9 || HeadPtr -> grade > 12)
		{
			cout << "\tPlease enter a grade between 9 and 12: ";
			cin >> HeadPtr -> grade;
		}
	}

	cout << endl << endl;
}

/// Must pass the head pointer so the function can access the list
/// Displays all of the students and their information in a nice output
void DisplayAllStudents(NODE*& HeadPtr)
{
	NODE *TempPtr = HeadPtr;
	cout.setf(ios::showpoint | ios::fixed);

	system("cls");

	cout << endl << "\t-- Complete Student Database --" << endl << endl;

	cout << endl << "\tID Number\tFirst Name\tLast Name\tGPA\tGrade" << endl << endl;

	if(!TempPtr)
		cout << "\tThere are no students currently in the database." << endl << endl;
	else
	{
		while(TempPtr)
		{
			string tempfirstname(TempPtr -> firstname), templastname(TempPtr -> lastname);
			tempfirstname.resize(7); // resize. Member of the string class.
			templastname.resize(7);

			cout << '\t' << TempPtr -> studentnum << "\t\t" << tempfirstname << "\t\t" << templastname <<
				"\t\t" << setprecision(3) << TempPtr -> gpa << '\t' << TempPtr -> grade << endl;
			TempPtr = TempPtr -> next;
		}
		cout << endl << endl << "\t  ~ Please Note: Students are organized by Student ID Number." << endl;
		cout << "\t    Full names may not be shown to prevent formatting issues." << endl << endl;
	}
	
	cout << endl;
}

/// Must pass the function the head pointer so the function can access the list
/// Adds a student in the correct location in the list (based on student num)
void AddAStudent(NODE*& HeadPtr)
{
	system("cls");
	cout << endl << "\t-- Add a Student --" << endl << endl;

	if(!HeadPtr)
		cout << endl << "\tYou have not created the first student yet." << endl;
	else
	{
		NODE *CurrentPtr, *PreviousPtr, *TempPtr;
		CurrentPtr = HeadPtr;

		TempPtr = new NODE;
		TempPtr -> next = NULL;

		cout << endl << "\tEnter student's first name: ";
		cin >> TempPtr -> firstname;
		cout << "\tEnter student's last name: ";
		cin >> TempPtr -> lastname;
		cout << "\tEnter student's ID number: ";
		cin >> TempPtr -> studentnum;
		cout << "\tEnter student's GPA: ";
		cin >> TempPtr -> gpa;
		cout << "\tEnter student's grade: ";
		cin >> TempPtr -> grade;
		while(TempPtr -> grade < 9 || TempPtr -> grade > 12)
		{
			cout << "\tPlease enter a grade between 9 and 12: ";
			cin >> TempPtr -> grade;
		}

		if(TempPtr -> studentnum <= CurrentPtr -> studentnum)
		{
			TempPtr -> next = HeadPtr;
			HeadPtr = TempPtr;
		}
		else
		{
			PreviousPtr = CurrentPtr;
			CurrentPtr = CurrentPtr -> next;

			while(CurrentPtr)
			{
				if(TempPtr -> studentnum <= CurrentPtr -> studentnum)
				{
					PreviousPtr -> next = TempPtr;
					TempPtr -> next = CurrentPtr;
					break;
				}

				PreviousPtr = PreviousPtr -> next;
				CurrentPtr = CurrentPtr -> next;
			}

			if(!CurrentPtr)
				PreviousPtr -> next = TempPtr;
		}
	}

	cout << endl << endl;
}

/// Must pass the function the head pointer so the function can access the list
/// Removes a student without damaging the rest of the list
void RemoveAStudent(NODE*& HeadPtr)
{
	system("cls");
	cout << endl << "\t-- Remove a Student --" << endl << endl;

	if(!HeadPtr)
		cout << endl << "\tThere are no students in the database." << endl;
	else
	{
		NODE *CurrentPtr, *PreviousPtr;
		int UserChoice;
		CurrentPtr = HeadPtr;

		cout << endl << "\tEnter the ID Number of the student you want to remove: ";
		cin >> UserChoice;

		if(UserChoice == CurrentPtr -> studentnum)
		{
			cout << endl << "\tStudent " << CurrentPtr -> studentnum << " - " << CurrentPtr -> firstname
				<< " " << CurrentPtr -> lastname << " has been removed." << endl << endl;
			HeadPtr = HeadPtr -> next;
		}
		else
		{
			PreviousPtr = CurrentPtr;
			CurrentPtr = CurrentPtr -> next;

			while(CurrentPtr)
			{
				if(UserChoice == CurrentPtr -> studentnum)
				{
					cout << endl << "\tStudent " << CurrentPtr -> studentnum << " - " << CurrentPtr -> firstname
						<< " " << CurrentPtr -> lastname << " has been removed." << endl;
					PreviousPtr -> next = CurrentPtr -> next;
					break;
				}

				PreviousPtr = PreviousPtr -> next;
				CurrentPtr = CurrentPtr -> next;
			}

			if(!CurrentPtr)
				cout << endl << "\tThere is no student with that ID Number" << endl;
		}
	}

	cout << endl << endl;
}

/// Must pass the function the head pointer so the function can access the list
/// Displays mean GPA of all students in the list
void DisplayAverageGPA(NODE*& HeadPtr)
{
	NODE *TempPtr = HeadPtr;
	double gpasum(0);
	int i(0);
	system("cls");
	cout.setf(ios::showpoint | ios::fixed);
	cout << endl << "\t-- Average GPA for all Students --" << endl << endl;

	if(!TempPtr)
		cout << endl << "\tThere are no students currently in the database." << endl << endl;
	else
	{
		while(TempPtr)
		{
			gpasum += TempPtr -> gpa;
			TempPtr = TempPtr -> next;
			i++;
		}
		gpasum /= i;
		cout << endl << "\tAverage GPA: " << setprecision(3) << gpasum << endl << endl;
	}

	cout << endl;
}

/// Must pass the function the head pointer so the function can access the list
/// Displays all students in a user defined grade
void DisplayAllStudentsInACertainGrade(NODE*& HeadPtr)
{
	NODE *TempPtr = HeadPtr;
	int UserChoice;
	cout.setf(ios::showpoint | ios::fixed);

	system("cls");

	cout << endl << "\tPlease enter the grade you want displayed: ";
	cin >> UserChoice;

	cout << endl << endl << "\t-- All Students in Grade " << UserChoice << " --" << endl << endl;

	cout << endl << "\tID Number\tFirst Name\tLast Name\tGPA" << endl << endl;

	if(!TempPtr)
		cout << "\tThere are no students currently in the database." << endl << endl;
	else
	{
		while(TempPtr && TempPtr -> grade == UserChoice)
		{
			string tempfirstname(TempPtr -> firstname), templastname(TempPtr -> lastname);
			tempfirstname.resize(7); // resize. Member of the string class.
			templastname.resize(7);

			cout << '\t' << TempPtr -> studentnum << "\t\t" << tempfirstname << "\t\t" << templastname <<
				"\t\t" << setprecision(3) << TempPtr -> gpa << endl;
			TempPtr = TempPtr -> next;
		}
		cout << endl << endl << "\t  ~ Please Note: Students are organized by Student ID Number." << endl;
		cout << "\t    Full names may not be shown to prevent formatting issues." << endl << endl;
	}
	
	cout << endl;
}

/// If user is sure they want to exit, teminates the program, else nothing
void Quit()
{
	char UserChoice;
	system("cls");
	cout << endl << endl << "\tAre you sure you want to quit? (y/n) ";
	cin >> UserChoice;

	if(UserChoice == 'y' || UserChoice == 'Y')
		exit(0);
}
