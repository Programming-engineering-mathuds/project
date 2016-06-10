#include <windows.h>
#include <stdio.h>
#include "TextBox.h"
using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
char Text_Box[30];
char Temp[30];
int Maxlenght = 30;
TextBox textBox(30,0);
//Label label("label",0,cor,2);

int main(VOID)
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;
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
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;

	// Loop to read and handle the next 100 input events. 
	COORD Coord;
	Coord.X = 1;
	Coord.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);

	while (counter++ <= 10000)
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
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;
			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;
			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
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
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo);
	if (SBInfo.dwCursorPosition.Y == 1)
		switch (ker.wVirtualKeyCode) {
		case VK_NUMPAD4:
		case VK_LEFT:
			if (!ker.bKeyDown)
				if (SBInfo.dwCursorPosition.X >= textBox.StartX + 2 && SBInfo.dwCursorPosition.X <= textBox.TextmaxWidth) {
					COORD Coord;
					Coord.X = SBInfo.dwCursorPosition.X;
					Coord.Y = SBInfo.dwCursorPosition.Y;
					Coord.X--;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
				}
			break;
		case VK_SPACE:
			/*
			if (!ker.bKeyDown)
				if (SBInfo.dwCursorPosition.X > textBox.StartX + 1 && SBInfo.dwCursorPosition.X <= Maxlenght) {
					COORD Coord;
					Coord.X = SBInfo.dwCursorPosition.X;
					Coord.Y = SBInfo.dwCursorPosition.Y;
					
					for (int i = Coord.X ; i <= Maxlenght; i++)
					{
						Temp[i+1] = Text_Box[i];
					}
					Text_Box[SBInfo.dwCursorPosition.X - textBox.StartX] = ' ';
					printf(" ");
					for (int i = Coord.X+1 ; i <= Maxlenght; i++)
					{
						printf("%c", Temp[i]);
					}
					Coord.X = SBInfo.dwCursorPosition.X+1;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
				}
			break;*/
		case VK_NUMPAD6:
		case VK_RIGHT:
			if (!ker.bKeyDown)
				if (SBInfo.dwCursorPosition.X >= textBox.StartX + 1 && SBInfo.dwCursorPosition.X <= textBox.TextmaxWidth - 1) {
					COORD Coord;
					Coord.X = SBInfo.dwCursorPosition.X;
					Coord.Y = SBInfo.dwCursorPosition.Y;
					Coord.X++;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
				}
			break;
		case VK_BACK:
			if (!ker.bKeyDown)
				if (SBInfo.dwCursorPosition.X > textBox.StartX + 1 && SBInfo.dwCursorPosition.X <= textBox.TextmaxWidth) {
					COORD Coord;
					Coord.X = SBInfo.dwCursorPosition.X;
					Coord.Y = SBInfo.dwCursorPosition.Y;
					Coord.X--;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
					printf(" ");
					Text_Box[SBInfo.dwCursorPosition.X ] = ' ';
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
				}
			break;

		case VK_DELETE:
			if (!ker.bKeyDown)
				if (SBInfo.dwCursorPosition.X > textBox.StartX + 1 && SBInfo.dwCursorPosition.X <= textBox.TextmaxWidth) {
					COORD Coord;
					Coord.X = SBInfo.dwCursorPosition.X;
					Coord.Y = SBInfo.dwCursorPosition.Y;
					printf(" ");
					Text_Box[SBInfo.dwCursorPosition.X - textBox.StartX] = ' ';
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
					for (int i = Coord.X + 1 - textBox.StartX; i <= textBox.TextmaxWidth; i++)
					{
						Text_Box[i] = Text_Box[i+1];
					}
					for (int i = Coord.X + 1 - textBox.StartX; i <= textBox.TextmaxWidth; i++)
					{
						printf("%c",Text_Box[i]) ;
					}
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
				}
			break;
		case VK_ESCAPE:
			COORD Coord;
			Coord.X = 1;
			Coord.Y = 20;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
			printf("Text You Wrote Is : \n ");
			for (int i = 0; i < textBox.TextmaxWidth; i++){

				printf("%c", Text_Box[i]);

			}
			printf("\n");
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo);
			break;
		
		default:
			if (ker.wVirtualKeyCode >= 0x41 && ker.wVirtualKeyCode <= 0x5A || ker.wVirtualKeyCode >= 0x30 && ker.wVirtualKeyCode <= 0x39)
			{
				if (SBInfo.dwCursorPosition.X < textBox.TextmaxWidth){
					if (!ker.bKeyDown)
						printf("%c", ker.wVirtualKeyCode);
					Text_Box[SBInfo.dwCursorPosition.X] = ker.wVirtualKeyCode;
				}
			}// check virtualkeycore not ascii code
			break;
	}
}


VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{

}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{

			if (mer.dwMousePosition.X >= 0 && mer.dwMousePosition.X <= textBox.TextmaxWidth-1 && mer.dwMousePosition.Y == 1)
			{
				COORD Coord;
				Coord.X = mer.dwMousePosition.X;
				Coord.Y = 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);

			}
		}
		break;
	case DOUBLE_CLICK:
	case MOUSE_HWHEELED:
	case MOUSE_MOVED:
	case MOUSE_WHEELED:
	default:
		break;
	}
}
