#pragma once
#include <Windows.h>
#include <string>
#include <stdio.h>

using namespace std;

class CheckList
{
private:
	string bName;
	int iLenght;
	int curY;
	bool pressed;
	bool active;
public:
	CheckList(string name, COORD cur);
	~CheckList();
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