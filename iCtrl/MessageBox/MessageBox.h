#include <windows.h>
#include <stdio.h>
#include "../iCtrl/iCtrl.h"

class MessageBox : public iCtrl
{
	char* text;
	int size;
	//TBADDED to base class
	int frameSize = 0; //should be change to enum. 0 = no fram,1= 1 line, 2 = 2 lines//
	int fontColor = 0;//defult white
	int backColor = 0;
	COORD init;
public:
	MessageBox(char* text, int arrSize, COORD cor, int frameS);
	~MessageBox() {};

};