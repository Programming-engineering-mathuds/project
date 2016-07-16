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