#pragma once

#include <stdio.h>
#include "iControl.h"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
#include "Panel.h"
#include "CheckBoxLine.h"

using namespace std;

class Radiolist : public Panel
{
	CheckBoxLine *hold;
	int index;
	vector<CheckBoxLine> lines;

public:
	Radiolist(int height, int width, vector<string> options);
	~Radiolist(){};

	void AddControler(iControl& control, int left, int top){};

	void mousePressed(int x, int y, bool isLeft);

	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);


};