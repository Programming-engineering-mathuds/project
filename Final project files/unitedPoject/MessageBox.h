#pragma once

#include <windows.h>
#undef MessageBox

#include <stdio.h>
#include "iControl.h"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "Panel.h"
#include "Button.h"
#include "Label.h"
using namespace std;

struct BoxListener : public MouseListener
{
	BoxListener(iControl &c) : _c(c) { }
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.invisible();
	}
private:
	iControl &_c;
};

class MessageBox : public Panel
{
	Button button;
	Label text;
	Label title;
	BoxListener listner;
	bool visible=true;

	void setTextLabelSize(int height, int width);
	void setTitleLabelSize(int height, int width);
	void setButtonSize(int height, int width);

public:
	MessageBox(int height, int width);
	~MessageBox(){};

	void SetText(string text){this->text.SetValue(text);};
	void SetTitle(string title){this->title.SetValue(title);};
	void AddControler(iControl& control, int left, int top){};
	void draw(Graphics &g, int left, int top, size_t layer);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater){};
	void invisible();
	void setVisible(){visible = true;};
};