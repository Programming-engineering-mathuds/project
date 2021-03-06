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
private:
	string bName;
	int iLenght;
	int curY;
	bool pressed; //Active
	bool hover; 
	int clrNormal;
	int clrActive;
public:
	CheckBox(string name);
	~CheckBox();
	void coordinator(COORD& cur, string upDown);
	void checkSwitch(COORD cur);
	bool isHover();
	int getPlace();
	bool getSwitchState();
	string getName();
	int getLenght();
	void setHover(COORD cur);
	void setHoverTrue(COORD& cur);
	void setHoverFalse(COORD cur);
};

