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
	int iLenght;
	int curY;
	bool pressed; //Active
	bool hover;
	int clrNormal;
	int clrActive;
public:
	CheckBox(string name, int width);
	~CheckBox();
	void coordinator(COORD& cur, string upDown);
	void checkSwitch(COORD cur);
	bool isHover();
	int getPlace();
	bool getSwitchState();
	string getName();
	int getLenght();
	void setHover();
	void setHoverTrue(COORD& cur);
	void setHoverFalse(COORD cur);
	void reveal();
	void hide();

	void mousePressed(int x, int y, bool isLeft) {};
	void invisible();
	void setVisible(){ visible = true; };
};

