/*
&& is the AND logical operator
|| is the OR logical operator
! is the NOT logical operator

if (4.2 >= 5.0) && (8 == (3+5))
false && true
false
*/

/* Declare Boolean:
typedef int boolean;
boolean true = 1;
boolean false = 0;
*/

// #include <iomanip> //input output manipulation... formatting
/*
	cout << endl *makes new line
	cout << '\n' *makes new line
	cout << '\t' *tab

	setw(5) *sets field width to 5 spaces

	cout.setf(ios::left, ios::adjustfield) *left justify
	cout.setf(ios::showpoint | ios::fixed)
		cout << setprecision(3) << variable << endl; *sets and rounds to third decimal place

5 Rules of Formatting:

1. The decimal point counts as one space
2. Trailing zeros are printed to the number of positions
3. Leading plus (+) signs are not displayed
4. Leading minus (-) signs are displayed
5. Digits appearing to the right of the decimal point will be rounded not truncated.

*/

/*
	Rules of mixed typed
	1. If the operands have the same type, the result will be that type.
	2. If the operands do not have the same type, the  smaller type is promoted to the larger type.

	*/
/*
	Declaration of Variables
	<type><name>


*/

/* only one main in a project, but you can exclude from project without deleting file

*/

/* <limits.h> <float.h> has functions that return min and max type values. */
/* <math.h> math functions */

/* a++ is the same as a = a + 1
   a-- is the same as a = a - 1
   ++a is the same as a = a + 1
   --a is the same as a = a - 1

   */

// typedef char initial <-- make your own types //

#include <iomanip>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <iostream> 
#include <assert.h>
using namespace std;

void notmainlul()
{

	int numStu;
	cout << "Enter the number of strudents: ";
	cin >> numStu;

	assert(numStu > 0);
	cout << numStu;

	typedef char string[];

	string _explaination = "To make a string type, you have to be all like: 'typedef char string[]'";
	cout << _explaination << endl << endl;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	cout << "Maximum integer allowed: " << INT_MAX << endl << endl;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	int i = 1;

	while (i < 11) {
		cout << "Test of While Loop. Line " << i++ << endl;
	}

	cout << endl;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	int m, n, a, b, c;

	cout << "Enter a positive integer: ";
	cin >> n;
	cout << "enger a positive integer larger than " << n << ": ";
	cin >> m;

	a = pow(double(m), 2) - pow(double(n), 2);
	b = 2 * m * n;
	c = pow(double(m), 2) + pow(double(n), 2);

	cout << endl;
	cout << "For m = " << m << " and " << "n = " << n << endl;
	cout << "The Pythagorean Triple is: " << a << " " << b << " " << c << endl << endl;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	if ( 10 < 5 ) {
		cout << "This is a test of an if statement." << endl << endl;
	}
	else {
		cout << "This is a test of the else part." << endl << endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	system("Pause");
	system("cls");

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	system("Pause");
}

