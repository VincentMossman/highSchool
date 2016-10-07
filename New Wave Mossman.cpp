/*  Vincent Mossman
	New Wave Prices
	December 12, 2012
	The purpose of this program is to display the cost of various computer parts along with the subtotal, tax, and total.
	*/

#include <iomanip>
#include <math.h> //Just in case//
#include <iostream> 
using namespace std;

//Constants:
typedef double Price; //Made my own name for a double for fun//
const Price NEW_PC = 675.00, MEM_CARD = 69.95, FLSH_DRIVE = 15.36, SFTWR_PACK = 114.25;

void main()
{
	typedef int Num_Ordered; //And integer//
	
	//Number Ordered varibles:
	Num_Ordered ordered_new_pc, ordered_mem_card, ordered_flsh_drive, ordered_sftwr_pack;

	cout << "Enter the quantity of New PCs purchased: ";
	cin >> ordered_new_pc;
	cout << endl << "Enter the quantity of Memory Cards purchased: ";
	cin >> ordered_mem_card;
	cout << endl << "Enter the quantity of Flash Drives purchased: ";
	cin >> ordered_flsh_drive;
	cout << endl << "Enter the quantity of Software Packs purchased: ";
	cin >> ordered_sftwr_pack;
	cout << endl << endl;

	double subtotal = (NEW_PC * ordered_new_pc) + (MEM_CARD * ordered_mem_card) + (FLSH_DRIVE * ordered_flsh_drive) +
		(SFTWR_PACK * ordered_sftwr_pack);
	double tax = subtotal * 0.07;

	cout.setf(ios::showpoint | ios::fixed);

	cout << "**************************" << endl << "New Wave Computers" << endl << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << "Item";
	cout.setf(ios::right, ios::adjustfield);
	cout <<  setw(22) << "Cost" << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << ordered_new_pc << " NW-PC";
	cout.setf(ios::right, ios::adjustfield);
	cout  << setw(13) << '$' << setprecision(2) << NEW_PC * ordered_new_pc << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << ordered_mem_card << " Memory Card";
	cout.setf(ios::right, ios::adjustfield);
	cout << setw(13) << setprecision(2) << MEM_CARD * ordered_mem_card << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << ordered_flsh_drive << " Flash Drive";
	cout.setf(ios::right, ios::adjustfield);
	cout  << setw(13) << setprecision(2) << FLSH_DRIVE * ordered_flsh_drive << endl;

	cout.setf(ios::left, ios::adjustfield);
	cout << ordered_sftwr_pack << " Software Pack";
	cout.setf(ios::right, ios::adjustfield);
	cout  << setw(11) << setprecision(2) << SFTWR_PACK * ordered_sftwr_pack << endl << endl;

	cout << '\t' << "SUBTOTAL" << setw(3) << setprecision(2) << '$' << subtotal << endl; 
	cout << '\t' << "TAX (7%)" << setw(10) << setprecision(2) << tax << endl; 
	cout << '\t' << "TOTAL" << setw(6) << setprecision(2) << '$' << subtotal + tax << endl << endl; 

	cout << "**************************" << endl << endl;


	system("Pause");
}