/*  Vincent Mossman
	Bowling (Function Project)
	January 7, 2013
	The purpose of this program is to display the individual total, the individual average, as well as the team
		total and average for a bowling team that bowls at Roll-Em Lanes.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//Prototypes:
void GetScore(int &game1, int &game2, int &game3);
int ScoreSum(int game1, int game2, int game3);
double ScoreAve(int totalscore);
void TeamTotAve(int indtotal1, int indtotal2, int indtotal3, int indtotal4, int &teamtotal, double &teamaverage);

//Player 1: Weber
//Player 2: Fazio
//Player 3: Martin
//Player 4: Patterson

void main()
{
	cout.setf(ios::showpoint | ios::fixed);

	cout.setf(ios::right, ios::adjustfield);
	cout << setw(30) << "Welcome to Roll-Em Lanes!" << endl << endl;

	int webergame1, faziogame1, martingame1, pattersongame1;
	int webergame2, faziogame2, martingame2, pattersongame2;
	int webergame3, faziogame3, martingame3, pattersongame3;
	int webertotal, faziototal, martintotal, pattersontotal;
	double weberaverage, fazioaverage, martinaverage, pattersonaverage;
	int teamtotal;
	double teamaverage;
	
	cout.setf(ios::right, ios::adjustfield);
	cout << setw(24) << "*** WEBER ***" << endl;
	GetScore(webergame1, webergame2, webergame3);
	cout << endl;

	cout.setf(ios::right, ios::adjustfield);
	cout << setw(24) << "*** FAZIO ***" << endl;
	GetScore(faziogame1, faziogame2, faziogame3);
	cout << endl;

	cout.setf(ios::right, ios::adjustfield);
	cout << setw(24) << "*** MARTIN ***" << endl;
	GetScore(martingame1, martingame2, martingame3);
	cout << endl;
	
	cout.setf(ios::right, ios::adjustfield);
	cout << setw(26) << "*** PATTERSON ***" << endl;
	GetScore(pattersongame1, pattersongame2, pattersongame3);
	cout << endl;

	webertotal = ScoreSum(webergame1, webergame2, webergame3);
	faziototal = ScoreSum(faziogame1, faziogame2, faziogame3);
	martintotal = ScoreSum(martingame1, martingame2, martingame3);
	pattersontotal = ScoreSum(pattersongame1, pattersongame2, pattersongame3);
	
	weberaverage = ScoreAve(webertotal);
	fazioaverage = ScoreAve(faziototal);
	martinaverage = ScoreAve(martintotal);
	pattersonaverage = ScoreAve(pattersontotal);

	TeamTotAve(webertotal, faziototal, martintotal, pattersontotal, teamtotal, teamaverage);
	
	system("CLS");

	cout << "Name" << '\t' << '\t' << "Game 1" << '\t' << "Game 2" << '\t' << "Game 3" << '\t' << "TOTAL" << '\t' << "AVERAGE"
		<< endl << endl;
	cout << "Weber" << '\t' << '\t' << webergame1 << '\t' << webergame2 << '\t' << webergame3 << '\t' << webertotal <<
		'\t';
	cout << setprecision(1) << weberaverage << endl << endl;
	cout << "Fazio" << '\t' << '\t' << faziogame1 << '\t' << faziogame2 << '\t' << faziogame3 << '\t' << faziototal <<
		'\t';
	cout << setprecision(1) << fazioaverage << endl << endl;
	cout << "Martin" << '\t' << '\t' << martingame1 << '\t' << martingame2 << '\t' << martingame3 << '\t' << martintotal <<
		'\t';
	cout << setprecision(1) << martinaverage << endl << endl;
	cout << "Patterson" << '\t' << pattersongame1 << '\t' << pattersongame2 << '\t' << pattersongame3 << '\t' << 
		pattersontotal << '\t';
	cout << setprecision(1) << pattersonaverage << endl << endl;
	cout << '\t' << "Team Total:  " << teamtotal << endl << endl;
	cout << '\t' << "Team Average:  " << teamaverage << endl << endl << endl;

	system("pause");
}

// Pre-con/Input: User enters scores for each of three games.
// Post-con/Output: Returns scores for the three games.
void GetScore(int &game1, int &game2, int &game3)
{
	cout << "Please enter Game 1 score: ";
	cin >> game1;
	cout << "Please enter Game 2 score: ";
	cin >> game2;
	cout << "Please enter Game 3 score: ";
	cin >> game3;
}
// Pre-con/Input: Accepts three game scores.
// Post-con/Output: Returns sum of three game scores.
int ScoreSum(int game1, int game2, int game3)
{
	return game1 + game2 + game3;
}

// Pre-con/Input: Accepts sum of three game scores.
// Post-con/Output: Returns average of sum of three game scores.
double ScoreAve(int totalscore)
{
	return double(totalscore) / 3;
}

// Pre-con/Input: Accepts four players total scores.
// Post-con/Output: Returns team total and team average.
void TeamTotAve(int indtotal1, int indtotal2, int indtotal3, int indtotal4, int &teamtotal, double &teamaverage)
{
	teamtotal = indtotal1 + indtotal2 + indtotal3 + indtotal4;
	teamaverage = double(teamtotal) / 3;
}
