#include "iControl.h"
#include <iostream>
using namespace std;

vector<iControl*> iControl::controls;

void iControl::setCoords(COORD coord) {
	pos = coord;
	top = pos.Y;
	left = pos.X;
	mPos = pos;

};
void iControl::setLocation(int x, int y)
{
	COORD co = { x, y };
	pos = co;
	setLeft(x);
	setTop(y);
	mPos = co;
}
void iControl::frame(int size)
{
	hight = size;
	//X Axis
	int xInit = pos.X - 1;
	int xEnd = maxWidth + 1;
	//Y Axis
	int yInit = pos.Y - 1;
	int yEnd = pos.Y + size;
	if ((border != BorderType::None) && (pos.X = 0) && (pos.Y = 0)) //frame cannot be printed in -1,-1
	{
		setLocation(1, 1);
	}

	if (border != BorderType::None)
	{
		//Prints Borders
		for (int i = yInit; i <= yEnd; i++)
		{
			//Upper row
			if (i == yInit)
			{
				pos = { xInit, yInit };
				SetConsoleCursorPosition(hndl, pos);
				if (border == BorderType::Single) cout << '\xDA';
				else cout << '\xC9';
				for (int j = xInit + 1; j < xEnd; j++)
				{
					pos = { j, i };
					SetConsoleCursorPosition(hndl, pos);
					if (border == BorderType::Single) cout << '\xC4';
					else cout << '\xCD';
				}
				if (border == BorderType::Single) cout << '\xBF';
				else cout << '\xBB';
			}
			//Middle columns (first and last only) 
			if ((i > yInit) && (i < yEnd))
			{
				pos = { xEnd, i };
				SetConsoleCursorPosition(hndl, pos);
				if (border == BorderType::Single) cout << '\xB3';
				else cout << '\xBA';
				pos = { xInit, i };
				SetConsoleCursorPosition(hndl, pos);
				if (border == BorderType::Single) cout << '\xB3';
				else cout << '\xBA';
			}
			//Lower row
			if (i == yEnd)
			{
				pos = { xInit, i };
				SetConsoleCursorPosition(hndl, pos);
				if (border == BorderType::Single) cout << '\xC0';
				else cout << '\xC8';
				for (int j = xInit + 1; j < xEnd; j++)
				{
					pos = { j, i };
					SetConsoleCursorPosition(hndl, pos);
					if (border == BorderType::Single) cout << '\xC4';
					else cout << '\xCD';
				}
				if (border == BorderType::Single) cout << '\xD9';
				else cout << '\xBC';
			}
		}
	}
}
/*
void iControl::color(int clrNum)
{
	SetConsoleTextAttribute(hndl, clrNum);
}

void iControl::color2(Foreground clrNumFont, Background clrNumBG)
{
	SetConsoleTextAttribute(hndl, (DWORD)clrNumFont);
	SetConsoleTextAttribute(hndl, (DWORD)clrNumBG);
}
*/