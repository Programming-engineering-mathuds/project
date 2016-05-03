#pragma once
#include <Windows.h>
#include <string>
#include <stdio.h>

using namespace std;

class iCtrl
{
protected:
	COORD pos;
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	int clrNum;
	int clrNumHvr;
	int area;
	int rowLength;

public:
	iCtrl(int arrSize);
	~iCtrl();

	void frame(int size);
	void color(int clrNumFont, int clrNumBG);
};

