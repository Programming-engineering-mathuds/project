#include "CheckBox.h"
#include <windows.h>

struct CheckBoxListener : public MouseListener
{
	CheckBoxListener(iControl &c) : _c(c) { }
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		cout << "boom!";
	}
private:
	iControl &_c;
};

int rowCount = 0;

// "width" holds the second value returned from the main & "name.length" is 
// being sent all the way down to iControl, which puts it in "maxWidth"
// bottom line - iLength != maxWidth
CheckBox::CheckBox(string name, int width) : Button(name.length())
{
	CheckBoxListener(*this);
	iLenght = width;
	bName = name;
	hover = false;
	pressed = false;
}


CheckBox::~CheckBox() {}

//Switching position of rows
void CheckBox::coordinator(COORD& cur, string upDown)
{
	if (upDown == "down") cur.Y = cur.Y + 1; //Sets Global Y position to Y+1
	if (upDown == "up") cur.Y = cur.Y - 1; // Sets Global Y position to Y-1
	//if (upDown == "top") cur.Y = cur.Y + ;
}

//Gets "Acvite" State
bool CheckBox::isHover() { return hover; }

//Gets the Y position of a cell
int CheckBox::getPlace() { return curY; }

//Sets a Cell's "Hover" to ture/false {Keyboard Use}
void CheckBox::setHover(COORD cur)
{
	//Sets cursors position
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, cur);

	//Swithces cell's "Hover" state and color scheme (true becomes false and vice versa)
	if (hover)
	{
		hover = false;
		//SetConsoleTextAttribute(h, clrNormal);
	}
	else
	{
		hover = true;
		//SetConsoleTextAttribute(h, 240);
	}
}

//Sets a Cell's "Hover" to true {Mouse Use}
void CheckBox::setHoverTrue(COORD& cur)
{
	//Changes the GLOBAL cursor's Y position to the objects position
	//And sets the colors to chosen scheme
	cur.Y = getPlace();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clrActive);

	//Sets the cell to "Hover"
	hover = true;
}

//Sets a Cell's "Hover" to false {Mouse Use}
void CheckBox::setHoverFalse(COORD cur)
{
	//Changes the LOCAL cursor's Y position to the objects position
	//And sets the colors to chosen scheme
	cur.Y = getPlace();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clrNormal);

	//Sets the cell to "Hover"
	hover = false;

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
		//cout << unchecked << " " << bName;
	}
	else
	{
		pressed = true;
		//cout << checked << " " << bName;
	}
}

//Returns Cell's selected/unselected status
bool CheckBox::getSwitchState() { return pressed; }

//Returns Cell's name/label
string CheckBox::getName() { return bName; }

//Returns Cell's lenght (from the first char "[" to the last)
int CheckBox::getLenght() { return iLenght; }