#pragma once
#include "CheckBox.h"
#include "panel.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "vector"
#include "CheckBoxLine.h"

using namespace std;

class CheckList : private Panel
{
private:
	vector<CheckBoxLine> List;
	size_t where_am_i;
	int size; // Number of cells in a Check List
public:
	CheckList(int height, int width, vector<string> entries);
	~CheckList();

	int cListSize();
	void setCheckbox(int x, int y);

	vector<size_t> GetSelectedIndices();
	void SelectedIndex(size_t index);
	void DeselectIndex(size_t index);

	void getAllControls(vector < iControl * > *controls) {};
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater);
	void draw(Graphics &g, int left, int top, size_t layer);
};