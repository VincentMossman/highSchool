/*
// multi-threading_practice.cpp : Defines the entry point for the console application.

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <iostream>
#include <string>

using namespace std;


HANDLE hPrintMutex;			//"Integer printed" mutex
int ThreadNr;				//number of threads started
int x;

void printNumber(void* pInt)
{
	int* xp=(int*)pInt;
	while(*xp<100)
	{
		WaitForSingleObject(hPrintMutex,INFINITE);
		++*xp;
		cout<<*xp<<endl;
		ReleaseMutex(hPrintMutex);
		Sleep(10);
	}
}

void printNumberDouble(void* pInt)
{
	int* xp=(int*)pInt;
	while(*xp<99)
	{
		WaitForSingleObject(hPrintMutex,INFINITE);
		*xp+=2;
		cout<<*xp<<endl;
		ReleaseMutex(hPrintMutex);
		Sleep(10);
	}
}

int main()
{
	x=0;
	hPrintMutex=CreateMutex(NULL,false,NULL);
	
	HANDLE hThread1=(HANDLE)_beginthread(printNumber,0,&x);
	HANDLE hThread2=(HANDLE)_beginthread(printNumberDouble,0,&x);

	WaitForSingleObject(hThread1,INFINITE);
	WaitForSingleObject(hThread2,INFINITE);
	return 0;
}
*/

/*

#include <iostream>
#include <Windows.h>
#include <Mspthrd.h>
using namespace std;

void  * function1(void * argument);
void  * function2(void * argument);

int mainCUNTSUCKINGFAGGOT( void )
{
    pthread_t t1, t2 ; // declare 2 threads.
    pthread_create( &t1, NULL, function1,NULL); // create a thread running function1
    pthread_create( &t2, NULL, function2,NULL); // create a thread running function2

    // Because all created threads are terminated when main() finishes, we have
    // to give the threads some time to finish. Unfortunately for function1, main()
    // will give only 1 second, but function1 needs at least 2 seconds. So function1 will
    // probably be terminated before it can finish. This is a BAD way to manage threads.
    sleep(1);

    return 0;
}

void * function1(void * argument)
{
    cout << " hello " << endl ;
    sleep(2); // fall alseep here for 2 seconds...
    return 0;
}

void * function2(void * argument)
{
    cout << " world "  << endl ;
    return 0;
}

*/
