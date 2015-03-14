#include <stdio.h>
#include "windows.h"

int main()
{
	int i;
	for(i=0;i<9 ;++i)
	{
		if(i%7==1)
		{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
		printf("egg-%d\n",i+1);
		} 
		else if(i%7==2)
		{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		printf("egg-%d\n",i+1);
		} 
		else if(i%7==3)
		{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		printf("egg-%d\n",i+1);
		} 
		else if(i%7==4)
		{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		printf("egg-%d\n",i+1);
		} 
		else if(i%7==5)
		{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		printf("egg-%d\n",i+1);
		} 
		else if(i%7==6)
		{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("egg-%d\n",i+1);
		} 
		else if(i%7==0)
		{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("egg-%d\n",i+1);
		} 
	}
}
