#include "CheckList.h"
#include "vector"


//Constructor
CheckList::CheckList(int height, int width, vector<string> entries) : Panel(height, width)
{
	setCanGetFocus(true);
	size = height;
	for (int i = 0; i < height; i++) {
		CheckBox tempBox(entries[i], width);
		cList.push_back(tempBox);
		cList[i].setCanGetFocus(true);
	}
}

//Destructor
CheckList::~CheckList() {}

int CheckList::cListSize() { return cList.size(); }

vector<size_t> CheckList::GetSelectedIndices() {
	vector<size_t> tempIndexVector;
	for (int i = 0; i < size; i++)	tempIndexVector[i] = cList[i].pressed;
	return tempIndexVector;
}

void CheckList::SelectedIndex(size_t index) { for (int i = 0; i < size; i++)	if (i == index) cList[i].pressed = true; }

void CheckList::DeselectIndex(size_t index) { for (int i = 0; i < size; i++) if (i == index) cList[i].pressed = false; }

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

void CheckList::setCheckbox(int x, int y)
{
	COORD c = cList[0].getCoords();
	
	for (int i = 0; i < cList.size(); i++) 	{
		if ((y >= c.Y) && (y <= (c.Y + cList.size() - 1)) && (x >= c.X) && (x <= c.X + getMaxWidth())) {
			if (i == y - c.Y) {
				if (cList[i].isPressed()) DeselectIndex(i);
				else SelectedIndex(i);
			}
		}
	}
}

void CheckList::draw(Graphics &g, int left, int top, size_t layer) {
	if (getVisible()) {
		g.moveTo(left, top);
		COORD c = { left, top };
		
		for (int i = 0; i < size; i++) {
			SetConsoleCursorPosition(hndl, c);
			if (cList[i].isHover()) {
				setBackground(Color::White);
				setForeground(Color::Black);
				if (!cList[i].isPressed()) g.write("[ ] ");
				else g.write("[X] ");
				g.write(cList[i].getName());
			}
			else {
				setBackground(Color::Black);
				setForeground(Color::White);
				if (!cList[i].isPressed()) g.write("[ ] ");
				else g.write("[X] ");
				g.write(cList[i].getName());
			}
			c = { left, ++top };
		}	
	}	
}

void CheckList::mousePressed(int x, int y, bool isLeft) { if (getVisible()) setCheckbox(x, y); }

void CheckList::keyDown(int keyCode, char charater) {
	int i;
	COORD c = cList[0].getCoords();

	if (keyCode == VK_UP) {
		for (i = 0; i < size; i++) {
			if (cList[i].isHover())	{
				if (cList[i].pos.Y - 1 > c.Y) {
					cList[i].setHover();
					cList[i - 1].setHover();
				}
			}
		}
	}
	if (keyCode == VK_DOWN)	{
		for (i = 0; i < size; i++) {
			if (cList[i].isHover()) {
				if (cList[i].pos.Y + 1 < c.Y + (size - 1)) {
					cList[i].setHover();
					cList[i + 1].setHover();
				}
			}
		}
	}
	if ((keyCode == 0x58) || (keyCode == VK_SPACE) || (keyCode == VK_RETURN)) { for (i = 0; i < cList.size(); i++)	{}	}
	else printf("key released\n");
}