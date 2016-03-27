#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "CheckList.h"

using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

COORD cur = { 35, 10 };

void borders()
{
	int xInit = 20;
	int xEnd = 60;
	int yInit = 2;
	int yEnd = 18;
	COORD c = { xInit+3, yInit+2 };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << "CheckList demo for console with C++";

	for (int i = yInit; i <= yEnd; i++)
	{
		if (i == yInit)
		{
			c = { xInit, yInit };
			SetConsoleCursorPosition(h, c);
			cout << '\xC9';
			for (int j = xInit+1; j < xEnd; j++)
			{
				c = { j , i };
				SetConsoleCursorPosition(h, c);
				cout << '\xCD';
			}
			cout << '\xBB';
		}
		if ((i > yInit) && (i < yEnd))
		{
			c = { xEnd, i };
			SetConsoleCursorPosition(h, c);
			cout << '\xBA';
			c = { xInit, i };
			SetConsoleCursorPosition(h, c);
			cout << '\xBA';
		}
		if (i == yEnd)
		{
			c = { xInit, i };
			SetConsoleCursorPosition(h, c);
			cout << '\xC8';
			for (int j = xInit+1; j < xEnd; j++)
			{
				c = { j, i };
				SetConsoleCursorPosition(h, c);
				cout << '\xCD';
			}
			cout << '\xBC';
		}	
	}
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD                      result;
	result = cur;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	return result.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD                      result;
	result = cur;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	return result.Y;
}

//CheckList
CheckList cBox[] = { { "Item01", cur.Y },
{ "Item02", cur.Y + 1 },
{ "Item03", cur.Y + 2 },
{ "Item04", cur.Y + 3 } };

int main(VOID)
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int counter = 0;
	borders();

	//set cursor size and visibility example

	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(h, &cci);

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	cBox[0].setActive(cur);

	// Loop to read and handle the next input events. 

	while (true)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			int tempX = wherex();
			int tempY = wherey();
			//cout << " ( " << tempX << " , " << tempY << " )";

			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				//ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
	}

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	return 0;
}

VOID ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	//printf("Key event: ");
	int i;
	if (ker.bKeyDown)
	{
		//printf("key pressed\n");
		if (ker.wVirtualKeyCode == VK_UP)
		{
			for (i = 0; i < ARRAYSIZE(cBox); i++)
			{
				if ((cBox[i].isActive() == true) && (i > 0))
				{
					cBox[i].setActive(cur);
					cBox[i].coordinator(cur, "up");
					cBox[i - 1].setActive(cur);
					break;
				}
			}
			//printf("UP");
		}
		if (ker.wVirtualKeyCode == VK_DOWN)
		{
			for (i = 0; i < ARRAYSIZE(cBox); i++)
			{
				if ((cBox[i].isActive() == true) && (i + 1 < ARRAYSIZE(cBox)))
				{
					cBox[i].setActive(cur);
					cBox[i].coordinator(cur, "down");
					cBox[i + 1].setActive(cur);
					break;
				}
			}
			//printf("DOWN");
		}
		if ((ker.wVirtualKeyCode == 0x58) || (ker.wVirtualKeyCode == VK_SPACE) || (ker.wVirtualKeyCode == VK_RETURN))
		{
			for (i = 0; i < ARRAYSIZE(cBox); i++)
			{
				if ((cBox[i].isActive() == true))
				{
					cBox[i].checkSwitch(cur);
					break;
				}
			}
			//printf("Select");
		}
	}
	//else printf("key released\n");
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	//printf("Mouse event: ");
	//cout << mer.dwMousePosition.Y;

	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			for (int i = 0; i < ARRAYSIZE(cBox); i++)
			{
				if (mer.dwMousePosition.Y == cBox[i].getPlace())
				{
					cBox[i].checkSwitch(cur);
					break;
				}
			}
			//printf("left button press \n");
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			//printf("right button press \n");
		}
		else
		{
			//printf("button press\n");
		}
		break;
	case DOUBLE_CLICK:
		for (int i = 0; i < ARRAYSIZE(cBox); i++)
		{
			if (mer.dwMousePosition.Y == cBox[i].getPlace())
			{
				cBox[i].checkSwitch(cur);
				break;
			}
		}
		//printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		//printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		for (int i = 0; i < ARRAYSIZE(cBox); i++)
		{
			if (mer.dwMousePosition.Y == cBox[i].getPlace())
			{
				//COORD tempCur;
				//tempCur.X = cur.X;
				for (int j = 0; j < ARRAYSIZE(cBox); j++)
				{
					if (j != i)	cBox[j].setActiveFalse(cur);
					else cBox[i].setActiveTrue(cur);
				}
			}
		}
		//printf("mouse moved\n");
		break;
	case MOUSE_WHEELED:
		//printf("vertical mouse wheel\n");
		break;
	default:
		//printf("unknown\n");
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}