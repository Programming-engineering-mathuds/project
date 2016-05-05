#pragma once
#include <Windows.h>
#include <string>
#include <stdio.h>

using namespace std;

class Cell
{
	friend class ComboBox;
private:
	string bName;
	COORD c;
	bool pressed;
	bool active;
	int iLenght;
public:
	Cell(string objName, COORD pos, HANDLE hndl, int clrNum, int clrNumHvr);
	~Cell();
	void coordinator(COORD& cur, string upDown);
	void checkSwitch(COORD cur);
	bool isActive();
	int getPlace();
	bool getSwitchState();
	void setName();
	string getName();
	void setActive(COORD cur);
	void setActiveTrue(COORD& cur);
	void setActiveFalse(COORD cur);
	void setPressedColor(COORD cur);
	void reveal();
	void hide();


};

