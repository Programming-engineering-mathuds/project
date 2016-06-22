#include <windows.h>
#include <string>
#include <stdio.h>
#include "Button.h"
#include "BorderType.h"
#include "EventEngine.h"
#include "Graphics.h"
using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

struct MyListener : public MouseListener
{
	MyListener(iControl &c) : _c(c) { }
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.setForeground(Color::Red);
	}
private:
	iControl &_c;
};

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

int main(int argc, char *argv[])
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;
	Button bSubmit(10);
	bSubmit.setCoords(COORD{ 5, 5 });
	MyListener listener(bSubmit);
	bSubmit.SetValue("Submit");
	bSubmit.AddListener(listener);
	bSubmit.setBorder(BorderType::Double);

	EventEngine e;
	e.run(bSubmit);
}
