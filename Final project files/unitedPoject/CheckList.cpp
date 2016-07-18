#include "Checklist.h"

Checklist::Checklist(int height, int width, vector<string> options) :Radiolist(height, width, options)
{ 
	getAllLines(lines); 
};

void Checklist::draw(Graphics &g, int left, int top, size_t layer)
{
	getAllLines(lines);
	if (getVisible())
	if (layer == Radiolist::_layer)
	{
		Panel::draw(g, left, top, layer);
	}
}

void Checklist::mousePressed(int x, int y, bool isLeft)
{
	if (getVisible())
	{
		for (int i = 0; i < lines.size(); i++)
		{
			CheckBoxLine * line = getIndexLine(i);
			if ((x >= line->getLeft() - getLeft()) && (x <= line->getLeft() - getLeft() + line->getMaxWidth()))
			if (y >= line->getTop() - getTop() && y <= (line->getTop() - getTop() + line->getHight()))
			{
				if (line->isPressed())line->unPress();
				else line->press();
			}
		}
	}
	Panel::mousePressed(x, y, isLeft);
}
