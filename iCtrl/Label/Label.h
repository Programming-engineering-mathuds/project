#pragma once

#include <windows.h>
#include <stdio.h>
//#include "../iCtrl/iCtrl.h"
//#include "../iCtrl/ConsoleForeground.h"
//#include "../iCtrl/ConsoleBackground.h"
#include "iCtrl.h"
#include "ConsoleForeground.h"
#include "ConsoleBackground.h"
using namespace std;

class Label: public iCtrl
{
	char* text;
	int size;
	//TBADDED to base class
	int frameSize = 0; //should be change to enum. 0 = no fram,1= 1 line, 2 = 2 lines//
	int fontColor = 0;//defult white
	int backColor = 0;//defult black
public:
	Label(char* text, int arrSize);
	~Label() {};
	void print();
	void getInput(KEY_EVENT_RECORD key);
	void getMouse(MOUSE_EVENT_RECORD mer);
	void handelInput(INPUT_RECORD input);
};

