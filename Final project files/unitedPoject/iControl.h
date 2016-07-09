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
	int widthSetFlag=0;
	bool can_Get_Focus;//to be set in the controls themself
	bool focused = false;
	size_t _layer = 0;
	BorderType border= BorderType::None;
	COORD mPos;//coords for mouse use
	Graphics g;
	static vector<iControl*> controls;

public:
	iControl(int width) :maxWidth(width), pos(COORD{ 0, 0 }), mPos(COORD{ 0, 0 }), top(0), left(0){};
	~iControl() {};

	virtual void invisible(){ this->_layer = 6; };
	void setBorder(BorderType type){ border = type; };
	BorderType getBorder(){ return border; };
	void setTop(int tempTop) { top = tempTop; };
	int getTop() { return top; };
	void setLeft(int tempLeft){ left = tempLeft; };
	int getLeft() { return left; };
	void setCoords(COORD coord);
	COORD getCoords(){ return pos; };
	void setLocation(int x, int y);
	void setLayer(size_t layer) { _layer = layer; };
	size_t getLayer() { return _layer; };
	void setForeground(Color color){ g.setForeground(color); };
	void setBackground(Color color){ g.setBackground(color); };
	bool canGetFocus(){ return can_Get_Focus; };
	bool isFocused(){ return focused; };
	void unFocused(){ focused = false; };
	void setMaxWidth(int newMaxWidth){ maxWidth = newMaxWidth; };
	int getMaxWidth(){ return maxWidth; }
	void frame(int size);
	void setWidthSetFlag(){ widthSetFlag = 1; };
	int getWidthSetFlag(){ return widthSetFlag; };
	void setHight(int addToTop){ hight = hight + addToTop; };
	int getHight(){ return hight; };
	virtual void getAllControls(vector < iControl * > *controls) = 0;
	virtual void mousePressed(int x, int y, bool isLeft) = 0;// maybe change to size_t
	virtual void keyDown(int keyCode, char charater) = 0;
	virtual void draw(Graphics &g, int left, int top, size_t layer) = 0;
		//const { if (layer > _layer) return; }
	//	void color(int clrNum);
	//	void color2(Foreground clrNumFont, Background clrNumBG);

	static void setStaticControlList(static vector < iControl * > newControls)
	{
		controls = newControls;
	};
	static void setFocus(iControl &control)
	{
		for (int i = 0; i < controls.size(); i++)
		{
			if (controls[i]->getFocus())
			{
				controls[i]->unFocused();
			}
			control.focused = true;
		}
	};
	static iControl* getFocus()
	{
		for (int i = 0; i < controls.size(); i++)
		{
			if (controls[i]->isFocused()) return controls[i];
		}
	};
};

