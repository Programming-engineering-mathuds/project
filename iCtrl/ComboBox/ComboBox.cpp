#include "ComboBox.h"
#include "Cell.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

ComboBox::ComboBox(int arrSize, COORD cur, int frameLines) : iCtrl(arrSize, cur)
{
	//Theme Colors
	clrNum = 7;
	clrNumHvr = 240;

	//set cursor initial position
	SetConsoleCursorPosition(hndl, pos);

	label =  "[ Please Select an item | v ]";
	cout << label;
	for (int i = 0; i < arrSize; i++)
	{
		cBox.push_back(Cell("item0" + to_string(i + 1), pos, hndl, clrNum, clrNumHvr));
		if (cBox[i].iLenght > maxWidth) maxWidth = cBox[i].iLenght;
	}
	if (sizeof(label) > maxWidth) maxWidth = sizeof(label) + 1;
	color(clrNum);
	frame(arrSize+2, frameLines);
}

ComboBox::~ComboBox() { }

int ComboBox::cBoxSize() {	return cBox.size(); }

void ComboBox::revealAll()
{
	for (int i = 0; i < cBox.size(); i++)
	{
		cBox[i].reveal();

	}
	
}

void ComboBox::hideAll()
{
	for (int i = 0; i < cBox.size(); i++)
	{
		cBox[i].hide();
	}

}

int ComboBox::getCellPlace(int itemNum) { return cBox[itemNum].getPlace(); }

void ComboBox::cellCheckSwitch(int itemNum, COORD pos) { cBox[itemNum].checkSwitch(pos); }

void ComboBox::cellSetPressedColor(int itemNum, COORD pos) 
{ 
	cBox[itemNum].setPressedColor(pos); 
	hideAll();
}

void ComboBox::setCellActiveFalse(int itemNum, COORD pos) { cBox[itemNum].setActiveFalse(pos); }

void ComboBox::setCellActiveTrue(int itemNum, COORD& pos) { cBox[itemNum].setActiveTrue(pos); }

int ComboBox::getLabelsLenght()
{
	return sizeof(label);
}

bool ComboBox::isCellActive(int itemNum) { return cBox[itemNum].isActive(); }

void ComboBox::setCellActive(int itemNum, COORD pos) { cBox[itemNum].setActive(pos); }

void ComboBox::cellCoordinator(int itemNum, COORD& pos, string direction) { cBox[itemNum].coordinator(pos, direction); }
