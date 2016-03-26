#include "box.h"

box::box()
{
	selectedCombo = NULL;
	open = false;
	longestWord = 0;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	GetConsoleScreenBufferInfo(h, &SBInfo);
	start.X = SBInfo.dwCursorPosition.X;
	start.Y = SBInfo.dwCursorPosition.Y;
	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(h, &cci);

	DWORD wAttr = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(h, wAttr);

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		exit(3);

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		exit(3);

}

box::~box()
{
	SetConsoleMode(hStdin, fdwSaveOldMode);
}

void box::printlist()
{
	SBInfo.dwCursorPosition.X = beforePrint.X;
	SBInfo.dwCursorPosition.Y = beforePrint.Y;
	for (i = myList.begin(); i != myList.end(); i++)
	{
		GetConsoleScreenBufferInfo(h, &SBInfo);
		temp.Y = ++SBInfo.dwCursorPosition.Y;
		temp.X = start.X;
		SetConsoleCursorPosition(h, temp);
		i->print();
	}
}
void box::printBox()
{
	GetConsoleScreenBufferInfo(h, &SBInfo);
	SBInfo.dwCursorPosition.X = start.X;
	SBInfo.dwCursorPosition.Y = start.Y;
	if (selectedCombo == NULL)
	{
		putchar('\xDA');
		for (int i = 0; i < longestWord; i++)
		{
			putchar('\xC4');
		}
		putchar('\xBF');
		//print the middle
		putchar('\n');
		putchar('\xB3');

		for (int i = 0; i < longestWord; i++)
		{
			putchar(' ');
		}
		putchar('\xB3');
		printBotton();
		putchar('\n');
		//printing the bottom
		putchar('\xC0');
		for (int i = 0; i < longestWord; i++)
		{
			putchar('\xC4');
		}
		putchar('\xD9');
	}
	else
	{
		putchar('\xDA');
		for (int i = 0; i < selectedCombo->getSize(); i++)
		{
			putchar('\xC4');
		}
		putchar('\xBF');
		//print the middle
		putchar('\n');
		putchar('\xB3');

		for (int i = 0; i < selectedCombo->getSize(); i++)
		{
			putchar(selectedCombo->comboText[i]);
		}
		putchar('\xB3');
		printBotton();
		putchar('\n');
		//printing the bottom
		putchar('\xC0');
		for (int i = 0; i < selectedCombo->getSize(); i++)
		{
			putchar('\xC4');
		}
		putchar('\xD9');
	}
	beforePrint.X = SBInfo.dwCursorPosition.X;
	beforePrint.Y = SBInfo.dwCursorPosition.Y;
}
void box::printBotton()
{
	GetConsoleScreenBufferInfo(h, &SBInfo);
	COORD co;
	co.X = ++SBInfo.dwCursorPosition.X;
	co.Y = --SBInfo.dwCursorPosition.Y;
	XL = --co.X;
	YU = co.Y;
	SetConsoleCursorPosition(h, co);
	putchar('\xC4'); //top
	co.X = --SBInfo.dwCursorPosition.X;
	co.Y = ++SBInfo.dwCursorPosition.Y;
	SetConsoleCursorPosition(h, co);
	putchar('\xB3');//left edge
	co.X = ++SBInfo.dwCursorPosition.X;
	SetConsoleCursorPosition(h, co);
	putchar('\x58');//X
	co.Y = ++SBInfo.dwCursorPosition.Y;
	SetConsoleCursorPosition(h, co);
	putchar('\xC4'); //bottom
	YD = co.Y;
	co.X = ++SBInfo.dwCursorPosition.X;
	co.Y = --SBInfo.dwCursorPosition.Y;
	SetConsoleCursorPosition(h, co);
	putchar('\xB3');//right edge
	XR = co.X;
}
void box::addCombo(combo a)
{
	if(myList.size() < myList.max_size()) myList.push_back(a);
	else
	{
		myList.resize(myList.size() * 2);

		myList.push_back(a);
	}
	numOfCombo++;
	if (a.getSize() > longestWord) longestWord = a.getSize();
}

void box::addCombo(char* text)
{
	combo a = text;
	if (myList.size() < myList.max_size()) myList.push_back(a);
	else
	{
		myList.resize(myList.size() * 2);

		myList.push_back(a);
	}
	numOfCombo++;
	if (strlen(text) > longestWord) longestWord = strlen(text);
}
void box::getInput(INPUT_RECORD in)
{
	switch (in.EventType)
	{
	case KEY_EVENT: // keyboard input 
					//label.handelInput(irInBuf[i]);
		KeyEvent(in.Event.KeyEvent);
		break;

	case MOUSE_EVENT: // mouse input 
		MouseEvent(in.Event.MouseEvent);
		break;

	case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
		ResizeEvent(in.Event.WindowBufferSizeEvent);
		break;

	case FOCUS_EVENT:  // disregard focus events 

	case MENU_EVENT:   // disregard menu events 
		break;

	default:
		exit(8);
		break;
	}
}
void box::MouseEvent(MOUSE_EVENT_RECORD in)
{
	if (in.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
	{
		if (((XL <= in.dwMousePosition.X)&&(in.dwMousePosition.X <= XR)) && ((YU <= in.dwMousePosition.Y)&&(in.dwMousePosition.Y <= YD)))
		{
			//open = !(open);
			if (open == true)open = false;
			else open = true;
			openBox();
		}
		else
		{
			for (i = myList.begin(); i != myList.end(); ++i)
			{
				if ((i->getXL() <= in.dwMousePosition.X) && (in.dwMousePosition.X <= i->getXR()) && (i->getYU() <= in.dwMousePosition.Y) && (in.dwMousePosition.Y <= i->getYD()))
				{
					printf("here");
					//if (system("CLS")) system("clear");
					selectedCombo = i._Ptr;
					//open = !(open);
					closeBox();
					//printBox();
					
				}
			}
		}
	}
}
void box::KeyEvent(KEY_EVENT_RECORD in)
{

}
void box::ResizeEvent(WINDOW_BUFFER_SIZE_RECORD in)
{

}
void box::openBox()
{
	//if (system("CLS")) system("clear");
	//printBox();
	if (open == true)
	{
		printlist();
	}
	else
	{
		closeBox();
	}
}

int box::getStartY()
{
	return start.Y;
}
void box::closeBox()
{
	if (system("CLS")) system("clear");
	printBox();
	open = false;
}