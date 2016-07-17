#pragma once

#include <windows.h>
#include <stdio.h>"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "iControl.h"
#include "vector"
#include "Label.h"

using namespace std;

class TextBox : public Label
{
	COORD curCoord;
	string Text;
	void putText();
	int firstDrawSetCor = 0;
	bool imATextBox = FALSE;
public:
	
	bool isATextBox(){ return imATextBox; };;

	TextBox(int length);
	~TextBox(){};

	virtual void draw(Graphics &g, int left, int top, size_t layer);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater);
	virtual void getAllControls(vector < iControl * > *controls){};

};

