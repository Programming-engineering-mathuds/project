#include "Radiolist.h"

Radiolist::Radiolist(int height, int width, vector<string> options) :Panel(height, width)
{
	setLocation(0,0);
	hold = NULL;

	for (int i = 0; i < options.size(); i++)
	{
		lines.push_back(CheckBoxLine(5, options[i]));
		listen.push_back(CheckListener(*this));
	}
	for (int i = 0; i < lines.size(); i++)
	{
		lines[i].AddListener(listen[i]);
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
				last = i;
				hold = &lines[i];
			}
		}
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != index) lines[i].unPress();
	}
	Panel::mousePressed(x, y, isLeft);
}
void Radiolist::draw(Graphics &g, int left, int top, size_t layer)
{
	if (getVisible())
	if (layer == _layer)
	{
		int diff = 0;
		if (timer > 0)
		{
			struct tm y2k = { 0 };
			y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
			y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

			for (int i = 0; i < lines.size(); i++)
			{
				seconds = difftime(lines[i].getTime(), mktime(&y2k));
				if (seconds>diff)
				{
					diff = seconds;
					last = i;   ///  <--- never enter this part so Last allways stay -1
				}
			}
			if (last!=-1)
			for (int i = 0; i < lines.size(); i++)
			{
				if (i != last)lines[i].unPress();
			}
			if (last != -1)
			{

				index = last;
				hold = &lines[last];
			}//  <--- You can access array -1 P_P then crashhhh
		}
		if (timer < 10)
		if (timer < 2)timer++;
		Panel::draw(g, left, top, layer);
	}
}
/*
void Radiolist::keyDown(int keyCode, char charater)
{
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].isFocused())
		if (keyCode == VK_RETURN)
		{
			index = i;
			hold = &lines[i];
			for (int i = 0; i < lines.size(); i++)
			{
				if (i != index) lines[i].unPress();
			}
			lines[i].genericFunc1();
		}
	}
}
*/
size_t Radiolist::GetSelectedIndex()
{
	return index;
}

void Radiolist::SetSelectedIndex(size_t index)
{
	hold = &lines[index];
	Radiolist::index = index;
}

void Radiolist::genericFunc3(int x, int y, bool arg)
{
	if (getVisible())
	{
		for (int i = 0; i < lines.size(); i++)
		{
			if ((x >= lines[i].getLeft() - getLeft()) && (x <= (lines[i].getLeft() - getLeft() + lines[i].getMaxWidth())))
			if (y >= lines[i].getTop() - getTop() && y <= (lines[i].getTop() - getTop() + lines[i].getHight()))
			{
				lines[i].genericFunc1();
			}
		}
	}
}