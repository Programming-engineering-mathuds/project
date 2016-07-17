#include <string>
#include <stdio.h>
#include "Button.h"
#include "BorderType.h"
#include "EventEngine.h"
#include "Graphics.h"
#include "Panel.h"
#include "MessageBox.h"
#include "keyButton.h"
#include "NumericBox.h"
#include "RadioList.h"
#include "CheckList.h"
#include "ComboBox.h"
#include "Label.h"


#include "TextBox.h"


using namespace std;

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

int main(int argc, char *argv[])
{
	EventEngine e;
	Panel p(20, 50);
	p.setBorder(BorderType::Single);
	TextBox t(10);
	Label l(10);
	l.SetValue("Hello");
	t.setBorder(BorderType::Single);
	p.AddControler(t, 4, 4);
	p.AddControler(l, 0, 0);
//	p.Hide();
	e.run(p);
	return 0;
};

