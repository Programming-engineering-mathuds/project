#include "keyButton.h"

void keyButton::keyDown(int keyCode, char charater)
{
	if (keyCode == VK_RETURN)
	{
		notify(left+1,top+1, 1);
	}
}