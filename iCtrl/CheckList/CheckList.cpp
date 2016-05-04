#include "CheckList.h"
#include "vector"



//Constructor
CheckList::CheckList(int arrSize, COORD cur, int frameLines) : iCtrl(arrSize, cur)
{
	clrNum = 7;
	clrNumHvr = 240;
	//cList = new CheckBox[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		cList.push_back(CheckBox("item0" + to_string(i + 1), pos, hndl, clrNum, clrNumHvr));
		if (cList[i].iLenght > maxWidth) maxWidth = cList[i].iLenght;
	}
	cList[0].setActive(pos);
	color(clrNum);
	frame(arrSize, frameLines);
}

//Destructor
CheckList::~CheckList() {}

int CheckList::cListSize()
{
	return cList.size();
}

//CheckBox CheckList::getcList(int item)
//{
//	return cList[item];
//}

bool CheckList::isCellActive(int itemNum) { return cList[itemNum].isActive(); }

void CheckList::setCellActive(int itemNum, COORD pos) { cList[itemNum].setActive(pos); }

void CheckList::cellCoordinator(int itemNum, COORD& pos, string direction) { cList[itemNum].coordinator(pos, direction); }

//void CheckList::topBottomCoordinator(int itemNum, COORD& pos, string direction)
//{
//	cList[i]
//}

void CheckList::cellCheckSwitch(int itemNum, COORD pos) { cList[itemNum].checkSwitch(pos); }

int CheckList::getCellPlace(int itemNum) { return cList[itemNum].getPlace(); }

int CheckList::getCellLenght(int itemNum) { return cList[itemNum].getLenght(); }

void CheckList::setCellActiveFalse(int itemNum, COORD pos) { cList[itemNum].setActiveFalse(pos); }

void CheckList::setCellActiveTrue(int itemNum, COORD& pos) { cList[itemNum].setActiveTrue(pos); }
