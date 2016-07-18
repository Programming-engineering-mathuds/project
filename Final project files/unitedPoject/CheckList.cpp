#include "Checklist.h"

Checklist::Checklist(int height, int width, vector<string> options) :Radiolist(height, width, options)
{ 
	getAllLines(lines); 
};

void Checklist::draw(Graphics &g, int left, int top, size_t layer)
{
	if (getVisible())
	if (layer == Radiolist::_layer)
	{
		getAllLines(lines);
		for (int i = 0; i < lines.size(); i++)
		{
			Panel::draw(g, left, top, layer);
		}
	}
}

void Checklist::mousePressed(int x, int y, bool isLeft)
{
	if (getVisible())
	{
		for (int i = 0; i < lines.size(); i++)
		{
			if ((x >= lines[i].getLeft() - getLeft()) && (x <= (lines[i].getLeft() - getLeft() + lines[i].getMaxWidth())))
			if (y >= lines[i].getTop() - getTop() && y <= (lines[i].getTop() - getTop() + lines[i].getHight()))
			{
				if (lines[i].isPressed())lines[i].unPress();
				else lines[i].press();
			}
		}
	}
	Panel::mousePressed(x, y, isLeft);
}
