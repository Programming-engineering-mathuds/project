#include "Checklist.h"

Checklist::Checklist(int height, int width, vector<string> options) :Radiolist(height, width, options)
{ 
	getAllLines(lines); 
};

void Checklist::draw(Graphics &g, int left, int top, size_t layer)
{
	getAllLines(lines);
	selectedLines.clear();
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].isPressed()) selectedLines.push_back(true);
		else selectedLines.push_back(false);
	}
	if (getVisible())
	if (layer == Radiolist::_layer)
	{
		Panel::draw(g, left, top, layer);
	}
}

void Checklist::mousePressed(int x, int y, bool isLeft)
{
	Panel::mousePressed(x, y, isLeft);
}

vector<size_t> Checklist::GetSelectedIndices()
{
	return selectedLines;
}

void Checklist::SelectIndex(size_t index)
{
	CheckBoxLine* line = getIndexLine(index);
	if (!line->isPressed()) line->press();
}

void Checklist::DeselectIndex(size_t index)
{
	CheckBoxLine* line = getIndexLine(index);
	if (line->isPressed()) line->unPress();
}
