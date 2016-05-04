#pragma once
#include "../iCtrl/iCtrl.h"
#include "CheckBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "vector"
#include "../iCtrl/ConsoleForeground.h"
#include "../iCtrl/ConsoleBackground.h"

using namespace std;

class RadioList : public iCtrl
{
private:
	//CheckBox* bList;
	vector<CheckBox> bList;
public:
	RadioList(int arrSize, COORD cur, int frameLines);
	~RadioList();

	int bListSize();
	//CheckBox getcList(int item);
	bool isCellActive(int itemNum);
	void setCellActive(int itemNum, COORD pos);
	void cellCoordinator(int itemNum, COORD& pos, string direction);
	//void topBottomCoordinator(int itemNum, COORD& pos, string direction);
	void cellCheckSwitch(int itemNum, COORD pos);
	int getCellPlace(int itemNum);
	int getCellLenght(int itemNum);
	void setCellActiveFalse(int itemNum, COORD pos);
	void setCellActiveTrue(int itemNum, COORD& pos);
	void setRadio(int itemNum, COORD pos);
};
