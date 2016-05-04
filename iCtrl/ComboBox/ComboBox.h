#pragma once
#include "../iCtrl/iCtrl.h"
#include "../iCtrl/ConsoleForeground.h"
#include "../iCtrl/ConsoleBackground.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include "Cell.h"
#include "vector"

using namespace std;

class ComboBox : public iCtrl
{
	vector<Cell> cBox;
	string label;
public:
	ComboBox(int arrSize, COORD cur, int frameLines);
	~ComboBox();

	int cBoxSize();
	void revealAll();
	void hideAll();
	int getCellPlace(int itemNum);
	void cellCheckSwitch(int itemNum, COORD pos);
	void cellSetPressedColor(int itemNum, COORD pos);
	void setCellActiveFalse(int itemNum, COORD pos);
	void setCellActiveTrue(int itemNum, COORD& pos);
	int getLabelsLenght();
};

