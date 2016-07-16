#include "ComboBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

ComboBox::ComboBox(int width, vector<string> entries) : Panel(entries.size(), width), cBoxHeader(23, "Please Select An Item")
{
	can_Get_Focus = true;
	size = entries.size();
	cBoxMaxWidth = 0;
	for (int i = 0; i < size; i++)
	{
		CheckBox tempBox(entries[i], width);
		cBox.push_back(tempBox);
		if (cBox[i].getMaxWidth() > cBoxMaxWidth) cBoxMaxWidth = cBox[i].getMaxWidth();
	}


	//if (sizeof(label) > maxWidth) maxWidth = sizeof(label) + 1;
}

ComboBox::~ComboBox() { }

int ComboBox::cBoxSize() { return cBox.size(); }

void ComboBox::revealAll()
{
	for (int i = 0; i < cBox.size(); i++) {
		cBox[i].reveal();
	}
}

void ComboBox::hideAll()
{
	for (int i = 0; i < cBox.size(); i++) {
		cBox[i].hide();
	}
}

int ComboBox::getCellPlace(int itemNum) { return cBox[itemNum].getPlace(); }

void ComboBox::cellCheckSwitch(int itemNum, COORD pos) { cBox[itemNum].checkSwitch(pos); }

void ComboBox::cellSetPressedColor(int itemNum, COORD pos)
{
	//cBox[itemNum].setPressedColor(pos);
	hideAll();
}

void ComboBox::setCellHoverFalse(int itemNum, COORD pos) { cBox[itemNum].setHoverFalse(pos); }

void ComboBox::setCellHoverTrue(int itemNum, COORD& pos) { cBox[itemNum].setHoverTrue(pos); }

int ComboBox::getLabelsLenght()
{
	return sizeof(label);
}

bool ComboBox::isCellHover(int itemNum) { return cBox[itemNum].isHover(); }

void ComboBox::setCellHover(int itemNum, COORD pos) { cBox[itemNum].setHover(); }

void ComboBox::cellCoordinator(int itemNum, COORD& pos, string direction) { cBox[itemNum].coordinator(pos, direction); }


void ComboBox::handelInput(INPUT_RECORD input)
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

void ComboBox::getInput(KEY_EVENT_RECORD key)
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

void ComboBox::getMouse(MOUSE_EVENT_RECORD mer)
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

void ComboBox::draw(Graphics &g, int left, int top, size_t layer) {
	g.moveTo(left, top);
	COORD c = { left, top };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	g.write("[ ");
	cBoxHeader.draw(g, left + 2, top, layer);
	c = { left + cBoxHeader.getMaxWidth(), top };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	g.write(" | v ]");

	if (!isOpen) for (int i = 0; i < size; i++) cBox[i].invisible();
	else for (int i = 0; i < size; i++) {
		cBox[i].setVisible();
		g.write(left + 2, ++top, cBox[i].bName);
	}
}

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	//saves the position of the first cell (incase we start at different y then 0)
	COORD l = cBoxHeader.getCoords();
	COORD c = cBox[0].getCoords();

	cout << cBoxMaxWidth;

	if (isOpen){
		if ((y - 1 >= c.Y) && (y - 1 <= (c.Y + cBox.size() - 1)) && (x >= c.X) && (x <= 28)) {
			for (int i = 0; i < cBox.size(); i++) {
				if (i == y - 1 - c.Y) {
					cBoxHeader.SetValue(cBox[i].bName);
					isOpen = false;
					draw(g, left, top, 0);
				}
			}
		}
	}
	else {
		if ((y == l.Y) && (x >= l.X) && (x <= 28)) {
			isOpen = true;
			draw(g, left, top, 0);
		}
	}
}

void ComboBox::keyDown(int keyCode, char charater) {
	//printf("Key event: ");
	int i;
	COORD c = cBox[0].getCoords();
	//printf("key pressed\n");
	if (keyCode == VK_UP)
	{
		for (i = 0; i < size; i++)
		{
			if (cBox[i].isHover())
			{
				if (cBox[i].curY - 1 > c.Y)
				{
					cBox[i].setHover();
					cBox[i - 1].setHover();
				}
			}
		}
		//SetSelectedIndex(GetSelectedIndex() - 1);
	}
	if (keyCode == VK_DOWN)
	{
		for (i = 0; i < size; i++)
		{
			if (cBox[i].isHover())
			{
				if (cBox[i].curY + 1 < c.Y + (size - 1))
				{
					cBox[i].setHover();
					cBox[i + 1].setHover();
				}
			}
		}
		//printf("DOWN");
	}
	if ((keyCode == 0x58) || (keyCode == VK_SPACE) || (keyCode == VK_RETURN))
	{
		for (i = 0; i < cBox.size(); i++)
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