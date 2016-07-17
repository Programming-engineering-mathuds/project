#pragma once

#include <stdio.h>"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "keyButton.h"
#include "vector"
using namespace std;

struct CheckListener : public MouseListener
{
	CheckListener(iControl &n) :_n(n){}
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_n.genericFunc1();
	}
private:
	iControl &_n;
};
class CheckBoxLine : public keyButton
{
	bool pressed = false;
	CheckListener listener;
	string pressedText;
	string unPressedText;

public:
	CheckBoxLine(int width, string input);
	~CheckBoxLine(){};

	void press();
	void unPress();
	bool isPressed(){ return pressed; };
	void genericFunc1();

};
