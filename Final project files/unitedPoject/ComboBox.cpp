#include "ComboBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

ComboBox::ComboBox(int width, vector<string> entries) : Panel((entries.size() * 2), width),label(23,"Please Select An Item"), BoxHeader(23, label.getValue()), listen(*this), button(5)
{
	setLocation(0, 0);
	button.AddListener(listen);
	for (int i = 0; i < entries.size(); i++)
	{
		boxList.push_back(ComboLine(5, entries[i]));
		listListen.push_back(ComboLineListener(*this));
	}
	if (boxList.size() < 0) return;
	for (int i = 0; i < boxList.size(); i++)
	{
		boxList[i].AddListener(listListen[i]);
		Panel::AddControler(boxList[i], 0, ((getHight() / boxList.size()) * (i+1)) + 1);
	}
}

void ComboBox::openList()
{
	bool hasPressed = false;
	BoxHeader.Hide();
	for (int i = 0; i < boxList.size(); i++)
	{
		boxList[i].Show();
		if (boxList[i].isPressed())
		{
			*last = boxList[i];
			boxList[i].unPress();
			hasPressed = true;
		}
	}
	isOpen = true;
	if (hasPressed == false)
	{
		last = NULL;
		BoxHeader.SetValue(label.getValue());
	}
}

void  ComboBox::closeList()
{
	BoxHeader.Show();
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
				*last = boxList[i];
			}
		}
	}
}