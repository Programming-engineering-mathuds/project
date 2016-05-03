#include "iCtrl.h"

#include <iostream>
using namespace std;

int xCount = 0;
int yCount = 0;

iCtrl::iCtrl(int arrSize)
{
	//frame(arrSize);
	//rowLength = lenght;
	pos = { (short)xCount, (short)yCount++ };
	SetConsoleCursorPosition(hndl, pos);
}

iCtrl::~iCtrl(){}

void iCtrl::frame(int size)
{
	int xInit = 0;
	int xEnd = 40;
	int yInit = 0;
	int yEnd = 40;
	//Prints Borders
	for (int i = yInit; i <= yEnd; i++)
	{
		//Upper row
		if (i == yInit)
		{
			pos = { (short)xInit, (short)yInit };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xC9';
			for (int j = xInit + 1; j < xEnd; j++)
			{
				pos = { (short)j,(short)i };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xCD';
			}
			cout << '\xBB';
		}
		//Middle columns (first and last only) 
		if ((i > yInit) && (i < yEnd))
		{
			pos = { (short)xEnd, (short)i };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xBA';
			pos = { (short)xInit, (short)i };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xBA';
		}
		//Lower row
		if (i == yEnd)
		{
			pos = { (short)xInit,(short)i };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xC8';
			for (int j = xInit + 1; j < xEnd; j++)
			{
				pos = { (short)j, (short)i };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xCD';
			}
			cout << '\xBC';
		}
	}
}

void iCtrl::color(int clrNumFont, int clrNumBG)
{
	SetConsoleTextAttribute(hndl, clrNum);
}