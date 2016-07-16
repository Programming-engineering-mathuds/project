#pragma once
#include "Graphics.h"
#include <vector>

struct GraphicsMock : Graphics {
	GraphicsMock() : Graphics(), _screen(25 * 80, L'\0') {}
	void moveTo(int x, int y) {
		_cursorX = x;
		_cursorY = y;
	}
	void clearAt(int x, int y, size_t length) {
		for (; length; ++x, --length) _screen[y * 80 + x] = '\0';
	}

	string getStringtAt(int x, int y, size_t length) {
		string s;
		for (; length; ++x, --length)
			s += _screen[y * 80 + x];
		return s;
	}
	bool isClear() {
		for (size_t i = 0; i < _screen.size(); ++i)
		if (_screen[i])
			return false;
		return true;
	}

private:
	vector <char> _screen;
	int _cursorX, _cursorY;
};