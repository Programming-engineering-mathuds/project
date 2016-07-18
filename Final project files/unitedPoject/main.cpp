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
	/*
	Panel p(20, 20);
	p.setBorder(BorderType::Single);
	CheckBoxLine test1(5, "test1");
	CheckBoxLine test2(5, "test2");
	CheckBoxLine test3(5, "test3");
	p.AddControler(test1, 0, 0);
	p.AddControler(test2, 0, 5);
	p.AddControler(test3, 0, 8);
	*/
	//Radiolist r(20, 20, { "test1", "test2", "test3" });
	Checklist r(20, 20, { "test1", "test2", "test3" });
	//r.setBorder(BorderType::Double);
	//ComboBox r(20 , { "test1", "test2", "test3" });
	r.setBorder(BorderType::None);
//	NumericBox  r(10, -10, 10);
	//r.setBorder(BorderType::Double);
	e.run(r);
	return 0;
};

