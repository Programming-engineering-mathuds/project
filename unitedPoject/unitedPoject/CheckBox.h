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
	bool pressed;
	bool active;
	int clrNormal;
	int clrActive;
public:
	CheckBox(string name);
	~CheckBox();
	void coordinator(COORD& cur, string upDown);
	void checkSwitch(COORD cur);
	bool isActive();
	int getPlace();
	bool getSwitchState();
	string getName();
	int getLenght();
	void setActive(COORD cur);
	void setActiveTrue(COORD& cur);
	void setActiveFalse(COORD cur);
};

