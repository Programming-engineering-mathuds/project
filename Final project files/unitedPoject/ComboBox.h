#pragma once
#include <Windows.h>
#include "panel.h"
#include <stdio.h>
#include "ComboLine.h"
#include "vector"
#include "Label.h"
#include "keyButton.h"

using namespace std;


class ComboBox;
struct ComboListener : public MouseListener
{
	ComboListener(iControl &n) :_n(n){}
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_n.genericFunc1();
	}

private:
	iControl &_n;
};

struct ComboLineListener : public MouseListener
{
	ComboLineListener(iControl &n) :_n(n){}
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_n.genericFunc3(x, y, isLeft);
	}

private:
	iControl &_n;
};

class ComboBox : public Panel
{
	vector<ComboLine> boxList;
	string label;
	Label BoxHeader;


	bool isOpen = false;
	ComboLine *last = NULL;
//	ComboLine *current = NULL;
	keyButton button;
	ComboListener listen;
	vector<ComboLineListener> listListen;
public:
	ComboBox(int width, vector<string> entries);
	~ComboBox(){};

	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index){};

	void openList();
	void closeList();

	void genericFunc1();
	void genericFunc3(int x, int y, bool arg);

//	void getInput(KEY_EVENT_RECORD key) {};
//	void getMouse(MOUSE_EVENT_RECORD mer) {};
//	void handelInput(INPUT_RECORD input){};
//
	//void mousePressed(int x, int y, bool isLeft){};
//	void keyDown(int keyCode, char charater){};
//	void draw(Graphics &g, int left, int top, size_t layer){};
};

