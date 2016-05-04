#include "iCtrl.h"

#include <iostream>
using namespace std;

iCtrl::iCtrl(int arrSize, COORD cur)
{
	pos = cur;
	maxWidth = 0;
	//SetConsoleCursorPosition(hndl, pos);
}

iCtrl::~iCtrl() {}

void iCtrl::frame(int size, int frameLines)
{
	//X Axis
	int xInit = 0;
	int xEnd = maxWidth + 3;
	//Y Axis
	int yInit = 0;
	int yEnd = size + 3;
	if (frameLines == 1)
	{
		//Prints Borders
		for (int i = yInit; i <= yEnd; i++)
		{
			//Upper row
			if (i == yInit)
			{
				pos = { xInit, yInit };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xDA';
				for (int j = xInit + 1; j < xEnd; j++)
				{
					pos = { j, i };
					SetConsoleCursorPosition(hndl, pos);
					cout << '\xC4';
				}
				cout << '\xBF';
			}
			//Middle columns (first and last only) 
			if ((i > yInit) && (i < yEnd))
			{
				pos = { xEnd, i };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xB3';
				pos = { xInit, i };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xB3';
			}
			//Lower row
			if (i == yEnd)
			{
				pos = { xInit, i };
				SetConsoleCursorPosition(hndl, pos);
				cout << '\xC0';
				for (int j = xInit + 1; j < xEnd; j++)
				{
					pos = { j, i };
					SetConsoleCursorPosition(hndl, pos);
					cout << '\xC4';
				}
				cout << '\xD9';
			}
		}
	}
	if (frameLines == 2)
	{
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
}

void iCtrl::color(int clrNum)
{
	SetConsoleTextAttribute(hndl, clrNum);
}

void iCtrl::color2(Foreground clrNumFont, Background clrNumBG)
{
	SetConsoleTextAttribute(hndl, (DWORD)clrNumFont);
	SetConsoleTextAttribute(hndl, (DWORD)clrNumBG);
}