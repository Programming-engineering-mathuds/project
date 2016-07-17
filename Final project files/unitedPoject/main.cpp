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

#include "CheckBoxLine.h"

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
	//Label l(5, "test");
	//l.setBackground(Color::Red);
	//l.setBorder(BorderType::Double);
	CheckBoxLine c(5, "test");
	CheckBoxLine c1(5, "test1");
	CheckBoxLine c2(5, "test2");
	//RadioList myRadioList(5, 20, { "432536", "5647dg", "grh543g", "b6yfbgbgb", "booom" });
	//CheckList  myCheckList(5, 20, { "432536", "5647dg", "grh543g", "b6yfbgbgb", "booom" });
	//ComboBox  myComboBox(5, { "hey", "there", "you", "stupid", "fuck" });
	//myCheckList.setBorder(BorderType::Double);



	p.AddControler(c, 0, 0);
	p.AddControler(c1, 0, 4);
	p.AddControler(c2, 0, 7);
//	p.Hide();
	e.run(p);
	return 0;
};

