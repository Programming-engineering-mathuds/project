#include "Button.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
Button::Button(int width) :iCtrl(),Label(), width(width)
{

}
Button::~Button() {};
void Button::SetValue(string value)
{
	text = value;
	Label::changeText(text);
}
void Button::AddListener(MouseListener &listener)
{
	listeners.push_back(listener);
}

void Button::notify()
{
	for (int iterator = 0; iterator < listeners.size(); iterator++)
	{
		listeners[iterator].MousePressed(*this,x,y,isLeft);
	}
}

void Button::Draw()
{

}