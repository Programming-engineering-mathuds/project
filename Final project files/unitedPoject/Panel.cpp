#include "Panel.h"
#include "Label.h"
#include "Button.h"
#include <iostream>

using namespace std;

vector<iControl*> Panel::controlers;

void Panel::add(iControl *c)
	{
		controlers.push_back(c);
	}
Panel::Panel(int height, int width) :iControl(width)
	{
		setHight(height);
		setMaxWidth(width);
		_layer = 0;
		iControl::setLocation(0, 0);
	}

void Panel::AddControler(iControl& control, int newLeft, int newTop)
{
	control.setLocation(newLeft + left, newTop + top);
	add(&control);
	setStaticControlList(controlers);
	if (control.canGetFocus() && weHaveFocus == 0)
	{
		setFocus(*controlers[controlers.size()-1]);
		weHaveFocus == 1;
	}
}
//void Panel::traverseFocuse()
//{
	//	PanelComposite::getFocus();
//	}

void Panel::draw(Graphics &g,int junk, int junk2, size_t p)
{
	if (p = getLayer()){
		//setCoords(COORD{ left, top });
		iControl::setLocation(left, top);
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

			controlers[i]->draw(g, controlers[i]->getLeft(), controlers[i]->getTop(), _layer);

		}
		frame(getHight());
	}
		//controlers[i]->draw(controlers[i]->getLeft(), controlers[i]->getTop(), controlers[i]->getLayer());
}

void Panel::mousePressed(int x, int y, bool isLeft) 
{
	for (int i = 0; i < controlers.size(); i++)
	{
		Panel *checkPanel;
		checkPanel=dynamic_cast<Panel*>(controlers[i]);
		if (checkPanel != 0)mousePressed(x, y, isLeft);
		else	if ( (x >= controlers[i]->getLeft()-1) && (x <= (controlers[i]->getLeft() + controlers[i]->getMaxWidth()) ))
					if (y >= controlers[i]->getTop()-1 && y <= (controlers[i]->getTop()+controlers[i]->getHight()) )
				controlers[i]->mousePressed(x, y, isLeft);
	};
}

void Panel::setLocation(int x, int y)
{
	iControl::setLocation(x, y);
	for (int i = 0; i < controlers.size(); i++)
	{
		controlers[i]->setLocation(controlers[i]->getLeft() + x, controlers[i]->getTop() + y);
	}
}




