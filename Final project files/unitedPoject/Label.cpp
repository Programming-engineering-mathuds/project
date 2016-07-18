#include "Label.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

Label::Label(int width, string value):iControl(width),text(value),size(value.length())
{
	setCanGetFocus(false);
	setCoords(COORD{ 0, 0 });
	_layer = 0;
}

void Label::SetValue(string value)
{
	text = value;
	size = text.length();
	if (getMaxWidth() > size){}
	else setMaxWidth(size);
}

void Label::handelInput(INPUT_RECORD input)
{
	switch (input.EventType)
	{
	case KEY_EVENT: // keyboard input 
		break;

	case MOUSE_EVENT: // mouse input 
		break;

	default:
		break;
	}

}

void Label::putText()
{
	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(hndl, &cci);
	SetConsoleCursorPosition(hndl, pos);
	for (int i = 0; i < size; i++)
	{
		putchar(text[i]);
	}
}

void Label::draw(Graphics &g, int left, int top, size_t layer)
{
	if (getVisible())
	{
		setColor();
		if (layer != _layer) return;
		iControl::g = g;
		COORD cur = { left, top };
		setCoords(cur);
		putText();
		frame(1);
		returnColor();
	}
}
