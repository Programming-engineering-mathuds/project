#include "Button.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

void Button::SetValue(string value)
{
	text = value;
	Label::SetValue(text);
	hight = 1;
}

void Button::AddListener(MouseListener &listener)
{
	listeners.push_back(&listener);
}

void Button::notify()
{
	for (int iterator = 0; iterator < listeners.size(); iterator++)
	{
		listeners[iterator]->MousePressed(*this, pos.X, pos.Y, 1);
	}
}

void Button::draw(Graphics &g, int left, int top, size_t layer)
{
	Label::draw(g, left, top, layer);
}


void Button::getInput(INPUT_RECORD in)
{
	switch (in.EventType)
	{
	case MOUSE_EVENT: // mouse input 
		MouseEvent(in.Event.MouseEvent);
		break;
	case FOCUS_EVENT:  // disregard focus events 
		break;
	default:
		exit(8);
		break;
	}
}

void Button::MouseEvent(MOUSE_EVENT_RECORD in)
{

	if (in.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
	{
		if (isInside(in.dwMousePosition.X, in.dwMousePosition.Y, mPos.X, mPos.Y, maxWidth + 1, hight))
			notify();
	}
}


void  Button::MousePressed(int x, int y, bool isLeft)
{
	int XL = mPos.X - 1;
	int XR = XL + maxWidth + 1;
	int YU = mPos.Y;
	int YD = YU + hight;
	if (isLeft)
	{
		if (((XL <= x) && (x <= XR)) && ((YU <= y) && (y <= YD)))
		{
			notify();

		}
	}
}