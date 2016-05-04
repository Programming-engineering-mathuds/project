#include "Label.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

void Label::getInput(KEY_EVENT_RECORD key)
{

}
void Label::print()
{
	COORD init = pos;
	if (frameSize == 0)
	{
		CONSOLE_CURSOR_INFO cci = { 100, FALSE };
		SetConsoleCursorInfo(hndl, &cci);
		SetConsoleCursorPosition(hndl, init);
		for (int i = 0; i < size; i++)
		{
			putchar(text[i]);
		}

	}
	else if (frameSize == 1)
	{
		CONSOLE_CURSOR_INFO cci = { 100, FALSE };
		SetConsoleCursorInfo(hndl, &cci);

		//color2(Foreground::WHITE, Background::BLACK);

		SetConsoleCursorPosition(hndl, init);
		putchar('\xDA');
		for (int i = 0; i < size; i++)
		{
			putchar('\xC4');
		}
		putchar('\xBF');
		//end of the top of the frame
		init.Y++;
		init.X = pos.X;
		SetConsoleCursorPosition(hndl, init);
		putchar('\xB3');
		for (int i = 0; i < size; i++)
		{
			putchar(text[i]);
		}
		putchar('\xB3');
		//end of text
		init.Y++;
		init.X = pos.X;
		SetConsoleCursorPosition(hndl, init);

		putchar('\xC0');
		for (int i = 0; i < size; i++)
		{
			putchar('\xC4');
		}
		putchar('\xD9');
		//end of bottom of frame
	}
	else
	{
		CONSOLE_CURSOR_INFO cci = { 100, FALSE };
		SetConsoleCursorInfo(hndl, &cci);

		//color2(Foreground::WHITE, Background::BLACK);

		SetConsoleCursorPosition(hndl, init);
		putchar('\xC9');
		for (int i = 0; i < size; i++)
		{
			putchar('\xCD');
		}
		putchar('\xBB');
		//end of the top of the frame
		init.Y++;
		init.X = pos.X;
		SetConsoleCursorPosition(hndl, init);
		putchar('\xBA');
		for (int i = 0; i < size; i++)
		{
			putchar(text[i]);
		}
		putchar('\xBA');
		//end of text
		init.Y++;
		init.X = pos.X;
		SetConsoleCursorPosition(hndl, init);

		putchar('\xC8');
		for (int i = 0; i < size; i++)
		{
			putchar('\xCD');
		}
		putchar('\xBC');
		//end of bottom of frame
	}

}
Label::Label(char* text, int arrSize,COORD cor) :iCtrl(arrSize,cor),text(text),size(strlen(text))
{
	frameSize = 0;
	print();

}

void Label::getMouse(MOUSE_EVENT_RECORD mer)
{

}
void Label::handelInput(INPUT_RECORD input)
{
	switch (input.EventType)
	{
	case KEY_EVENT: // keyboard input 
		getInput(input.Event.KeyEvent);
		break;

	case MOUSE_EVENT: // mouse input 
		getMouse(input.Event.MouseEvent);
		break;

	case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
		break;

	case FOCUS_EVENT:  // disregard focus events 

	case MENU_EVENT:   // disregard menu events 
		break;

	default:
		break;
	}

}
void Label::changeText(char* newText)
{
	text = newText;
	size = strlen(text);
	print();
}