#include "TextBox.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;


TextBox::TextBox(int length) :Label(length)
{ 
	imATextBox=TRUE;
	setCanGetFocus(true); 
	curCoord = { 0, 0 };
}

void TextBox::keyDown(int keyCode, char character)
{

	switch (keyCode) {
		case VK_NUMPAD4:
		case VK_LEFT:
			if (Text.length()>0 && curCoord.X > getLeft() + 1) {
				curCoord.X--;
			}
			break;

		case VK_RIGHT:
			if (Text.length()>0 && curCoord.X < getLeft() + Text.length() + 1) {
				curCoord.X++;
			}
			break;

		case VK_SPACE:
			if (curCoord.X >= getLeft() + 2 && curCoord.X <= getMaxWidth() + getLeft() + 1)
			{
				if (curCoord.X < getMaxWidth() + getLeft() - 1){
					{
						Text.insert(getLeft() - curCoord.X, " ");
						SetValue(Text);
					}
				}
				curCoord.X++;
			}// check virtualkeycore not ascii code
			break;
			
		case VK_NUMPAD6:
		
		case VK_BACK: 
			if (curCoord.X > getLeft() + 1) {
				Text.erase(curCoord.X - getLeft()-2,1);
				curCoord.X--;
				SetValue(Text);
			}
			break;

		case VK_DELETE:
			if (curCoord.X >= getLeft() + 1 && curCoord.X < getLeft() + Text.length()+1) {
				Text.erase(curCoord.X - getLeft()-1,1);
				SetValue(Text);
			}
			break;

		default:
			if (character >= 33 && character <= 126 )
			{
				if (curCoord.X < getMaxWidth() + getLeft() && Text.length() < getMaxWidth()-1)
					{
						Text.insert(curCoord.X-getLeft()-1, 1, character);
						SetValue(Text);
						curCoord.X++;
					}
			}// check virtualkeycore not ascii code
			break;
	}
}


void TextBox::draw(Graphics &g, int left, int top, size_t layer)
{
	if (getVisible())
	{
		if (firstDrawSetCor == 0)
		{
			curCoord = { left + 1, top };
			firstDrawSetCor = 1;
		}
		Label::draw(g, left, top, layer);
		if (curCoord.X-getLeft() < getMaxWidth())
		{
			CONSOLE_CURSOR_INFO cci = { 100, true };
			SetConsoleCursorInfo(hndl, &cci);
			SetConsoleCursorPosition(hndl, { curCoord.X - 1, curCoord.Y });
		}
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	if (x >= getLeft() && x <= getLeft() + Text.length())
	{
		curCoord.X = x+1;
	}
}
