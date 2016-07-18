#include "ComboBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

ComboBox::ComboBox(int width, vector<string> entries) : Panel((entries.size() * 4), width),label(" "), BoxHeader(10, label), listen(*this), button(2)
{
	setLocation(0, 0);
	button.AddListener(listen);
	button.SetValue("X");
	button.setBorder(BorderType::Single);
	BoxHeader.setBorder(BorderType::Single);
	for (int i = 0; i < entries.size(); i++)
	{
		boxList.push_back(ComboLine(5, entries[i]));
		listListen.push_back(ComboLineListener(*this));
	}
	Panel::AddControler(button, 1, 1);
	Panel::AddControler(BoxHeader, (button.getMaxWidth()) + 3, 1);
	for (int i = 0; i < boxList.size(); i++)
	{
		boxList[i].AddListener(listListen[i]);
		Panel::AddControler(boxList[i], 0, ((getHight() / boxList.size()) * (i+1)) + 1);
		boxList[i].Hide();
	}//////////// this loop
}

void ComboBox::openList()
{
	bool hasPressed = false;
	//BoxHeader.Hide();
	for (int i = 0; i < boxList.size(); i++)
	{
		boxList[i].Show();
		if (boxList[i].isPressed())
		{
			last = &boxList[i];
			index = i;      
			boxList[i].unPress();
			hasPressed = true;
		}
	}
	isOpen = true;
	if (hasPressed == false)
	{
		last = NULL;
		index = -1;
		BoxHeader.SetValue(label);
	}
}

void  ComboBox::closeList()
{
	if (last != NULL) BoxHeader.SetValue(last->getValue());
	for (int i = 0; i < boxList.size(); i++)
	{
		boxList[i].Hide();
	}
	isOpen = false;
}

void ComboBox::genericFunc1()
{
	if (isOpen) closeList();
	else openList();
}

void ComboBox::genericFunc3(int x, int y, bool arg)
{
	if (getVisible())
	{
		for (int i = 0; i < boxList.size(); i++)
		{
			if ((x >= boxList[i].getLeft() - getLeft()) && (x <= (boxList[i].getLeft() - getLeft() + boxList[i].getMaxWidth())))
			if (y >= boxList[i].getTop() - getTop() && y <= (boxList[i].getTop() - getTop() + boxList[i].getHight()))
			{
				boxList[i].genericFunc1();
				last = &boxList[i];
				index = i;
				closeList();
			}
		}
	}
}

void ComboBox::draw(Graphics &g, int left, int top, size_t layer)
{
	for (int i = 0; i < boxList.size(); i++)
	{
		if (boxList[i].getPressByKey())
		{
			last = &boxList[i];
			index = i;
			closeList();
			boxList[i].setPressbykey(false);
		}
	}
	Panel::draw(g, left, top, layer);
}