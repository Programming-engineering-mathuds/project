#include "Label.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>

void Label::insert()
{

}
void Label::getInput(KEY_EVENT_RECORD key)
{

}

Label::Label(char* text)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(h, &cci);

	DWORD wAttr = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(h, wAttr);

	int size = strlen(text);
	COORD c = { 15, 7 };
	SetConsoleCursorPosition(h, c);
	putchar('\xDA');
	for (int i = 0; i < size; i++)
	{
		putchar('\xC4');
	}
	putchar('\xBF');
	//end of the top of the frame
	//putchar('\n');
	c = { 15, 8 };
	SetConsoleCursorPosition(h, c);
	putchar('\xB3');

	for (int i = 0; i < size; i++)
	{
		putchar(text[i]);
	}
	putchar('\xB3');
	//end of text
	//putchar('\n');
	c = { 15, 9 };
	SetConsoleCursorPosition(h, c);

	putchar('\xC0');
	for (int i = 0; i < size; i++)
	{
		putchar('\xC4');
	}
	putchar('\xD9');
	//end of bottom of frame
}

Label::~Label()
{
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