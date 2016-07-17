#include "CheckBoxLine.h"

CheckBoxLine::CheckBoxLine(int width, string input) :keyButton(width), listener(*this)
{
	string temp = input;
	temp.insert(0, "    ");//spaceX4
	SetValue(temp);
	unPressedText = temp;
	input.insert(0, "X   ");//X spaceX3
	pressedText = input;
	AddListener(listener);
	setBorder(BorderType::Single);
}

void CheckBoxLine::press()
{
	SetValue(pressedText);
	pressed = true;
}
void CheckBoxLine::unPress()
{
	SetValue(unPressedText);
	pressed = false;
}

void CheckBoxLine::genericFunc1()
{
	if (isPressed()) unPress();
	else press();
}