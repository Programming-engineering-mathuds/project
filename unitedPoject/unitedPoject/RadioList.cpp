#include "RadioList.h"

//Constructor
RadioList::RadioList(int height, int width, vector<string> entries) : iControl(width)
{
	//clrNum = 7;
	//clrNumHvr = 240;
	//maxWidth = 0;
	//cList = new CheckBox[arrSize];
	can_Get_Focus = true;
	for (int i = 0; i < height; i++)
	{
		CheckBox a(entries[i]);
		bList.push_back(a);
		//if (bList[i].iLenght > maxWidth) maxWidth = bList[i].iLenght;
	}
	bList[0].setActive(pos);
	//color(clrNum);
	//frame(width, frameLines);
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

bool RadioList::isCellActive(int itemNum) {
	if (itemNum <= bList.size() - 1)
		return bList[itemNum].isActive();
}

void RadioList::setCellActive(int itemNum, COORD pos) {
	if (itemNum <= bList.size() - 1)
		bList[itemNum].setActive(pos);
}

void RadioList::cellCoordinator(int itemNum, COORD& pos, string direction) {
	if (itemNum <= bList.size() - 1)
		bList[itemNum].coordinator(pos, direction);
}

//void CheckList::topBottomCoordinator(int itemNum, COORD& pos, string direction)
//{
//	cList[i]
//}

void RadioList::cellCheckSwitch(int itemNum, COORD pos) {
	if (itemNum <= bList.size() - 1)
		bList[itemNum].checkSwitch(pos);
}

int RadioList::getCellPlace(int itemNum) {
	if (itemNum <= bList.size() - 1)
		return bList[itemNum].getPlace();
}

int RadioList::getCellLenght(int itemNum) {
	if (itemNum <= bList.size() - 1)
		return bList[itemNum].getLenght();
}

void RadioList::setCellActiveFalse(int itemNum, COORD pos) {
	if (itemNum <= bList.size() - 1)
		bList[itemNum].setActiveFalse(pos);
}

void RadioList::setCellActiveTrue(int itemNum, COORD& pos) {
	if (itemNum <= bList.size() - 1)
		bList[itemNum].setActiveTrue(pos);
}

void RadioList::setRadio(int x, int y)
{
	COORD c = bList[0].getCoords();
	for (int i = 0; i < bList.size(); i++)
	{
		if (i == y-c.Y)
		{
			SetConsoleTextAttribute(hndl, 240);
			SetConsoleCursorPosition(hndl, pos);
			bList[i].pressed = true;
			cout << "[X] " << bList[i].bName;
		}
		else
		{
			SetConsoleTextAttribute(hndl, 7);
			COORD c = { x, y - i };
			SetConsoleCursorPosition(hndl, c);
			bList[i].pressed = false;
			cout << "[ ] " << bList[i].bName;
		}
	}
}

void RadioList::setRadio(int itemNum, COORD pos)
{
	for (int i = 0; i < bList.size(); i++)
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
			COORD c = { pos.X, pos.Y - itemNum + i };
			SetConsoleCursorPosition(hndl, c);
			bList[i].pressed = false;
			cout << "[ ] " << bList[i].bName;
		}
	}
}

size_t RadioList::GetSelectedIndex()
{
	return where_am_i;
}

void RadioList::SetSelectedIndex(size_t index)
{
	where_am_i = index;
}

void RadioList::handelInput(INPUT_RECORD input)
{
	switch (input.EventType)
	{
	case KEY_EVENT: // keyboard input 
		getInput(input.Event.KeyEvent);
		break;

	case MOUSE_EVENT: // mouse input 
		getMouse(input.Event.MouseEvent);
		break;

	case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
		break;

	case FOCUS_EVENT:  // disregard focus events 

	case MENU_EVENT:   // disregard menu events 
		break;

	default:
		break;
	}

}

void RadioList::getInput(KEY_EVENT_RECORD key)
{
	////printf("Key event: ");
	//int i;
	//if (key.bKeyDown)
	//{
	//	//printf("key pressed\n");
	//	if (key.wVirtualKeyCode == VK_UP)
	//	{
	//		SetSelectedIndex(GetSelectedIndex() - 1);

	//	}
	//	if (key.wVirtualKeyCode == VK_DOWN)
	//	{
	//		for (i = 0; i < bList.bListSize(); i++)
	//		{
	//			if ((bList.isCellActive(i) == true) && (i + 1 < bList.bListSize()))
	//			{
	//				bList.setCellActive(i, cur);
	//				bList.cellCoordinator(i, cur, "down");
	//				bList.setCellActive(i + 1, cur);
	//				break;
	//			}
	//		}
	//		//printf("DOWN");
	//	}
	//	if ((key.wVirtualKeyCode == 0x58) || (key.wVirtualKeyCode == VK_SPACE) || (key.wVirtualKeyCode == VK_RETURN))
	//	{
	//		for (i = 0; i < bList.bListSize(); i++)
	//		{
	//			if ((bList.isCellActive(i) == true))
	//			{
	//				bList.setRadio(i, cur);
	//				break;
	//			}
	//		}
	//		//printf("Select");
	//	}
	//}
	////else printf("key released\n");
}

void RadioList::getMouse(MOUSE_EVENT_RECORD mer)
{

}

void RadioList::draw(Graphics &g, int left, int top, size_t layer) {
		g.moveTo(left, top);
		
		int tempLenght = 0;
		for (int i = 0; i < bList.size(); i++){
			if (bList[i].bName.length() > tempLenght) tempLenght = bList[i].bName.length();
		}

		tempLenght += 8;

		for (int i = 0; i < tempLenght; i++) g.write("=");

		COORD c = { left, ++top };
		SetConsoleCursorPosition(hndl, c);

		for (int i = 0 ; i < bList.size(); i++) {
			g.write("= [ ] ");
			g.write(bList[i].bName);
			COORD c = {tempLenght - 2, top };
			SetConsoleCursorPosition(hndl, c);
			g.write(" =");
			c = { left, ++top };
			SetConsoleCursorPosition(hndl, c);
		}

		for (int i = 0; i < tempLenght; i++) g.write("=");
}




