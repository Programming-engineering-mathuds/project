#include "CheckList.h"
#include "vector"



//Constructor
CheckList::CheckList(int height, int width, vector<string> entries) : Panel(height, width)
{
	can_Get_Focus = true;
	size = height;
	for (int i = 0; i < height; i++)
	{
		CheckBox tempBox(entries[i], width);
		cList.push_back(tempBox);
	}
	//cList[0].setHover();
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

bool CheckList::isCellHover(int itemNum) { return cList[itemNum].isHover(); }

void CheckList::setCellHover(int itemNum, COORD pos) { cList[itemNum].setHover(); }

void CheckList::cellCoordinator(int itemNum, COORD& pos, string direction) { cList[itemNum].coordinator(pos, direction); }

//void CheckList::topBottomCoordinator(int itemNum, COORD& pos, string direction)
//{
//	cList[i]
//}

void CheckList::cellCheckSwitch(int itemNum, COORD pos) { cList[itemNum].checkSwitch(pos); }

int CheckList::getCellPlace(int itemNum) { return cList[itemNum].getPlace(); }

int CheckList::getCellLenght(int itemNum) { return cList[itemNum].getLenght(); }

void CheckList::setCellHoverFalse(int itemNum, COORD pos) { cList[itemNum].setHoverFalse(pos); }

void CheckList::setCellHoverTrue(int itemNum, COORD& pos) { cList[itemNum].setHoverTrue(pos); }

vector<size_t> CheckList::GetSelectedIndices() {
	vector<size_t> tempIndexVector;
	for (int i = 0; i < size; i++)	{
		tempIndexVector[i] = cList[i].pressed;
	}
	return tempIndexVector;
}

void CheckList::SelectedIndex(size_t index) {
	for (int i = 0; i < size; i++)	{
		if (i == index){
			cList[i].pressed = true;
		}
	}
}

void CheckList::DeselectIndex(size_t index) {
	for (int i = 0; i < size; i++)	{
		if (i == index){
			cList[i].pressed = false;
		}
	}
}

void CheckList::setCheckbox(int x, int y)
{
	//saves the position of the first cell (incase we start at different y then 0)
	COORD c = cList[0].getCoords();
	for (int i = 0; i < cList.size(); i++)
	{
		if ((y >= c.Y) && (y <= (c.Y + cList.size() - 1)) && (x >= c.X) && (x <= c.X + maxWidth)) {
			if (i == y - c.Y) {
				if (cList[i].pressed) DeselectIndex(i);
				else SelectedIndex(i);
			}
		}
	}
}


void CheckList::handelInput(INPUT_RECORD input)
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

void CheckList::getInput(KEY_EVENT_RECORD key)
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

void CheckList::getMouse(MOUSE_EVENT_RECORD mer)
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

void CheckList::draw(Graphics &g, int left, int top, size_t layer) {
	g.moveTo(left, top);

	COORD c = { left, top };
	SetConsoleCursorPosition(hndl, c);

	for (int i = 0; i < size; i++) {
		if (cList[i].hover) {
			setBackground(Color::White);
			setForeground(Color::Black);
			if (!cList[i].pressed) g.write("[ ] ");
			else g.write("[X] ");
			g.write(cList[i].bName);
		}
		else {
			setBackground(Color::Black);
			setForeground(Color::White);
			if (!cList[i].pressed) g.write("[ ] ");
			else g.write("[X] ");
			g.write(cList[i].bName);
		}
		c = { left, ++top };
		SetConsoleCursorPosition(hndl, c);
	}
}

void CheckList::mousePressed(int x, int y, bool isLeft)
{
	//cout << bList.size();
	setCheckbox(x, y);
}

void CheckList::keyDown(int keyCode, char charater) {
	//printf("Key event: ");
	int i;
	COORD c = cList[0].getCoords();
	//printf("key pressed\n");
	if (keyCode == VK_UP)
	{
		for (i = 0; i < size; i++)
		{
			if (cList[i].isHover())
			{
				if (cList[i].curY - 1 > c.Y)
				{
					cList[i].setHover();
					cList[i - 1].setHover();
				}
			}
		}
		//SetSelectedIndex(GetSelectedIndex() - 1);
	}
	if (keyCode == VK_DOWN)
	{
		for (i = 0; i < size; i++)
		{
			if (cList[i].isHover())
			{
				if (cList[i].curY + 1 < c.Y + (size - 1))
				{
					cList[i].setHover();
					cList[i + 1].setHover();
				}
			}
		}
		//printf("DOWN");
	}
	if ((keyCode == 0x58) || (keyCode == VK_SPACE) || (keyCode == VK_RETURN))
	{
		for (i = 0; i < cList.size(); i++)
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