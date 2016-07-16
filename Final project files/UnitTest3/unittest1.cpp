#include "stdafx.h"
#include "CppUnitTest.h"
#include "../unitedPoject/unitedProject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
struct GraphicMock :Graphics
{
	GraphicMock() : Graphics(), _screen(25 * 80, '\0'){}
	void moveTo(int x, int y){ _cursorX = x; _cursorY = y; }
	void write(string s){
		for (size_t i = 0; i < s.size(); ++i)
			_screen[_cursorY * 80 + _cursorX + i] = s[i];
	}
	void write(int x, int y, string s){ moveTo(x, y); write(s); }
	string getStringAt(int x, int y, size_t length){
		string s;
		for (; length; ++x, --length)
			s += _screen[y * 80 + x];
		return s;
	}
	void clearAt(int x, int y, size_t length){
		for (; length; ++x, --length) _screen[y * 80 + x] = '\0';
	}
	bool isClear(){
		for (size_t i = 0; i < _screen.size(); ++i)
		if (_screen[i])
			return false;
		return true;
	}
private:
	vector<char> _screen;
	int _cursorX, _cursorY;
};
namespace UnitTest3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(testDraw)
		{
			GraphicMock g;
			
		}

	};
}