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
	int size; // Number of cells in a Combobox List
	int cBoxMaxWidth;
	bool isOpen = false;
public:
	ComboBox(int width, vector<string> entries);
	~ComboBox(){};

	int cBoxSize();
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index){};
	bool getOpenState(){};
	void toggleOpenState(){};

	void getInput(KEY_EVENT_RECORD key) {};
	void getMouse(MOUSE_EVENT_RECORD mer) {};
	void handelInput(INPUT_RECORD input){};

	void getAllControls(vector < iControl * > *controls) {};
	void mousePressed(int x, int y, bool isLeft){};
	void keyDown(int keyCode, char charater){};
	void draw(Graphics &g, int left, int top, size_t layer){};
};

