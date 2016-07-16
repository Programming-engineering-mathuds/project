#pragma once

#include <windows.h>
#include <stdio.h>
#include "iControl.h"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
using namespace std;

class Label: public iControl
{
	string text;
	int size;

	COORD init;
public:
	Label(int width, string value);
	Label(int width) :iControl(width){};
	~Label(){};

	void SetValue(string value);

	void handelInput(INPUT_RECORD input);
	void putText();
	virtual void draw(Graphics &g, int left, int top, size_t layer);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	void keyDown(int keyCode, char charater) {};
	virtual void getAllControls(vector < iControl * > *controls){};
};

