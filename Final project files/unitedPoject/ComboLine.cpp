#include "ComboLine.h"

ComboLine::ComboLine(int width, string input) :keyButton(width)//, listener(*this)
{
	setLocation(0, 0);
	SetValue(input);
	setBorder(BorderType::Single);
}

void ComboLine::press()
{
	time(&timeOfPress);
	pressed = true;
}
void ComboLine::unPress()
{
	pressed = false;
}

void ComboLine::genericFunc1()
{
	if (isPressed() == false)press();
}

void ComboLine::keyDown(int keyCode, char charater)
{
	if (keyCode == VK_RETURN || keyCode == VK_SPACE)
	{
		genericFunc1(); time(&timeOfPress); pressedBykey = true;
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


