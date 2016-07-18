#pragma once

#include <stdio.h>"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "keyButton.h"
#include "vector"
#include <ctime>
using namespace std;
/*
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
*/
class CheckBoxLine : public keyButton
{
	bool Hover = false;
	bool pressed = false;
//	CheckListener listener;
	string pressedText;
	string unPressedText;
	time_t timeOfPress;
public:
	CheckBoxLine(int width, string input);
	~CheckBoxLine(){};

	bool isHover(){return Hover;};
	bool setHover(){ if (Hover)Hover = false; else Hover = true; };
	void press();
	void unPress();
	bool isPressed(){ return pressed; };
	void genericFunc1();
	time_t  getTime(){ return timeOfPress; };
	void setTime(size_t t){ timeOfPress = t; };
	void setTime(time_t  t){ timeOfPress = t; };
	void keyDown(int keyCode, char charater) { if (keyCode == VK_RETURN)genericFunc1(); time(&timeOfPress); };
};
