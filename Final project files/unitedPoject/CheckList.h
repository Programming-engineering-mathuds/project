#pragma once
#include "CheckBox.h"
#include "panel.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "vector"
//#include "Button.h"

using namespace std;

class CheckList : public Panel
{
private:
	//CheckBox* cList;
	vector<CheckBox> cList;
	size_t where_am_i;
	int size;
public:
	CheckList(int height, int width, vector<string> entries);
	~CheckList();

	int cListSize();
	//CheckBox getcList(int item);
	bool isCellHover(int itemNum);
	void setCellHover(int itemNum, COORD pos);
	void cellCoordinator(int itemNum, COORD& pos, string direction);
	//void topBottomCoordinator(int itemNum, COORD& pos, string direction);
	void cellCheckSwitch(int itemNum, COORD pos);
	int getCellPlace(int itemNum);
	int getCellLenght(int itemNum);
	void setCellHoverFalse(int itemNum, COORD pos);
	void setCellHoverTrue(int itemNum, COORD& pos);
	void setCheckbox(int x, int y);

	vector<size_t> GetSelectedIndices();
	void SelectedIndex(size_t index);
	void DeselectIndex(size_t index);

	//void print();
	void getInput(KEY_EVENT_RECORD key);
	void getMouse(MOUSE_EVENT_RECORD mer);
	void handelInput(INPUT_RECORD input);

	void getAllControls(vector < iControl * > *controls) {};
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater);
	void draw(Graphics &g, int left, int top, size_t layer);
};