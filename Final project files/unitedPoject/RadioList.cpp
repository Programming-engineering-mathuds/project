#include "Radiolist.h"

Radiolist::Radiolist(int height, int width, vector<string> options) :Panel(height, width)
{
	hold = NULL;
	for (int i = 0; i < options.size(); i++)
	{
		CheckBoxLine temp(5, options[i]);
		lines.push_back(temp);
	}
	for (int i = 0; i < lines.size(); i++)
	{
		Panel::AddControler(lines[i], 0, ((lines[i].getHight())*i) + 4*i);
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
}

size_t Radiolist::GetSelectedIndex()
{
	return index;
}

void Radiolist::SetSelectedIndex(size_t index)
{
	hold = &lines[index];
}