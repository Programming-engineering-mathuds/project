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

