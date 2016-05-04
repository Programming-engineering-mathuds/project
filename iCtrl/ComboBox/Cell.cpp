#include "Cell.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <array>

using namespace std;

int rowCount = 2; // used to addvance rows - unused at the moment

Cell::Cell(string objName, COORD pos, HANDLE hndl, int clrNum, int clrNumHvr)
{
	//int place = pos.Y + rowCount++;

	bName = objName;
	active = false;
	pressed = false;
	c = { pos.X + 2, pos.Y + rowCount++ };
	iLenght = objName.length();
}

Cell::~Cell() { }

//Switching position of rows
void Cell::coordinator(COORD& cur, string upDown)
{
	if (upDown == "down") cur.Y = cur.Y + 1;
	else cur.Y = cur.Y - 1;
}

//Gets "Acvite" State
bool Cell::isActive() { return active; }

//Gets the Y position of a cell
int Cell::getPlace() { return c.Y; }

//Sets a Cell's "Acvite" to ture/false
void Cell::setActive(COORD cur)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, cur);
	if (active)
	{
		active = false;
		SetConsoleTextAttribute(h, 7);
	}
	else
	{
		active = true;
		SetConsoleTextAttribute(h, 240);
	}
	if (pressed) cout << bName;
	else cout << bName;
}

//Sets a Cell's "Active" to true
void Cell::setActiveTrue(COORD& cur)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cur.Y = getPlace();
	COORD tempCur = cur;
	tempCur.X = tempCur.X + 2;
	SetConsoleCursorPosition(h, tempCur);
	if (pressed) SetConsoleTextAttribute(h, 240);
	else SetConsoleTextAttribute(h, 240);
	active = true;
	cout << bName;
}

//Sets a Cell's "Active" to false
void Cell::setActiveFalse(COORD cur)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cur.Y = getPlace();
	cur.X = cur.X + 2;
	SetConsoleCursorPosition(h, cur);
	SetConsoleTextAttribute(h, 7);
	active = false;
	cout << bName;
}

void Cell::checkSwitch(COORD cur)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tempCur = { cur.X + 2, cur.Y };
	SetConsoleCursorPosition(h, tempCur);
	SetConsoleTextAttribute(h, 7);
	if (pressed)
	{
		pressed = false;
		cout << bName + "               ";
	}
	else
	{
		pressed = true;
		cout << bName + "               ";
	}
}

void Cell::setPressedColor(COORD cur)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tempCur = { cur.X + 2, cur.Y };
	SetConsoleCursorPosition(h, tempCur);
	SetConsoleTextAttribute(h, 7);
	cout << bName;
}

bool Cell::getSwitchState() { return pressed; }

string Cell::getName() { return bName; }

void Cell::reveal()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << bName;
}

void Cell::hide()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	cout << bName;
}
