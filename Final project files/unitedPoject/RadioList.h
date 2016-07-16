#pragma once
#include "panel.h"
#include "CheckBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "vector"

using namespace std;

class RadioList : public Panel
{
private:
	vector<CheckBox> rList;
	size_t where_am_i;
	int size; // Number of cells in a Radio List
public:
	RadioList(int height, int width, vector<string> entries);
	~RadioList();

	int bListSize();
	void setRadio(int x, int y);

	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);

	void getInput(KEY_EVENT_RECORD key) {};
	void getMouse(MOUSE_EVENT_RECORD mer) {};
	void handelInput(INPUT_RECORD input);

	void getAllControls(vector < iControl * > *controls) {};
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater);
	void draw(Graphics &g, int left, int top, size_t layer);
};

