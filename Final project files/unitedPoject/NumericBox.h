#pragma once

#include <windows.h>
#include <stdio.h>
#include "iControl.h"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "Panel.h"
#include "Button.h"
#include "Label.h"
using namespace std;

class NumericBox;

struct MinusListener : public MouseListener
{
	MinusListener(iControl &n) :_n(n){}
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_n.genericFunc2();
	}
private:
	iControl &_n;
};

struct PlusListener : public MouseListener
{
	PlusListener(iControl &c) :_n(c) { }
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_n.genericFunc1();
	}
private:
	iControl &_n;
};

class NumericBox : public Panel
{
	int value;
	MinusListener minus;
	PlusListener plus;
	Button plus_button;
	Button minus_button;
	Label screen;
	int maxValue;
	int minValue;

	void setButtonSize(int height, int width);

public:
	NumericBox(int width, int min, int max);
	~NumericBox(){};

	void AddControler(iControl& control, int left, int top){};
	void draw(Graphics &g, int left, int top, size_t layer);

	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater){};
	
	void inc();
	void dec();
	void genericFunc1(){ NumericBox::inc(); };
	void genericFunc2(){ NumericBox::dec(); };
	int GetValue(){return value;};
	bool SetValue(int value);//true if value is in range
};