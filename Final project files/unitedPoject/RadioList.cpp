#include "RadioList.h"

//struct radioListener : public MouseListener
//{
//	radioListener(RadioList &r) : _r(r) { }
//	void  MousePressed(RadioList &rl, int x, int y, bool isLeft)
//	{
//		_r.setRadio(x, y);
//	}
//private:
//	RadioList &_r;
//};

//Constructor
RadioList::RadioList(int height, int width, vector<string> entries) : Panel(height, width)
{
	can_Get_Focus = true;
	size = height;
	for (int i = 0; i < height; i++)
	{
		CheckBox tempBox(entries[i], width);
		//radioListener lisenter(tempBox);
		rList.push_back(tempBox);
	}
	rList[0].setHover();
}

//Destructor
RadioList::~RadioList() {}

int RadioList::bListSize()
{
	return rList.size();
}

//CheckBox CheckList::getcList(int item)
//{
//	return cList[item];
//}

bool RadioList::isCellActive(int itemNum) {
	if (itemNum <= rList.size() - 1)
		return rList[itemNum].isHover();
}

void RadioList::setCellActive(int itemNum, COORD pos) {
	if (itemNum <= rList.size() - 1)
		rList[itemNum].setHover();
}

void RadioList::cellCoordinator(int itemNum, COORD& pos, string direction) {
	if (itemNum <= rList.size() - 1)
		rList[itemNum].coordinator(pos, direction);
}

//void CheckList::topBottomCoordinator(int itemNum, COORD& pos, string direction)
//{
//	cList[i]
//}

void RadioList::cellCheckSwitch(int itemNum, COORD pos) {
	if (itemNum <= rList.size() - 1)
		rList[itemNum].checkSwitch(pos);
}

int RadioList::getCellPlace(int itemNum) {
	if (itemNum <= rList.size() - 1)
		return rList[itemNum].getPlace();
}

int RadioList::getCellLenght(int itemNum) {
	if (itemNum <= rList.size() - 1)
		return rList[itemNum].getLenght();
}

void RadioList::setCellActiveFalse(int itemNum, COORD pos) {
	if (itemNum <= rList.size() - 1)
		rList[itemNum].setHoverFalse(pos);
}

void RadioList::setCellActiveTrue(int itemNum, COORD& pos) {
	if (itemNum <= rList.size() - 1)
		rList[itemNum].setHoverTrue(pos);
}

void RadioList::setRadio(int x, int y)
{
	//saves the position of the first cell (incase we start at different y then 0)
	COORD c = rList[0].getCoords();
	for (int i = 0; i < rList.size(); i++)
	{
		if ((y >= c.Y) && (y <= (c.Y + rList.size() - 1)) && (x >= c.X) && (x <= c.X + maxWidth))
		{
			if (i == y - c.Y)
			{
				rList[i].pressed = true;
				cout << "[X] " << rList[i].bName;
			}
			else		
				{
				rList[i].pressed = false;
				cout << "[ ] " << rList[i].bName;
				}
		}
		
	}
}

