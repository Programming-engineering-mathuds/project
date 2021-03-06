#include "CheckBoxLine.h"

CheckBoxLine::CheckBoxLine(int width, string input) :keyButton(width)//, listener(*this)
{
	setLocation(0, 0);
	string temp = input;
	temp.insert(0,"    ");//spaceX4
	SetValue(temp);
	unPressedText = temp;
	input.insert(0, "X   ");//X spaceX3
	pressedText = input;
//	AddListener(listener);
	setBorder(BorderType::Single);
}

void CheckBoxLine::press()
{
	SetValue(pressedText);
	time(&timeOfPress);
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


void CheckBoxLine::keyDown(int keyCode, char charater)
{
	if (keyCode == VK_RETURN || keyCode == VK_SPACE)
	{ 
		genericFunc1(); time(&timeOfPress); 
	}
	if (keyCode == VK_DOWN && NEXT != NULL)
	{
		setFocus(*this);
		setFocus(*NEXT);
	}
	if (keyCode == VK_UP && PREV != NULL)
	{
		setFocus(*this);
		setFocus(*PREV);
	}
}
