#pragma once

#include <windows.h>
#include <stdio.h>
#include "../iCtrl/iCtrl.h"
#include "../Label/Label.h"
#include "../iCtrl/ConsoleForeground.h"
#include "../iCtrl/ConsoleBackground.h"
#include "vector"
using namespace std;

class Button : public iCtrl,public Label
{
	struct MouseListener
	{
		virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
	};
	vector <MouseListener> listeners;
	int width;
	string text;
	int x;
	int y;
	bool isLeft;
public:
	Button(int width);
	~Button();
	void SetValue(string value);
	void AddListener(MouseListener &listener);
	void notify();
	void Draw();
};

