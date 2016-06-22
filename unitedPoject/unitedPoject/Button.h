#pragma once

#include <windows.h>
#include <stdio.h>"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "iControl.h"
#include "Label.h"
#include "vector"
using namespace std;

class Button;

struct MouseListener
{
	virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
};

class Button : public Label
{
protected:
	vector <MouseListener*> listeners;
	string text;
	bool isLeft = false;
public:
	Button(int width) :Label(width){};
	~Button(){};

	void SetValue(string value);
	void AddListener(MouseListener &listener);
	void notify();
	virtual void draw(Graphics &g, int left, int top, size_t layer);

	void getInput(INPUT_RECORD in);
	void MouseEvent(MOUSE_EVENT_RECORD in);
	void MousePressed(int x, int y, bool isLeft);
};

