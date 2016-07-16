#include "ComboBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

ComboBox::ComboBox(int width, vector<string> entries) : Panel(entries.size(), width), cBoxHeader(23, "Please Select An Item")
{
	setCanGetFocus(true);
	size = entries.size();
	cBoxMaxWidth = 0;
	for (int i = 0; i < size; i++)	{
		CheckBox tempBox(entries[i], width);
		cBox.push_back(tempBox);
		if (cBox[i].getMaxWidth() > cBoxMaxWidth) cBoxMaxWidth = cBox[i].getMaxWidth();
		cBox[i].setCanGetFocus(true);
	}
}

ComboBox::~ComboBox() { }

int ComboBox::cBoxSize() { return cBox.size(); }

bool ComboBox::getOpenState() { return isOpen; }

void ComboBox::toggleOpenState() {
	if (isOpen) isOpen = false;
	else isOpen = true;
}

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

void ComboBox::draw(Graphics &g, int left, int top, size_t layer) {
	if (getVisible()) {
		g.moveTo(left, top);
			COORD c = { left, top };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
			g.write("[ ");
			cBoxHeader.draw(g, left + 2, top, layer);
			c = { left + cBoxHeader.getMaxWidth(), top };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
			g.write(" | v ]");

			if (!getOpenState()) for (int i = 0; i < size; i++) cBox[i].Show();
			else for (int i = 0; i < size; i++) {
				cBox[i].Hide();
				g.write(left + 2, ++top, cBox[i].getName());
			}
	}
}

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	if (getVisible()) {
			COORD l = cBoxHeader.getCoords();
			COORD c = cBox[0].getCoords();

			if (getOpenState()){
				if ((y - 1 >= c.Y) && (y - 1 <= (c.Y + cBox.size() - 1)) && (x >= c.X) && (x <= 28)) {
					for (int i = 0; i < cBox.size(); i++) {
						if (i == y - 1 - c.Y) {
							cBoxHeader.SetValue(cBox[i].getName());
							toggleOpenState();
							draw(g, left, top, 0);
						}
					}
				}
			}
			else {
				if ((y == l.Y) && (x >= l.X) && (x <= 28)) {
					toggleOpenState();
					draw(g, left, top, 0);
				}
			}
	}	
}

void ComboBox::keyDown(int keyCode, char charater) {
	int i;
	COORD c = cBox[0].getCoords();

	if (keyCode == VK_UP) {
		for (i = 0; i < size; i++)	{
			if (cBox[i].isHover())	{
				if (cBox[i].pos.Y - 1 > c.Y)	{
					cBox[i].setHover();
					cBox[i - 1].setHover();
				}
			}
		}
	}
	if (keyCode == VK_DOWN) {
		for (i = 0; i < size; i++) {
			if (cBox[i].isHover())	{
				if (cBox[i].pos.Y + 1 < c.Y + (size - 1)){
					cBox[i].setHover();
					cBox[i + 1].setHover();
				}
			}
		}
	}
	if ((keyCode == 0x58) || (keyCode == VK_SPACE) || (keyCode == VK_RETURN)) { for (i = 0; i < cBox.size(); i++){}	}
	else printf("key released\n");
}