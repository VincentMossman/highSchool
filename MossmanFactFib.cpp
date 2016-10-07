/*  Vincent Mossman
	Fact / Fib
	February 9, 2013
	Program will provide the factoral of a number as well as determine the nth term of the Fibonacci sequence.
	*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <limits.h>
using namespace std;

//Prototypes:
int getnum(); /* Even though the sheet said to have the main function handle all input and output, with the robustness
			  I wanted to have it made things look a bit cluttered, so I added the getnum functions */
void getnum(int &first_fib, int &second_fib, int &nth_term);
int factoral(int num);
int fibonacci(int first_fib, int second_fib, int nth_term);
char menu();

void main()
{
	char user_choice;
	int orig_factoral_num, post_factoral_num;
	int first_fib, second_fib, nth_term, calculated_fib;

	do
	{
		user_choice = menu();
		switch (user_choice)
		{
		case 'a':
			orig_factoral_num = getnum();
			post_factoral_num = factoral(orig_factoral_num);
			cout << endl << endl << '\t' << orig_factoral_num << "! = ";
			switch (post_factoral_num)
			{
			case 0: 
				cout << "ERROR (Number too large!)" << endl << endl;
				break;
			default:
				cout << post_factoral_num << endl << endl;
				break;
			}
			system("pause");
			system("CLS");
			break;
		case 'b':
			getnum(first_fib, second_fib, nth_term);
			calculated_fib = fibonacci(first_fib, second_fib, nth_term);
			cout << endl << endl << "\tThe " << nth_term;
			switch (nth_term)
			{
			case 1:
				cout << "st";
				break;
			case 2:
				cout << "nd";
				break;
			case 3:
				cout << "rd";
				break;
			default:
				cout << "th";
			}
			cout << " term of the Fibonnaci Sequence beginning with " << first_fib << " and " << second_fib << " is: " <<
				endl << "\t\t";
			switch (calculated_fib)
			{
			case 0:
				cout << "ERROR (Number too large!)" << endl << endl;
				break;
			default:
				cout << calculated_fib << endl << endl;
			}
			system("pause");
			system("CLS");
			break;
		}
	} while (user_choice != 'c');

}

//Pre-con: Accepts an integer value
//Post-con: Returns the factoral of received value
//Other: Also handles negative numbers and zero and returns a 0 if number is too large
int factoral(int num)
{
	int temp = 1;

	if (num != 0)
	{
		for (int counter = num; counter >= 1; counter--)
		{
			temp *= counter;
			if ((temp > INT_MAX) || (temp < 0))
			{
				temp = 0;
				break;
			}
		}
	}
	else
		temp = 1; /* 0!, by definition, is 1 */

	return temp;
}

//Pre-con: Accepts three integer values: two numbers in the fibonacci sequence and the desired term
//Post-con: Returns desired term
/*Other: First two integers must be equal or increasing positive integers and third must be positive
	and if the number is too large function returns a 0 */
int fibonacci(int first_fib, int second_fib, int nth_term)
{
	int temp;

	if (nth_term == 1)
		temp = first_fib;
	else if (nth_term == 2)
		temp = second_fib;
	else
	{
		for (int counter; counter <= (nth_term - 3); counter++)
		{		
			temp = first_fib + second_fib;
			first_fib = second_fib;
			second_fib = temp;

			if ((temp > INT_MAX) || (temp < 0))
			{
				temp = 0;
				break;
			}
		}
	}

	return temp;
}

//Pre-con: None
//Post-con: Returns either a, b, or c (lower case)
char menu()
{
	char user_choice;

	do 
	{
		cout << endl << "\tPlease select an option:" << endl << endl;
		cout << "\t\tA. Factoral (n!)" << endl << "\t\tB. Fibonacci (n1, n2, n1 + n2, n2 + (n1 + n2), . . .)"
			<< endl << "\t\tC. Quit" << endl << endl << endl;
		cout << "Your choice: ";
		cin >> user_choice;

		if ((user_choice == 'a') || (user_choice == 'b') || (user_choice == 'c'))
			break;
		else
		{
			switch (user_choice)
			{
			case 'A': 
				user_choice = 'a';
				break;
			case 'B':
				user_choice = 'b';
				break;
			case 'C':
				user_choice = 'c';
				break;
			default:
				system("CLS");
				cout << endl << "WARNING: '" << user_choice << "' is not a valid choice. "
					<< "Please enter a valid choice." << endl << endl;
			}
		}
	} while (!((user_choice == 'a') || (user_choice == 'b') || (user_choice == 'c')));

	return user_choice;
}

