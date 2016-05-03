#include "iCtrl.h"

#include <iostream>
using namespace std;

int xCount = 0;
int yCount = 0;

iCtrl::iCtrl(int arrSize)
{
	//frame(arrSize);
	//rowLength = lenght;
	pos = { xCount, yCount++ };
	SetConsoleCursorPosition(hndl, pos);
}

iCtrl::~iCtrl() {}

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
			pos = { xInit, yInit };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xC9';
			for (int j = xInit + 1; j < xEnd; j++)
			{
				pos = { j, i };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xCD';
			}
			cout << '\xBB';
		}
		//Middle columns (first and last only) 
		if ((i > yInit) && (i < yEnd))
		{
			pos = { xEnd, i };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xBA';
			pos = { xInit, i };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xBA';
		}
		//Lower row
		if (i == yEnd)
		{
			pos = { xInit, i };
			SetConsoleCursorPosition(hndl, pos);
			cout << '\xC8';
			for (int j = xInit + 1; j < xEnd; j++)
			{
				pos = { j, i };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xCD';
			}
			cout << '\xBC';
		}
	}
}

void iCtrl::color(int clrNum)
{
	SetConsoleTextAttribute(hndl, clrNum);
}