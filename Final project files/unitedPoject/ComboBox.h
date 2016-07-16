#pragma once
#include <Windows.h>
#include "panel.h"
#include <string>
#include <stdio.h>
#include "CheckBox.h"
#include "vector"
#include "Label.h"

using namespace std;

class ComboBox : public Panel
{
	vector<CheckBox> cBox;
	Label cBoxHeader;
	string label;
	int size;
	int cBoxMaxWidth;
	bool isOpen = false;
public:
	ComboBox(int width, vector<string> entries);
	~ComboBox();

	int cBoxSize();
	void revealAll();
	void hideAll();
	int getCellPlace(int itemNum);
	void cellCheckSwitch(int itemNum, COORD pos);
	void cellSetPressedColor(int itemNum, COORD pos);
	void setCellHoverFalse(int itemNum, COORD pos);
	void setCellHoverTrue(int itemNum, COORD& pos);
	int getLabelsLenght();
	bool isCellHover(int itemNum);
	void setCellHover(int itemNum, COORD pos);
	void cellCoordinator(int itemNum, COORD& pos, string direction);

	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);

	//void print();
	void getInput(KEY_EVENT_RECORD key);
	void getMouse(MOUSE_EVENT_RECORD mer);
	void handelInput(INPUT_RECORD input);

	void getAllControls(vector < iControl * > *controls) {};
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater);
	void draw(Graphics &g, int left, int top, size_t layer);
};

