#include "RadioList.h"

//Constructor
RadioList::RadioList(int height, int width, vector<string> entries) : Panel(height, width)
{
	setCanGetFocus(true);
	size = height;
	for (int i = 0; i < height; i++) {
		CheckBox tempBox(entries[i], width);
		rList.push_back(tempBox);
		rList[i].setCanGetFocus(true);
	}
}

//Destructor
RadioList::~RadioList() {}

int RadioList::bListSize() { return rList.size(); }

void RadioList::setRadio(int x, int y)
{
	COORD c = rList[0].getCoords();
	for (int i = 0; i < rList.size(); i++) {
		if ((y >= c.Y) && (y <= (c.Y + rList.size() - 1)) && (x >= c.X) && (x <= c.X + getMaxWidth())) {
			if (i == y - c.Y) {
				rList[i].setPressed(true);
				cout << "[X] " << rList[i].getName();
			} 
			else {
				rList[i].setPressed(false);
				cout << "[ ] " << rList[i].getName();
				}
		}
		
	}
}

size_t RadioList::GetSelectedIndex() {	return where_am_i; }

void RadioList::SetSelectedIndex(size_t index) { where_am_i = index; }

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

void RadioList::draw(Graphics &g, int left, int top, size_t layer) {
	if (getVisible()){
		g.moveTo(left, top);
		COORD c = { left, top };

		for (int i = 0; i < size; i++) {
			SetConsoleCursorPosition(hndl, c);
			if (rList[i].hover) {
				setBackground(Color::White);
				setForeground(Color::Black);
				if (!rList[i].isPressed()) g.write("[ ] ");
				else g.write("[X] ");
				g.write(rList[i].getName());
			} else {
				setBackground(Color::Black);
				setForeground(Color::White);
				if (!rList[i].isPressed()) g.write("[ ] ");
				else g.write("[X] ");
				g.write(rList[i].getName());
			}
			c = { left, ++top };
		}
	}	
}

void RadioList::mousePressed(int x, int y, bool isLeft) { if (getVisible()) setRadio(x, y); }

void RadioList::keyDown(int keyCode, char charater) {
	int i;
	COORD c = rList[0].getCoords();
		if (keyCode == VK_UP) {
			for (i = 0; i < size; i++)	{
				if (rList[i].isHover())	{
					if (rList[i].pos.Y - 1 > c.Y) {
						rList[i].setHover();
						rList[i - 1].setHover();
					}
				}
			}
		}
		if (keyCode == VK_DOWN)	{
			for (i = 0; i < size; i++)	{
				if (rList[i].isHover())	{
					if (rList[i].pos.Y + 1 < c.Y + (size - 1)) {
						rList[i].setHover();
						rList[i + 1].setHover();
					}
				}
			}
		}
		if ((keyCode == 0x58) || (keyCode == VK_SPACE) || (keyCode == VK_RETURN))	{ for (i = 0; i < rList.size(); i++) {}	}
	else printf("key released\n");
}




