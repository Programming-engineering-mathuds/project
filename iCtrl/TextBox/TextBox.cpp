#include "TextBox.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
COORD cor;
TextBox::TextBox(int arrSize,int StartX) :iCtrl(arrSize, cor)
{
	maxWidth = arrSize;
	setSmaxWidth(arrSize);
	init = { 2, 2 };
	frame(StartX, 2);

}
