#pragma once
#include <windows.h>
#include <stdio.h>

class Label
{
public:
	Label(char* text);
	~Label();
	void insert();
	void getInput(KEY_EVENT_RECORD key);
	void getMouse(MOUSE_EVENT_RECORD mer);
	void handelInput(INPUT_RECORD input);
};

