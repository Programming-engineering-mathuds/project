#include "CheckBox.h"
#include <windows.h>

// "width" holds the second value returned from the main & "name.length" is 
// being sent all the way down to iControl, which puts it in "maxWidth"
// bottom line - iLength != maxWidth
CheckBox::CheckBox(string name, int width) : Button(name.length())
{
	bName = name;
	hover = false;
	pressed = false;
}

CheckBox::~CheckBox() {}

//Gets "Acvite" State
bool CheckBox::isHover() { return hover; }

//Sets a Cell's "Hover" to ture/false {Keyboard Use}
void CheckBox::setHover()
{
	if (hover) hover = false;
	else hover = true;
}

//Returns Cell's selected/unselected status
bool CheckBox::isPressed() { return pressed; }

void CheckBox::setPressed(bool value) { pressed = value; }

//Returns Cell's name/label
string CheckBox::getName() { return bName; }

