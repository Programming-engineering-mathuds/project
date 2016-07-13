#include "Panel.h"
#include "Label.h"
#include "Button.h"
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
	//if (control.getLeft() < this->getLeft() || control.getLeft() > this->getLeft() + this->getMaxWidth())
	add(&control);
	setStaticControlList(controlers);
	if (control.canGetFocus() && weHaveFocus == 0)
	{
		setFocus(*controlers[controlers.size()-1]);
		weHaveFocus = 1;
	}
}
//void Panel::traverseFocuse()
//{
	//	PanelComposite::getFocus();
//	}

void Panel::draw(Graphics &g,int junk, int junk2, size_t p)
{
		//setCoords(COORD{ left, top });
		iControl::setLocation(left, top);
		if (p == getLayer()){
			Panel::frame(getHight());
		}
		for (int i = 0; i < controlers.size(); i++)
		{

			//int a = controlers[i]->getLeft();
			//int b = controlers[i]->getTop();
			//int x = controlers[i]->getLeft() + left;
			//int y = controlers[i]->getTop() + top;
			//int j = controlers[i]->getMaxWidth();


			if (p == 0 && controlers[i]->getWidthSetFlag() == 0)controlers[i]->setCoords(COORD{ controlers[i]->getLeft(), controlers[i]->getTop() });
			if (p == 0 && controlers[i]->getWidthSetFlag() == 0)
			{
				controlers[i]->setMaxWidth(controlers[i]->getLeft() + controlers[i]->getMaxWidth() - 1);
				controlers[i]->setWidthSetFlag();
			}

			//int w = controlers[i]->getLeft() + controlers[i]->getMaxWidth() + left;
			//int c = controlers[i]->getMaxWidth();
			if (p == controlers[i]->getLayer()){
				controlers[i]->draw(g, controlers[i]->getLeft(), controlers[i]->getTop(), p);
			}
			
		}
		//controlers[i]->draw(controlers[i]->getLeft(), controlers[i]->getTop(), controlers[i]->getLayer());
}

void Panel::mousePressed(int x, int y, bool isLeft) 
{
	for (int i = 0; i < controlers.size(); i++)
	{
		if ((x >= controlers[i]->getLeft() - getLeft()) && (x <= (controlers[i]->getLeft() - getLeft() + controlers[i]->getMaxWidth())))
		if (y >= controlers[i]->getTop() - getTop() && y <= (controlers[i]->getTop() - getTop() + controlers[i]->getHight()))
			controlers[i]->mousePressed(x + getLeft(), y + getTop(), isLeft);
	};
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




