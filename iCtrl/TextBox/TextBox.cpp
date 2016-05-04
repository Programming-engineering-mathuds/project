#include "TextBox.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

TextBox::TextBox( int arrSize, COORD cor, int frameS) :iCtrl(arrSize, cor),size(30), frameSize(frameS)
{
	maxWidth = 30;
	init = { 2, 2 };
	frame(1, 30);

}
