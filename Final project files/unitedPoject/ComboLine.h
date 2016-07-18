#pragma once

#include <stdio.h>"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "keyButton.h"
#include "vector"
#include <ctime>
using namespace std;

class ComboLine : public keyButton
{
	bool Hover = false;
	bool pressed = false;
	//	CheckListener listener;

	time_t timeOfPress;
public:
	ComboLine(int width, string input);
	~ComboLine(){};

	bool isHover(){ return Hover; };
	void setHover(){ if (Hover)Hover = false; else Hover = true; };
	void press();
	void unPress();
	bool isPressed(){ return pressed; };
	void genericFunc1();
	time_t  getTime(){ return timeOfPress; };
	void setTime(size_t t){ timeOfPress = t; };
	void setTime(time_t  t){ timeOfPress = t; };
	void keyDown(int keyCode, char charater) { if (keyCode == VK_RETURN)genericFunc1(); time(&timeOfPress); };
};