#pragma once

#include <stdio.h>
#include "iControl.h"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "Panel.h"
#include "CheckBoxLine.h"
#include <ctime>
#include "RadioList.h"

using namespace std;
class Checklist;
struct CheckListListener : public MouseListener
{
	CheckListListener(iControl &n) :_n(n){}
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_n.genericFunc3(x, y, isLeft);
	}

private:
	iControl &_n;
};
class Checklist : public Radiolist
{
	vector<CheckBoxLine> lines;
	vector<CheckBoxLine> slectedLines;

public:
	Checklist(int height, int width, vector<string> options);
	~Checklist(){};
	
	void mousePressed(int x, int y, bool isLeft);

	void draw(Graphics &g, int left, int top, size_t layer);

};