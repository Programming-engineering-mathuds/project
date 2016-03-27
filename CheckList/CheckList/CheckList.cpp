#include "CheckList.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int rowCount = 5; // used to addvance rows - unused at the moment
string unchecked = "[ ]";
string checked = "[X]";

//Constructor
CheckList::CheckList(string name, int place)
{
	//set cursor initial position
	COORD c = { 35, place };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, c);

	bName = name;
	active = false;
	pressed = false;
	curY = place;
	cout << unchecked << " " << bName;
}

//Switching position of rows
void CheckList::coordinator(COORD& cur, string upDown)
{
	if (upDown == "down") cur.Y = cur.Y + 1;
	else cur.Y = cur.Y - 1;
}

//Gets "Acvite" State
bool CheckList::isActive() { return active; }

//Gets the Y position of a cell
int CheckList::getPlace() { return curY; }

//Sets a Cell's "Acvite" to ture/false
void CheckList::setActive(COORD cur)
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
	if (pressed) cout << checked << " " << bName;
	else cout << unchecked << " " << bName;
}

//Sets a Cell's "Active" to true
void CheckList::setActiveTrue(COORD& cur)
{
	COORD tempCur;
	tempCur.X = cur.X;
	tempCur.Y = getPlace();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tempCur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	active = true;
	cur = tempCur;
	if (pressed) cout << checked << " " << getName();
	else cout << unchecked << " " << getName();
}

//Sets a Cell's "Active" to false
void CheckList::setActiveFalse(COORD cur)
{
	COORD tempCur;
	tempCur.X = cur.X;
	tempCur.Y = getPlace();
	active = false;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tempCur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	if (pressed) cout << checked << " " << getName();
	else cout << unchecked << " " << getName();
}

void CheckList::checkSwitch(COORD cur)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, cur);
	SetConsoleTextAttribute(h, 240);
	if (pressed)
	{
		pressed = false;
		cout << unchecked << " " << bName;
	}
	else
	{
		pressed = true;
		cout << checked << " " << bName;
	}
}

bool CheckList::getSwitchState() { return pressed; }

string CheckList::getName() { return bName; }

CheckList::~CheckList()
{
}
