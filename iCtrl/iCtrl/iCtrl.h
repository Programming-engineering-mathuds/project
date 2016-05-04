#pragma once
#include <Windows.h>
#include <string>
#include <stdio.h>
#include "ConsoleBackground.h"
#include "ConsoleForeground.h"
using namespace std;

class iCtrl
{
protected:
	COORD pos;
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	int clrNum;
	int clrNumHvr;
	int area;
	int maxWidth;
public:
	iCtrl(int arrSize, COORD cur);
	~iCtrl();

	void frame(int size, int frameLines);
	void color(int clrNum);
	void color2(Foreground clrNumFont, Background clrNumBG);
};

