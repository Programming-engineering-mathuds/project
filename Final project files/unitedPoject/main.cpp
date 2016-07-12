#include <string>
#include <stdio.h>
#include "Button.h"
#include "BorderType.h"
#include "EventEngine.h"
#include "Graphics.h"
#include "Panel.h"
#include "MessageBox.h"
#include "keyButton.h"

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
	MessageBox mess(10, 30);
	mess.setBorder(BorderType::Single);
	mess.SetTitle("title");
	mess.SetText("look! text!");
	mess.setLocation(10, 10);
	EventEngine e;
	MyListener listeners(mess);
	//Button bSubmit(10);
	//bSubmit.SetValue("Submit");

//	bSubmit.setBorder(BorderType::Double);
	//Label l(7, "just");
	Panel p(10, 20);
	keyButton k(10);
	k.SetValue("kbutton");
	k.AddListener(listeners);
	p.AddControler(k, 5, 5);
	//p.setBorder(BorderType::Single);
	//MyListener listeners(p);
//	bSubmit.AddListener(listeners);
	//p.AddControler(bSubmit,5,5);
	//p.AddControler(l, 8, 9);
	//bSubmit.setLayer(4);
	e.run(p);
	return 0;
};

/*
int main(int argc, char *argv[])
{
	//Test for Panel
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;


	EventEngine e;
	//e.run(bSubmit);
	
	
	Graphics g;
	Panel list(25, 25);
	Label l1(8, "one");

	Label l2(8, "two");

	Button bSubmit(10);
	//bSubmit.setCoords(COORD{ 5, 5 });
	MyListener listener(bSubmit);
	bSubmit.SetValue("Bananana");
	bSubmit.AddListener(listener);
	bSubmit.setBorder(BorderType::Double);

	Button B(16);

	B.SetValue("BUTTON");
	B.setBorder(BorderType::Double);
	B.AddListener(listener);


	list.AddControler(l1, 3, 8);
	list.AddControler(l2, 8, 8);
	list.AddControler(B, 3, 13);
	list.AddControler(bSubmit, 3, 16);
	list.setBorder(BorderType::Double);
	//list.draw(g, 3, 3, 0);
	//l1.draw(8, 3, 0);
	//l2.draw(8,8, 0);
	//B.draw(13, 13,0);
	e.run(list);
	return 0;
	//while (1){};
	
	
	//Test for button
	/*DWORD cNumRead, fdwMode, i;
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
*/
/* //Teacher's Main
struct MyListener : public MouseListener
{
MyListener(iControl &c) : _c(c) { }
void mousePressed(Button &b, int x, int y, bool isLeft)
{
_c.setForeground(Color::Red);
}
private:
iControl &_c;
};
int main(int argc, char **argv)
{
Label lName(20);
lName.setText("Name: ");

Label lAddress(20);
lAddress.setText("Address:");
Label lCountry(20);
lCountry.setText("Counrty:");
Label lSex(20);
lSex.setText("Sex:");
Label lInterests(20);
lInterests.setText("Interests:");
Label lAge(20);
lAge.setText("Age:");
TextBox tName(20);
tName.setText("Sherlock Holmes");
tName.setBorder(BorderType::Single);
TextBox tAddress(25);
tAddress.setText("221B Baker Street, London");
tAddress.setBorder(BorderType::Single);
ComboBox cCountry({ "Israel", "Great Britain", "United States" }, 20);
cCountry.setSelectedIndex(1);
cCountry.setBorder(BorderType::Single);
Radiolist rSex(2, 15, { "Male", "Female" });
rSex.setBorder(BorderType::Single);
Checklist clInterests(3, 15, { "Sports", "Books", "Movies" });
clInterests.selectIndex(1);
clInterests.setBorder(BorderType::Single);
NumericBox nAge(15, 18, 120);
nAge.setValue(23);
nAge.setBorder(BorderType::Single);
MyListener listener(tAddress);
Button bSubmit(10);
bSubmit.setText("Submit");
bSubmit.addListener(listener);
bSubmit.setBorder(BorderType::Double);
Panel main;
main.addControl(lName, 1, 2);
main.addControl(lAddress, 1, 5);
main.addControl(lCountry, 1, 8);
main.addControl(lSex, 1, 11);
main.addControl(lInterests, 1, 15);
main.addControl(lAge, 1, 20);
main.addControl(tName, 25, 2);
main.addControl(tAddress, 25, 5);
main.addControl(cCountry, 25, 8);
main.addControl(rSex, 25, 11);
main.addControl(clInterests, 25, 15);
main.addControl(nAge, 25, 20);

main.addControl(bSubmit, 1, 22);
iControl::setFocus(tName);
EventEngine engine;
engine.run(main);
return 0;
}
*/