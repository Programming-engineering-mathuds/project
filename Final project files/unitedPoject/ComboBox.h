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
	ComboLine *current = NULL;
	keyButton button;
	ComboListener listen;
	vector<ComboLineListener> listListen;
	int index = -1;
public:
	ComboBox(int width, vector<string> entries);
	~ComboBox(){};

	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index){};

	void openList();
	void closeList();

	void genericFunc1();
	void genericFunc3(int x, int y, bool arg);
	void draw(Graphics &g, int left, int top, size_t layer);
};

