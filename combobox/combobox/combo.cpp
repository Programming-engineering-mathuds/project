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
	COORD st;
	co.X = SBInfo.dwCursorPosition.X;
	co.Y = SBInfo.dwCursorPosition.Y;
	st = co;
	SetConsoleCursorPosition(h, co);
	/*
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
	*/

	XL = co.X;
	YU = co.Y;
	//SetConsoleCursorPosition(h, co);
	putchar('\xDA');//corner
	for (int i = 0; i < size; i++)
	{
		putchar('\xC4'); //top
	}
	putchar('\xBF');
	//end of the top of the frame

	co.X = st.X;
	co.Y = ++SBInfo.dwCursorPosition.Y;
	SetConsoleCursorPosition(h, co);

	putchar('\xB3');//left edge

	for (int i = 0; i < size; i++)
	{
		putchar(comboText[i]);//text
	}
	putchar('\xB3');//right edge
	XR = SBInfo.dwCursorPosition.X;

	co.Y = ++SBInfo.dwCursorPosition.Y;
	co.X = st.X;
	SetConsoleCursorPosition(h, co);
	putchar('\xC0');//corner
	for (int i = 0; i < size; i++)
	{
		putchar('\xC4'); //bottom
	}
	putchar('\xD9');
	//end of bottom of frame
	YD = co.Y;
}
