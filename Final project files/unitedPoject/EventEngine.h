#pragma once

#include "iControl.h"
#include <Windows.h>

class EventEngine
{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(iControl &c);
	virtual ~EventEngine();
private:
	void moveFocus(iControl &main, iControl *focused);

	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};