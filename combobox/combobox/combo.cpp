#include "combo.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include<string.h>
combo::combo()
{
}
combo::combo(char* text)
{
	comboText = _strdup(text);
	size = strlen(text);
}

int combo::getSize()
{
	return size;
}
char* combo::getText()
{
	return comboText;
}
combo::~combo()
{
}

void combo::print()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;

	GetConsoleScreenBufferInfo(h, &SBInfo);

	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(h, &cci);

	DWORD wAttr = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(h, wAttr);

	int size = strlen(comboText);
	COORD co;
	co.X = SBInfo.dwCursorPosition.X;
	co.Y = SBInfo.dwCursorPosition.Y;
	//COORD c = { 15, 7 };
	SetConsoleCursorPosition(h, co);
	putchar('\xDA');
	for (int i = 0; i < size; i++)
	{
		putchar('\xC4');
	}
	putchar('\xBF');
	//end of the top of the frame
	//putchar('\n');
	//c = { 15, 8 };
	co.Y++;
	SetConsoleCursorPosition(h, co);
	putchar('\xB3');

	for (int i = 0; i < size; i++)
	{
		putchar(comboText[i]);
	}
	putchar('\xB3');
	//end of text
	//putchar('\n');
	//c = { 15, 9 };
	co.Y++;
	SetConsoleCursorPosition(h, co);

	putchar('\xC0');
	for (int i = 0; i < size; i++)
	{
		putchar('\xC4');
	}
	putchar('\xD9');
	//end of bottom of frame
}