//Pre-con: None
//Post-con: Returns an integer
//Other: Checks for invalid entries
int getnum()
{
	double user_entry;

	system("CLS");
	cout << endl << "\tFACTORAL" << endl << endl << "\t\tPlease enter a number: ";
	cin >> user_entry;

	while (user_entry > INT_MAX)
	{
		system("CLS");
		cout << endl << "\tFACTORAL" << endl << endl << "\t\tWARNING: That number is too big!" << endl << 
			"\t\tPlease enter a number: ";
		cin >> user_entry;
	}

	while ((user_entry < 0) || (fmod(user_entry, 1) != 0))
	{
		system("CLS");
		cout << endl << "\tFACTORAL" << endl << endl << "\t\tWARNING: You must enter an INTEGER GREATER THAN" << endl
			<< "\t\t\t or EQUAL TO zero!" << endl << "\t\tPlease enter a number: ";
		cin >> user_entry;
	}

	system("CLS");
	cout << endl << "\tFACTORAL" << endl << endl << "\t\tPlease enter a number: " << user_entry;

	return int(user_entry);
}

//Pre-con: Three variables
//Post-con: Two of the first numbers in a fibonnaci sequence as well as the desired term
//Other: Checks for invalid entries
void getnum(int &first_fib, int &second_fib, int &nth_term)
{
	double sub_first_fib, sub_second_fib, sub_nth_term;

	system("CLS");
	cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: ";
	cin >> sub_first_fib;

	while (sub_first_fib > INT_MAX)
	{
		system("CLS");
		cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tWARNING: That number is too big!" << endl << 
			"\t\tPlease enter the first term: ";
		cin >> sub_first_fib;
	}

	while ((fmod(sub_first_fib, 1) != 0) || (sub_first_fib < 0))
	{
		system("CLS");
		cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tWARNING: You must enter a POSITIVE INTEGER." << endl << 
			"\t\tPlease enter the first term: ";
		cin >> sub_first_fib;
	}

	system("CLS");
	cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: " << sub_first_fib
		<< endl;
	cout << "\t\tPlease enter the second term: ";
	cin >> sub_second_fib;

	while (sub_second_fib > INT_MAX)
	{
		system("CLS");
		cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: " << 
			sub_first_fib << endl << "\t\tWARNING: That number is too big!" << endl;
		cout << "\t\tPlease enter the second term: ";
		cin >> sub_second_fib;
	}

	while ((fmod(sub_second_fib, 1) != 0) || (sub_second_fib < sub_first_fib))
	{
		system("CLS");
		cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: " << 
			sub_first_fib << endl << "\t\tWARNING: You must enter an INTEGER that is GREATER THAN" << endl <<
			"\t\t\t or EQUAL TO the first term." << endl;
		cout << "\t\tPlease enter the second term: ";
		cin >> sub_second_fib;
	}

	system("CLS");
	cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: " << sub_first_fib
		<< endl << "\t\tPlease enter the second term: " << sub_second_fib << endl;
	cout << "\t\tPlease enter the desired term to be calculated: ";
	cin >> sub_nth_term;

	while (sub_nth_term > INT_MAX)
	{
		system("CLS");
		cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: " << sub_first_fib
			<< endl << "\t\tPlease enter the second term: " << sub_second_fib << endl <<
			"\t\tWARNING: That number is too big!" << endl;
		cout << "\t\tPlease enter the desired term to be calculated: ";
		cin >> sub_nth_term;
	}

	while ((fmod(sub_nth_term, 1) != 0) || (sub_nth_term <= 0))
	{
		system("CLS");
		cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: " << sub_first_fib
			<< endl << "\t\tPlease enter the second term: " << sub_second_fib << endl <<
			"\t\tWARNING: You must enter a POSITIVE INTEGER." << endl;
		cout << "\t\tPlease enter the desired term to be calculated: ";
		cin >> sub_nth_term;
	}

	system("CLS");
	cout << endl << "\tFIBONACCI SEQUENCE" << endl << endl << "\t\tPlease enter the first term: " << sub_first_fib
		<< endl << "\t\tPlease enter the second term: " << sub_second_fib << endl <<
		"\t\tPlease enter the desired term to be calculated: " << sub_nth_term;

	first_fib = int(sub_first_fib);
	second_fib = int(sub_second_fib);
	nth_term = int(sub_nth_term);
}