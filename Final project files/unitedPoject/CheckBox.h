#pragma once
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Button.h"

using namespace std;

class CheckBox : public Button
{
	friend class RadioList;
	friend class CheckList;
	friend class ComboBox;
private:
	string bName;
	bool pressed; //Active
	bool hover;
public:
	CheckBox(string name, int width);
	~CheckBox();
	bool isHover();
	bool isPressed();
	void setPressed(bool value);
	string getName();
	void setHover();

	void mousePressed(int x, int y, bool isLeft) {};
};

