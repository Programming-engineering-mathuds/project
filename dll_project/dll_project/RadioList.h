#pragma once
#include "iControl.h"
#include "CheckBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "vector"

using namespace std;

class RadioList : public iControl
{
private:
	//CheckBox* bList;
	vector<CheckBox> bList;
	size_t where_am_i;
public:
	RadioList(int height, int width, vector<string> entries);
	~RadioList();

	int bListSize();
	//CheckBox getcList(int item);
	bool isCellActive(int itemNum);
	void setCellActive(int itemNum, COORD pos);
	void cellCoordinator(int itemNum, COORD& pos, string direction);
	//void topBottomCoordinator(int itemNum, COORD& pos, string direction);
	void cellCheckSwitch(int itemNum, COORD pos);
	int getCellPlace(int itemNum);
	int getCellLenght(int itemNum);
	void setCellActiveFalse(int itemNum, COORD pos);
	void setCellActiveTrue(int itemNum, COORD& pos);
	void setRadio(int x, int y);
	void setRadio(int itemNum, COORD pos);

	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);

	//void print();
	void getInput(KEY_EVENT_RECORD key);
	void getMouse(MOUSE_EVENT_RECORD mer);
	void handelInput(INPUT_RECORD input);

	void MousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater) {};
	void draw(Graphics &g, int left, int top, size_t layer);
};

//struct radioListener : public MouseListener
//{
//	radioListener(RadioList &r) : _r(r) { }
//	void  MousePressed(RadioList &rl, int x, int y, bool isLeft)
//	{
//		_r.setRadio(x, y);
//	}
//private:
//	RadioList &_r;
//};