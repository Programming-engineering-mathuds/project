#include "Panel.h"
#include "Label.h"
#include "TextBox.h"
#include <iostream>

using namespace std;

void Panel::add(iControl *c)
	{
		controlers.push_back(c);
	}
Panel::Panel(int height, int width) :iControl(width), nullFocuse(1, "")
	{
		setFocus(nullFocuse);
		add(&nullFocuse);
		setHight(height);
		setMaxWidth(width);
		_layer = 0;
		iControl::setLocation(0, 0);
	}

void Panel::AddControler(iControl& control, int newLeft, int newTop)
{
	control.setLocation(newLeft + left, newTop + top);
	if ( control.getLeft() < this->getLeft() || control.getLeft() + control.getMaxWidth() > this->getLeft() + this->getMaxWidth()+1 
		|| control.getTop() < this->getTop() || control.getTop() + control.getHight() > this->getTop() + this->getHight()+1 )
	{
		cout << "There is a Controler out of Boundries";
		return;
	}

	add(&control);
	setStaticControlList(controlers);
	if (control.canGetFocus() && weHaveFocus == 0)
	{
		setFocus(*controlers[controlers.size()-1]);
		weHaveFocus = 1;
	}
}

void Panel::draw(Graphics &g,int junk, int junk2, size_t p)
{
	if (getVisible())
	{
		TextBox *checkTextBox;
		TextBox *Temp=NULL;
		iControl::setLocation(left, top);
		if (p == getLayer()){
			Panel::frame(getHight());
		}
		for (int i = 0; i < controlers.size(); i++)
		{
			if (p == 0 && controlers[i]->getWidthSetFlag() == 0)controlers[i]->setCoords(COORD{ controlers[i]->getLeft(), controlers[i]->getTop() });
			if (p == 0 && controlers[i]->getWidthSetFlag() == 0)
			{
				controlers[i]->setMaxWidth(controlers[i]->getLeft() + controlers[i]->getMaxWidth() - 1);
				controlers[i]->setWidthSetFlag();
			}

			if (p == controlers[i]->getLayer())
			{
				if (controlers[i]->isFocused() && dynamic_cast<TextBox*>(controlers[i]) != NULL) Temp = dynamic_cast<TextBox*>(controlers[i]);
				else controlers[i]->draw(g, controlers[i]->getLeft(), controlers[i]->getTop(), p);
			}

		}
		if (Temp != NULL && Temp->isFocused() == TRUE && p == Temp->getLayer()) Temp->draw(g, Temp->getLeft(), Temp->getTop(), p);
	}
}

void Panel::mousePressed(int x, int y, bool isLeft) 
{
	if (getVisible())
	{

		for (int i = 0; i < controlers.size(); i++)
		{
			if ((x >= controlers[i]->getLeft() - getLeft()) && (x <= (controlers[i]->getLeft() - getLeft() + controlers[i]->getMaxWidth())))
			if (y >= controlers[i]->getTop() - getTop() && y <= (controlers[i]->getTop() - getTop() + controlers[i]->getHight()))
				controlers[i]->mousePressed(x + getLeft(), y + getTop(), isLeft);
		};
	}
}

void Panel::setLocation(int x, int y)
{
	iControl::setLocation(x, y);
	for (int i = 0; i < controlers.size(); i++)
	{
		if (controlers[i]->getLeft() == 0 && controlers[i]->getTop() == 0) 
					controlers[i]->setLocation(controlers[i]->getLeft() + x + 1, controlers[i]->getTop() + y + 1);
		else if (controlers[i]->getLeft() == 0) 
				controlers[i]->setLocation(controlers[i]->getLeft() + x +1, controlers[i]->getTop() + y);
		else if (controlers[i]->getTop() == 0)
			controlers[i]->setLocation(controlers[i]->getLeft() + x, controlers[i]->getTop() + y +1);
		else controlers[i]->setLocation(controlers[i]->getLeft() + x, controlers[i]->getTop() + y);
	}
}

void Panel::frame(int size)
{
	if ((border != BorderType::None) && (left == 0) && (top == 0) && !FirstFrameRun) //frame cannot be printed in -1,-1
	{
		Panel::setLocation(1, 1);
		FirstFrameRun = 1;
	}
	iControl::frame(size);
}




