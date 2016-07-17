#pragma once

#include <windows.h>
#include <stdio.h>"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "iControl.h"
#include "Label.h"
#include "Button.h"
#include "vector"
using namespace std;

class keyButton : public Button
{

public:
	keyButton(int width) :Button(width){ setCanGetFocus(true); };
	~keyButton(){};

	virtual void draw(Graphics &g, int left, int top, size_t layer){Button::draw(g, left, top, layer);};
	//void MousePressed(int x, int y, bool isLeft){ Button::mousePressed(x, y, isLeft); };
	void keyDown(int keyCode, char charater);
	//virtual void getAllControls(vector < iControl * > *controls){};

};

