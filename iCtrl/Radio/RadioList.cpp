#include "RadioList.h"

//Constructor
RadioList::RadioList(int arrSize, COORD cur, int frameLines) : iCtrl(arrSize, cur)
{
	clrNum = 7;
	clrNumHvr = 240;
	//cList = new CheckBox[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		bList.push_back(CheckBox("item0" + to_string(i + 1), pos, hndl, clrNum, clrNumHvr));
		if (bList[i].iLenght > maxWidth) maxWidth = bList[i].iLenght;
	}
	bList[0].setActive(pos);
	color(clrNum);
	frame(arrSize, frameLines);
}

//Destructor
RadioList::~RadioList() {}

int RadioList::bListSize()
{
	return bList.size();
}

//CheckBox CheckList::getcList(int item)
//{
//	return cList[item];
//}

bool RadioList::isCellActive(int itemNum) { return bList[itemNum].isActive(); }

void RadioList::setCellActive(int itemNum, COORD pos) { bList[itemNum].setActive(pos); }

void RadioList::cellCoordinator(int itemNum, COORD& pos, string direction) { bList[itemNum].coordinator(pos, direction); }

//void CheckList::topBottomCoordinator(int itemNum, COORD& pos, string direction)
//{
//	cList[i]
//}

void RadioList::cellCheckSwitch(int itemNum, COORD pos) { bList[itemNum].checkSwitch(pos); }

int RadioList::getCellPlace(int itemNum) { return bList[itemNum].getPlace(); }

int RadioList::getCellLenght(int itemNum) { return bList[itemNum].getLenght(); }

void RadioList::setCellActiveFalse(int itemNum, COORD pos) { bList[itemNum].setActiveFalse(pos); }

void RadioList::setCellActiveTrue(int itemNum, COORD& pos) { bList[itemNum].setActiveTrue(pos); }

void RadioList::setRadio(int itemNum, COORD pos)
{
	for (int i = 0; i < bList.size() ; i++)
	{		
		if (i == itemNum)
		{
			SetConsoleTextAttribute(hndl, 240);
			SetConsoleCursorPosition(hndl, pos);
			bList[i].pressed = true;
			cout << "[X] " << bList[i].bName;
		}
		else
		{
			SetConsoleTextAttribute(hndl, 7);
			COORD c = { pos.X, pos.Y - itemNum + i};
			SetConsoleCursorPosition(hndl, c);
			bList[i].pressed = false;
			cout << "[ ] " << bList[i].bName;
		}
	}
}

