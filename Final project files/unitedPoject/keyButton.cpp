#include "keyButton.h"

void keyButton::keyDown(int keyCode, char charater)
{
	if (getVisible())
	{
		if (keyCode == VK_RETURN)
		{
			notify(left + 1, top + 1, 1);
		}
	}
}

void keyButton::draw(Graphics &g, int left, int top, size_t layer)
{
	if (isFocused())
	{
		g.setBackground(textColor);
		g.setForeground(BackColor);
	}
	Button::draw(g, left, top, layer);
	if (isFocused())
	{
		g.setBackground(BackColor);
		g.setForeground(textColor);
	}
}