//void RadioList::setRadio(int itemNum, COORD pos)
//{
//	for (int i = 0; i < bList.size(); i++)
//	{
//		if (i == itemNum)
//		{
//			SetConsoleTextAttribute(hndl, 240);
//			SetConsoleCursorPosition(hndl, pos);
//			bList[i].pressed = true;
//			cout << "[X] " << bList[i].bName;
//		}
//		else
//		{
//			SetConsoleTextAttribute(hndl, 7);
//			COORD c = { pos.X, pos.Y - itemNum + i };
//			SetConsoleCursorPosition(hndl, c);
//			bList[i].pressed = false;
//			cout << "[ ] " << bList[i].bName;
//		}
//	}
//}

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
	/*#ifndef MOUSE_HWHEELED
	#define MOUSE_HWHEELED 0x0008
	#endif

	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
	{
	if (isInside(mer.dwMousePosition.X, mer.dwMousePosition.Y, mPos.X, mPos.Y, maxWidth + 1, hight))
	setRadio(mPos.X, mPos.Y);
	}
	*/

	//#ifndef MOUSE_HWHEELED
	//#define MOUSE_HWHEELED 0x0008
	//#endif
	//	//printf("Mouse event: ");
	//	switch (mer.dwEventFlags)
	//	{
	//	case 0:
	//
	//		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
	//		{
	//			for (int i = 0; i < bList.bListSize(); i++)
	//			{
	//				if ((mer.dwMousePosition.Y == bList.getCellPlace(i)) && (mer.dwMousePosition.X >= cur.X) && (mer.dwMousePosition.X < (cur.X + bList.getCellLenght(i))))
	//				{
	//					bList.setRadio(i, cur);
	//					break;
	//				}
	//			}
	//			//printf("left button press \n");
	//		}
	//		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
	//		{
	//			//printf("right button press \n");
	//		}
	//		else
	//		{
	//			//printf("button press\n");
	//		}
	//		break;
	//	case DOUBLE_CLICK:
	//		for (int i = 0; i < bList.bListSize(); i++)
	//		{
	//			if ((mer.dwMousePosition.Y == bList.getCellPlace(i)) && (mer.dwMousePosition.X >= cur.X) && (mer.dwMousePosition.X < (cur.X + bList.getCellLenght(i))))
	//			{
	//				bList.setRadio(i, cur);
	//				break;
	//			}
	//		}
	//		//printf("double click\n");
	//		break;
	//	case MOUSE_HWHEELED:
	//		//printf("horizontal mouse wheel\n");
	//		break;
	//	case MOUSE_MOVED:
	//		for (int i = 0; i < bList.bListSize(); i++)
	//		{
	//			if ((mer.dwMousePosition.Y == bList.getCellPlace(i)) && (mer.dwMousePosition.X >= cur.X) && (mer.dwMousePosition.X < (cur.X + bList.getCellLenght(i))))
	//			{
	//				for (int j = 0; j < bList.bListSize(); j++)
	//				{
	//					if (j != i)	bList.setCellActiveFalse(j, cur);
	//					else bList.setCellActiveTrue(i, cur);
	//				}
	//			}
	//		}
	//		//printf("mouse moved\n");
	//		break;
	//	case MOUSE_WHEELED:
	//		//printf("vertical mouse wheel\n");
	//		break;
	//	default:
	//		//printf("unknown\n");
	//		break;
	//	}
}

void RadioList::draw(Graphics &g, int left, int top, size_t layer) {
	g.moveTo(left, top);

	COORD c = { left, top };
	SetConsoleCursorPosition(hndl, c);

	for (int i = 0; i < size; i++) {
		if (rList[i].hover) {
			setBackground(Color::White);
			setForeground(Color::Black);
			if (!rList[i].pressed) g.write("[ ] ");
			else g.write("[X] ");
			g.write(rList[i].bName);
		} else {
			setBackground(Color::Black);
			setForeground(Color::White);
			if (!rList[i].pressed) g.write("[ ] ");
			else g.write("[X] ");
			g.write(rList[i].bName);
		}
		c = { left, ++top };
		SetConsoleCursorPosition(hndl, c);
	}
}

void RadioList::mousePressed(int x, int y, bool isLeft)
{
	//cout << bList.size();
	setRadio(x, y);
}

void RadioList::keyDown(int keyCode, char charater) {
	//printf("Key event: ");
	int i;
	COORD c = rList[0].getCoords();
		//printf("key pressed\n");
		if (keyCode == VK_UP)
		{
			for (i = 0; i < size; i++)
			{
				if (rList[i].isHover())
				{
					if (rList[i].curY - 1 > c.Y)
					{
						rList[i].setHover();
						rList[i - 1].setHover();
					}
				}
			}
			//SetSelectedIndex(GetSelectedIndex() - 1);
		}
		if (keyCode == VK_DOWN)
		{
			for (i = 0; i < size; i++)
			{
				if (rList[i].isHover())
				{
					if (rList[i].curY + 1 < c.Y + (size - 1))
					{
						rList[i].setHover();
						rList[i + 1].setHover();
					}
				}
			}
			//printf("DOWN");
		}
		if ((keyCode == 0x58) || (keyCode == VK_SPACE) || (keyCode == VK_RETURN))
		{
			for (i = 0; i < rList.size(); i++)
			{
				/*if ((bList.isCellActive(i) == true))
				{
					bList.setRadio(i, cur);
					break;
				}*/
			}
			//printf("Select");
		}
	else printf("key released\n");
}




