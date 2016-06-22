#pragma once
#include <Windows.h>
#include <string>
#include <stdio.h>
#include "vector"
#include "ConsoleBackground.h"
#include "ConsoleForeground.h"
#include <iterator>
#include "Graphics.h"
#include <iostream>
#include "BorderType.h"
using namespace std;

class iControl
{
protected:
	COORD pos;
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	int clrNum;
	int clrNumHvr;
	int area;
	int maxWidth;
	int hight;
	int top;
	int left;
	bool can_Get_Focus;//to be set in the controls themself
	bool focused = false;
	size_t _layer = 0;
	BorderType border;
	COORD mPos;//coords for mouse use
	Graphics g;
public:
	static vector<iControl*> controls;
	//iControl(int arrSize, COORD cur);
	iControl(int width) :maxWidth(width), pos(COORD{ 0, 0 }), mPos(COORD{ 0, 0 }), top(0), left(0){};
	~iControl() {};

	void setBorder(BorderType type){ border = type; };
	BorderType getBorder(){ return border; };
	void setTop(int tempTop) { top = tempTop; };
	void setLeft(int tempLeft){ left = tempLeft; };
	void setCoords(COORD coord);
	void frame(int size, int frameLines);
	void color(int clrNum);
	void color2(Foreground clrNumFont, Background clrNumBG);
	bool canGetFocus(){return can_Get_Focus;};
	virtual void  MousePressed(int x, int y, bool isLeft) = 0;// maybe change to size_t
	virtual void keyDown(int keyCode, char charater) = 0;
	bool isFocused(){ return focused; };
	void unFocused(){ focused = false; };
	size_t getLayer() {	return _layer;	};
	void setLayer(size_t layer) {_layer = layer;};
	int getLeft() { return left;};
	int getTop() { return top; };
	virtual void draw(Graphics &g, int left, int top, size_t layer) = 0;
		//const { if (layer > _layer) return; }
	void setForeground(Color color);
	static iControl* getFocus(){
		for (int i = 0; i < controls.size(); i++)
		{
			if (controls[i]->getFocus()) return controls[i];
		}
	};
	static void setFocus(iControl &control)
	{
		for (int i = 0; i < controls.size(); i++)
		{
			if (controls[i]->getFocus())
			{
				controls[i]->unFocused();
				break;
			}
			control.focused = true;
		}
	}
};

