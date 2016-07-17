#include "Radiolist.h"

Radiolist::Radiolist(int height, int width, vector<string> options) :Panel(height, width)
{
	setLocation(0,0);
	hold = NULL;
	for (int i = 0; i < options.size(); i++)
	{
		lines.push_back(CheckBoxLine(5, options[i]));
	}
	for (int i = 0; i < lines.size(); i++)
	{
		Panel::AddControler(lines[i], 0, ((getHight() / lines.size()) * i)+1);
	}
}

void Radiolist::mousePressed(int x, int y, bool isLeft)
{
	if (getVisible())
	{
		for (int i = 0; i < lines.size(); i++)
		{
			if ((x >= lines[i].getLeft() - getLeft()) && (x <= (lines[i].getLeft() - getLeft() + lines[i].getMaxWidth())))
			if (y >= lines[i].getTop() - getTop() && y <= (lines[i].getTop() - getTop() + lines[i].getHight()))
			{
				index = i;
				hold = &lines[i];
			}
		}
	}
	Panel::mousePressed(x, y, isLeft);
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != index) lines[i].unPress();
	}
}

size_t Radiolist::GetSelectedIndex()
{
	return index;
}

void Radiolist::SetSelectedIndex(size_t index)
{
	hold = &lines[index];
	Radiolist::index = index;
}