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

class Checklist : public Radiolist
{
	vector<CheckBoxLine> lines;
	vector<size_t> selectedLines;

public:
	Checklist(int height, int width, vector<string> options);
	~Checklist(){};
	
	void mousePressed(int x, int y, bool isLeft);

	void draw(Graphics &g, int left, int top, size_t layer);

	vector<size_t> GetSelectedIndices();
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);

};