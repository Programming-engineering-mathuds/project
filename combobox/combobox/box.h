#pragma once
#include "combo.h"
#include<vector>
#include<allocators>
#include<stdio.h>
using namespace std;

class box
{
public:
	box();
	~box();

	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	COORD temp;
	COORD beforePrint;
	void printlist();
	void addCombo(combo a);
	void addCombo(char* text);
	void openBox();
	void getInput(INPUT_RECORD in);
	void MouseEvent(MOUSE_EVENT_RECORD in);
	void KeyEvent(KEY_EVENT_RECORD in);
	void ResizeEvent(WINDOW_BUFFER_SIZE_RECORD in);
	void printBox();
	void printBotton();
	bool open;
	int XR;
	int XL;
	int YU;
	int YD;
	int numOfCombo;
	vector<combo> myList;
	vector<combo>::iterator i;
	combo* selectedCombo;
	int longestWord = 0;
	COORD start;
	HANDLE h;
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	int getStartY();
	void closeBox();
};

