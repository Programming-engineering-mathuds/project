#include "Label.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

//Label::Label(string text, int arrSize, COORD cor, int frameS) :iControl(arrSize, cor), text(text), size(text.length()), frameSize(frameS)
//{
//	maxWidth = text.length();
//	init = { 2, 2 };
	//print();
//	putText();
//	iControl::frame(1, 2);

//}
//Label::Label() :iControl()
//{
	//init = { 2, 2 };
	//print();
	//putText();
//}

Label::Label(int width, string value):iControl(width),text(value),size(value.length())
{
	can_Get_Focus = false;
	setCoords(COORD{ 0, 0 });
	_layer = 0;
}

void Label::handelInput(INPUT_RECORD input)
{
	switch (input.EventType)
	{
	case KEY_EVENT: // keyboard input 
		getInput(input.Event.KeyEvent);
		break;

	case MOUSE_EVENT: // mouse input 
		getMouse(input.Event.MouseEvent);
		break;

	default:
		break;
	}

}
void Label::SetValue(string value)
{
	text = value;
	size = text.length();
	//putText();
	//print();
}

void Label::putText()
{
	///COORD cur = pos;
	//COORD cur;
	//cur.X = pos.X + 1;
	//cur.Y = pos.Y + 1;


	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(hndl, &cci);
	SetConsoleCursorPosition(hndl, pos);
	for (int i = 0; i < size; i++)
	{
		putchar(text[i]);
	}
}

void Label::getMouse(MOUSE_EVENT_RECORD mer)
{

}

void Label::getInput(KEY_EVENT_RECORD key)
{

}
void Label::draw(Graphics &g, int left, int top, size_t layer)
{
	if (layer > _layer) return;
	iControl::g = g;
	COORD cur = { left, top };
	//pos.X = left;
	//pos.Y = top;
	setCoords(cur);
	putText();
	frame(1, 2);
}
