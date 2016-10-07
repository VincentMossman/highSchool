/*

#include <iostream>
#include <string>
using namespace std;

// Use a display function next time lol

struct NODE
{
	string name;
	int age;
	NODE *Next;
};

void AddToFront(NODE*&);
void AddToEnd(NODE*&);
void AddToMiddle(NODE*&);
void Remove(NODE*&);

void mainfiller()
{
	// Don't change the head pointer. lol

	NODE *HeadPtr, *CurrentPtr, *TempPtr;

	HeadPtr = new NODE;
	HeadPtr -> Next = NULL;
	cout << "Enter a name: ";
	cin >> HeadPtr -> name;
	cout << "Enter an age: ";
	cin >> HeadPtr -> age;

	CurrentPtr = HeadPtr;

	for(int k = 0; k < 2; k++)
	{
		TempPtr = new NODE;
		CurrentPtr -> Next = TempPtr;
		CurrentPtr = CurrentPtr -> Next;
		CurrentPtr -> Next = NULL;

		cout << "Enter a name: ";
		cin >> CurrentPtr -> name;
		cout << "Enter an age: ";
		cin >> CurrentPtr -> age;
	}

	CurrentPtr = HeadPtr;

	while(CurrentPtr != NULL)
	{
		cout << CurrentPtr -> name << "  " << CurrentPtr -> age << endl;
		CurrentPtr = CurrentPtr -> Next;
	}

	AddToFront(HeadPtr);
	CurrentPtr = HeadPtr;

	while(CurrentPtr != NULL)
	{
		cout << CurrentPtr -> name << "  " << CurrentPtr -> age << endl;
		CurrentPtr = CurrentPtr -> Next;
	}

	AddToEnd(HeadPtr);
	CurrentPtr = HeadPtr;

	while(CurrentPtr != NULL)
	{
		cout << CurrentPtr -> name << "  " << CurrentPtr -> age << endl;
		CurrentPtr = CurrentPtr -> Next;
	}

	AddToMiddle(HeadPtr);
	CurrentPtr = HeadPtr;

	while(CurrentPtr != NULL)
	{
		cout << CurrentPtr -> name << "  " << CurrentPtr -> age << endl;
		CurrentPtr = CurrentPtr -> Next;
	}

	Remove(HeadPtr);
	CurrentPtr = HeadPtr;

	while(CurrentPtr != NULL)
	{
		cout << CurrentPtr -> name << "  " << CurrentPtr -> age << endl;
		CurrentPtr = CurrentPtr -> Next;
	}
	
	cout << endl << endl;
	system("pause");
}

void AddToFront(NODE*& HP)
{
	NODE *CurrentPtr;

	for(int k = 0; k < 1; k++)
	{
		CurrentPtr = new NODE;
		CurrentPtr -> Next = HP;
		HP = CurrentPtr;

		cout << "Enter a name: ";
		cin >> CurrentPtr -> name;
		cout << "Enter an age: ";
		cin >> CurrentPtr -> age;
	}
}

void AddToEnd(NODE*& HP)
{
	NODE *CurrentPtr, *TempPtr;

	CurrentPtr = HP;

	while(CurrentPtr -> Next != NULL)
		CurrentPtr = CurrentPtr -> Next;

	for(int k = 0; k < 1; k++)
	{
		TempPtr = new NODE;
		CurrentPtr -> Next = TempPtr;
		CurrentPtr = CurrentPtr -> Next;
		CurrentPtr -> Next = NULL;

		cout << "Enter a name: ";
		cin >> CurrentPtr -> name;
		cout << "Enter an age: ";
		cin >> CurrentPtr -> age;
	}

}

void AddToMiddle(NODE*& HP)
{
	NODE *CurrentPointer, *TempPointer, *PreviousPointer;
	int num;

	PreviousPointer = HP;
	CurrentPointer = PreviousPointer -> Next;

	cout << "You are about to enter a number in the middle of the list." << endl;
	cout << "What age would you like to enter this person before? (lol)  ";
	cin >> num;

	while(CurrentPointer != NULL)
	{
		if(CurrentPointer -> age != num)
		{
			CurrentPointer = CurrentPointer -> Next;
			PreviousPointer = PreviousPointer -> Next;
		}
		else
			break;
	}

	if(CurrentPointer == NULL)
		cout << "The number is not in the list." << endl;
	else
	{
		TempPointer = new NODE;
		TempPointer -> Next = NULL;

		cout << "Enter a name: ";
		cin >> TempPointer -> name;
		cout << "Enter an age: ";
		cin >> TempPointer -> age;

		TempPointer -> Next = CurrentPointer;
		PreviousPointer -> Next = TempPointer;
	}
}

void Remove(NODE*& HP)
{
	NODE *PP, *CP; //*PreviousPointer, *CurrentPointer
	int target;

	while(CP != NULL)
	{
		cout << CP -> name << "  " << CP -> age << endl;
		CP = CP -> Next;
	}

	cout << "Which aged person do you want to delete? ";
	cin >> target;

	PP = HP;
	CP = HP -> Next;

	if(HP -> age == target)
		HP = CP;

	while(CP -> age != target && CP -> Next != NULL)
	{
		CP = CP -> Next;
		PP = PP -> Next;
	}

	if(CP -> Next == NULL && CP -> age == target)
		PP -> Next = NULL;

	if(CP -> age == target)
		PP -> Next = CP -> Next;

	if(CP -> Next == NULL && CP -> age != target)
		cout << target << " is not the age of any person in the list." << endl;
}

*/