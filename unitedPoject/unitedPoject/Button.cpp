#include "Button.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
Button::Button(int width) :Label(width){}
Button::~Button() {};

void Button::SetValue(string value)
{
	text = value;
	Label::SetValue(text);

}
void Button::AddListener(MouseListener &listener)
{
	listeners.push_back(&listener);
}

void Button::notify()
{
	for (int iterator = 0; iterator < listeners.size(); iterator++)
	{
		listeners[iterator]->MousePressed(*this, pos.X, pos.Y, isLeft);
	}
	///to delete
	draw(g, left, top, 0);
}

void Button::draw(Graphics &g, int left, int top, size_t layer)
{
	//x = left;
	//y = top;
	Label::draw(g, left, top, layer);
}

void Button::input()
{

}

void Button::getInput(INPUT_RECORD in)
{
	switch (in.EventType)
	{
	case KEY_EVENT: // keyboard input 
		break;

	case MOUSE_EVENT: // mouse input 
		MouseEvent(in.Event.MouseEvent);
		break;

	case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 

		break;

	case FOCUS_EVENT:  // disregard focus events 

	case MENU_EVENT:   // disregard menu events 
		break;

	default:
		exit(8);
		break;
	}
}

void Button::MouseEvent(MOUSE_EVENT_RECORD in)
{/*
	int XL = mPos.X - 1;
	//int XR = pos.X + maxWidth;
	int XR = XL + maxWidth + 1;
	int YU = mPos.Y;
	int YD = YU + hight;
	*/
	if (in.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
	{
		//if (((XL <= in.dwMousePosition.X) && (in.dwMousePosition.X <= XR)) && ((YU <= in.dwMousePosition.Y) && (in.dwMousePosition.Y <= YD)))
		//{
		if (isInside(in.dwMousePosition.X, in.dwMousePosition.Y, mPos.X, mPos.Y, maxWidth + 1, hight))
			notify();
			
		//}
	}
}
//needed to be removed when refactoring
void  Button::MousePressed(int x, int y, bool isLeft)
{
	int XL = mPos.X - 1;
	//int XR = pos.X + maxWidth;
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