#include "CheckList.h"
#include "vector"


//Constructor
CheckList::CheckList(int height, int width, vector<string> entries) : Panel(height, width) 
{
	Panel::setCanGetFocus(true);
	size = entries.size();
	for (int i = 0; i < entries.size(); i++) {
		CheckBoxLine tempBox(width, entries[i]);
		tempBox.setCanGetFocus(true);
		AddControler(tempBox, 0 , i);
		List.push_back(tempBox);
	}
}

//Destructor
CheckList::~CheckList() {}

int CheckList::cListSize() { return sizeOfList(); }

vector<size_t> CheckList::GetSelectedIndices() {
	vector<size_t> tempIndexVector;
	for (int i = 0; i < size; i++)	tempIndexVector.push_back(List[i].isPressed());
	return tempIndexVector;
}

void CheckList::SelectedIndex(size_t index) { for (int i = 0; i < size; i++)	if (i == index) List[i].press(); }

void CheckList::DeselectIndex(size_t index) { for (int i = 0; i < size; i++) if (i == index) List[i].unPress(); }

void CheckList::setCheckbox(int x, int y)
{
	COORD c = List[0].getCoords();
	
	for (int i = 0; i < List.size(); i++) 	{
		if ((y >= c.Y) && (y <= (c.Y + List.size() - 1)) && (x >= c.X) && (x <= c.X + getMaxWidth())) {
			if (i == y - c.Y) {
				if (List[i].isPressed()) DeselectIndex(i);
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
			if (List[i].isHover()) {
				setBackground(Color::White);
				setForeground(Color::Black);
				if (!List[i].isPressed()) g.write("[ ] ");
				else g.write("[X] ");
				g.write(List[i].getValue());
			}
			else {
				setBackground(Color::Black);
				setForeground(Color::White);
				if (!List[i].isPressed()) g.write("[ ] ");
				else g.write("[X] ");
				g.write(List[i].getValue());
			}
			c = { left, ++top };
		}	
	}	
}

void CheckList::mousePressed(int x, int y, bool isLeft) { if (getVisible()) setCheckbox(x, y); }

void CheckList::keyDown(int keyCode, char charater) {
	int i;
	COORD c = List[0].getCoords();

	if (keyCode == VK_UP) {
		for (i = 0; i < size; i++) {
			if (List[i].isHover())	{
				if (List[i].getCoords().Y - 1 > c.Y) {
					List[i].setHover();
					List[i - 1].setHover();
				}
			}
		}
	}
	if (keyCode == VK_DOWN)	{
		for (i = 0; i < size; i++) {
			if (List[i].isHover()) {
				if (List[i].getCoords().Y + 1 < c.Y + (size - 1)) {
					List[i].setHover();
					List[i + 1].setHover();
				}
			}
		}
	}
	if ((keyCode == 0x58) || (keyCode == VK_SPACE) || (keyCode == VK_RETURN)) { for (i = 0; i < List.size(); i++)	{} }
	else printf("key released\n");
}