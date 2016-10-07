#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
bool IsPrime(long int num_in_question);
char menu();
void main()
{
	long int smaller_prime = 1, larger_prime, sm_last_confirmed, lg_last_confirmed;
	bool is_it_prime;
	char choice;
	choice = menu();
	switch (choice)
	{
	case 'A':
	case 'a':
		{
			while (smaller_prime >=1)
			{
				if (IsPrime(smaller_prime))
				{
					larger_prime = smaller_prime + 2;
					if (IsPrime(larger_prime))
					{
						cout << smaller_prime << "   " << larger_prime << endl;
					}
				}
				smaller_prime++;
			}
		}
	case 'B':
	case 'b':
		{
			while (smaller_prime >=1)
			{
				larger_prime = smaller_prime + 2;
				if (sm_last_confirmed != smaller_prime)
				{
					system("CLS");
					cout << "Num pair being checked: " << smaller_prime << "   " << larger_prime << endl << endl;
					cout << "Last confirmed pair: " << sm_last_confirmed << "   " << lg_last_confirmed << endl;
				}
				if (IsPrime(smaller_prime))
				{
					if (IsPrime(larger_prime))
					{
						sm_last_confirmed = smaller_prime;
						lg_last_confirmed = larger_prime;
					}
				}
				smaller_prime++;
			}
		}
	}				
}
bool IsPrime(long int num_in_question)
{
	long int temp = 0;
	bool is_prime;
	if ((num_in_question - 1) > 0)
	{
		temp = (num_in_question / 2) + 1;	
		do {
			temp--;
			if ((!(num_in_question % temp)) && (temp != 1))
			{
				is_prime = false;
				break;
			}
			else if (temp == 1)
			{
				is_prime = true;
				break;
			}
		} while ((num_in_question % temp) && (temp >= 1));
	}
	else
		is_prime = false;
	return is_prime;
}
char menu()
{
	char choice;
	cout << endl << "   Trying to answer the question: Is there a finite or an infinite number" << endl << "\tof prime number pairs whos difference is two?" << endl << endl;
	cout << endl << "   Please choose an option:" << endl << endl << "   A. Fast" << endl <<   "   B. Fancy" << endl << endl << "   Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 'A':
	case 'a':
	case 'B':
	case 'b':
		break;
	default:
		{
		system("CLS");
		cout << endl << "   PLEASE CHOOSE A VALID OPTION: ";
		choice = menu();
		}
	}
	return choice;
}