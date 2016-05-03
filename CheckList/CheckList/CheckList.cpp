#include "CheckList.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int rowCount = 0;
string unchecked = "[ ]";
string checked = "[X]";

//Constructor
CheckList::CheckList(string name, COORD cur)
{
	//Saves each time the Y position on the initial position set and 
	//Adds the rowCount counter to it (thus advances each cell)
	int place = cur.Y + rowCount++;
	
	//set cursor initial position
	COORD c = { cur.X, place };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, c);

	//Initializes cells vars
	bName = name;
	iLenght = name.length() + 4;
	active = false;
	pressed = false;
	curY = place;

	//Prints an initialized cell (just "[ ]" and its name)
	cout << unchecked << " " << bName;
}

//Destructor
CheckList::~CheckList() {}

//Switching position of rows
void CheckList::coordinator(COORD& cur, string upDown)
{
	if (upDown == "down") cur.Y = cur.Y + 1; //Sets Global Y position to Y+1
	else cur.Y = cur.Y - 1; // Sets Global Y position to Y-1
}

//Gets "Acvite" State
bool CheckList::isActive() { return active; }

//Gets the Y position of a cell
int CheckList::getPlace() { return curY; }

//Sets a Cell's "Acvite" to ture/false {Keyboard Use}
void CheckList::setActive(COORD cur)
{
	//Sets cursors position
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, cur);

	//Swithces cell's "Active" state and color scheme (true becomes false and vice versa)
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

	//Checks if the cell is selected ("[X]") or not and reprints the cell in the acording colors
	if (pressed) cout << checked << " " << bName;
	else cout << unchecked << " " << bName;
}

//Sets a Cell's "Active" to true {Mouse Use}
void CheckList::setActiveTrue(COORD& cur)
{
	//Changes the GLOBAL cursor's Y position to the objects position
	//And sets the colors to chosen scheme
	cur.Y = getPlace();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

	//Sets the cell to "Active"
	active = true;

	//Checks if the cell is selected ("[X]") or not and reprints the cell in "Active" colors
	if (pressed) cout << checked << " " << getName();
	else cout << unchecked << " " << getName();
}

//Sets a Cell's "Active" to false {Mouse Use}
void CheckList::setActiveFalse(COORD cur)
{
	//Changes the LOCAL cursor's Y position to the objects position
	//And sets the colors to chosen scheme
	cur.Y = getPlace();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	//Sets the cell to "Active"
	active = false;

	//Checks if the cell is selected ("[X]") or not and reprints the cell in NON-"Active" colors
	if (pressed) cout << checked << " " << getName();
	else cout << unchecked << " " << getName();
}

//Selection switch that checks whether a Cell has been selected or not (has "X")
//If Cell is unselected ("[ ]") then the function changes it to selected ("[X]"), and vice versa
void CheckList::checkSwitch(COORD cur)
{
	//Sets cursors position and color scheme
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, cur);
	SetConsoleTextAttribute(h, 240); //Active = on, color scheme

	//Swithces cell's "Pressed" state (true becomes false and vice versa) and reprints it
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

//Returns Cell's selected/unselected status
bool CheckList::getSwitchState() { return pressed; }

//Returns Cell's name/label
string CheckList::getName() { return bName; }

//Returns Cell's lenght (from the first char "[" to the last)
int CheckList::getLenght() { return iLenght; }