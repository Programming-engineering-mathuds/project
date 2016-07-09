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


class MessageBox1 : public Panel
{
	Button button;
	Label text;
	Label title;

	void setTextLabelSize(int height, int width);
	void setTitleLabelSize(int height, int width);
	void setButtonSize(int height, int width);
	//void setPanelSize(int height, int width);

public:
	MessageBox1(int height, int width);
	~MessageBox1(){};

	void SetText(string text){this->text.SetValue(text);};
	void SetTitle(string title){this->title.SetValue(title);};

	//void draw(Graphics &g, int left, int top, size_t layer);
	//void getAllControls(vector < iControl * > *controls){};
	void mousePressed(int x, int y, bool isLeft){button.MousePressed(x, y, isLeft);	};
	void keyDown(int keyCode, char charater){};
	void invisible();

};