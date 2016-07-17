#pragma once

#include <stdio.h>
#include "iControl.h"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "Panel.h"
#include "CheckBoxLine.h"
#include <ctime>

using namespace std;
class Radiolist;
struct CheckListener : public MouseListener
{
	CheckListener(iControl &n) :_n(n){}
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_n.genericFunc3(x,y,isLeft);
	}

private:
	iControl &_n;
};
class Radiolist : public Panel
{
	vector<CheckListener> listen;
	CheckBoxLine *hold;
	int index;
	vector<CheckBoxLine> lines;
	double seconds;
	int  timer = 0;
	int last = -1;
public:
	Radiolist(int height, int width, vector<string> options);
	~Radiolist(){};

	void AddControler(iControl& control, int left, int top){};

	void mousePressed(int x, int y, bool isLeft);
//	void keyDown(int keyCode, char charater);
	void draw(Graphics &g, int left, int top, size_t layer);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	void genericFunc3(int x, int y, bool arg);

};