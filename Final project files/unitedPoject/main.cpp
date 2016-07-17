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
#include "Radiolist.h"
#include "CheckList.h"
#include "ComboBox.h"
#include "Label.h"

#include "CheckBoxLine.h"

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
	Label l(5, "test");
	l.setBackground(Color::Red);
	l.setBorder(BorderType::Double);
	Radiolist r(20, 20, { "test1", "test2", "test3" });
	r.setBorder(BorderType::Double);
	p.AddControler(l, 0, 0);
//	p.Hide();
	e.run(r);
	return 0;
};

