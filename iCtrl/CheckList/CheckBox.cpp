#include "CheckBox.h"

int rowCount = 0;
string unchecked = "[ ]";
string checked = "[X]";

CheckBox::CheckBox(string name, COORD pos, HANDLE hndl, int clrNum, int clrNumHvr)
{
	//Saves each time the Y position on the initial position set and 
	//Adds the rowCount counter to it (thus advances each cell)
	int place = pos.Y + rowCount++;

	//set cursor initial position
	COORD c = { pos.X, place };
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hndl, c);

	//Initializes cells vars

	bName = name;
	iLenght = name.length() + 4;
	active = false;
	pressed = false;
	curY = place;
	clrNormal = clrNum;
	clrActive = clrNumHvr;

	//Prints an initialized cell (just "[ ]" and its name)
	cout << unchecked << " " << bName;

	//vector<CheckList> cList;
	//for (int i = 0; i < arrSize; i++)
	//{
	//	cList.push_back(CheckList(i));
	//	cList[i].bName = "Item" + i;
	//	cList[i].iLenght = cList[i].bName.length() + 4;
	//	cList[i].active = false;
	//	cList[i].pressed = false;
	//	cList[i].curY = pos.Y;
	//	cList[i].clrNum = 7;
	//	cList[i].clrNumHvr = 240;
	//}


	////Prints an initialized cell (just "[ ]" and its name)
	//for (int i = 0; i < arrSize; i++)
	//{
	//	cout << unchecked << " " << cList[i].bName << i;
	//}
}


CheckBox::~CheckBox() {}

//Switching position of rows
void CheckBox::coordinator(COORD& cur, string upDown)
{
	if (upDown == "down") cur.Y = cur.Y + 1; //Sets Global Y position to Y+1
	else cur.Y = cur.Y - 1; // Sets Global Y position to Y-1
}

//Gets "Acvite" State
bool CheckBox::isActive() { return active; }

//Gets the Y position of a cell
int CheckBox::getPlace() { return curY; }

//Sets a Cell's "Acvite" to ture/false {Keyboard Use}
void CheckBox::setActive(COORD cur)
{
	//Sets cursors position
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, cur);

	//Swithces cell's "Active" state and color scheme (true becomes false and vice versa)
	if (active)
	{
		active = false;
		SetConsoleTextAttribute(h, clrNormal);
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
void CheckBox::setActiveTrue(COORD& cur)
{
	//Changes the GLOBAL cursor's Y position to the objects position
	//And sets the colors to chosen scheme
	cur.Y = getPlace();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clrActive);

	//Sets the cell to "Active"
	active = true;

	//Checks if the cell is selected ("[X]") or not and reprints the cell in "Active" colors
	if (pressed) cout << checked << " " << getName();
	else cout << unchecked << " " << getName();
}

//Sets a Cell's "Active" to false {Mouse Use}
void CheckBox::setActiveFalse(COORD cur)
{
	//Changes the LOCAL cursor's Y position to the objects position
	//And sets the colors to chosen scheme
	cur.Y = getPlace();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clrNormal);

	//Sets the cell to "Active"
	active = false;

	//Checks if the cell is selected ("[X]") or not and reprints the cell in NON-"Active" colors
	if (pressed) cout << checked << " " << getName();
	else cout << unchecked << " " << getName();
}

//Selection switch that checks whether a Cell has been selected or not (has "X")
//If Cell is unselected ("[ ]") then the function changes it to selected ("[X]"), and vice versa
void CheckBox::checkSwitch(COORD cur)
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
bool CheckBox::getSwitchState() { return pressed; }

//Returns Cell's name/label
string CheckBox::getName() { return bName; }

//Returns Cell's lenght (from the first char "[" to the last)
int CheckBox::getLenght() { return iLenght; }
