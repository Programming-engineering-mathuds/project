#include "MessageBox1.h"


MessageBox1::MessageBox1(int height, int width) : Panel(height, width), button(2), text(1, ""), title(1, ""),listner(*this)
{
	iControl::hight = height;
	setLayer(4);
	button.setLayer(3);
	button.AddListener(listner);
	text.setLayer(3);
	title.setLayer(3);
	button.SetValue("OK"); 
	button.setBorder(BorderType::Single);
	AddControler(title, 1, 1);
	AddControler(text, 3, 3);
	AddControler(button, 5, 5);
	//button.setLocation(this->getLeft() + 3, this->getTop() + 4);
	//text.setLocation(this->getLeft() + 2, this->getTop() + 2);
	//title.setLocation(this->getLeft() + 1, this->getTop() + 1);
};

void MessageBox1::setTextLabelSize(int height, int width)
{
	text.setHight(height);
	text.setMaxWidth(width);
};
void MessageBox1::setTitleLabelSize(int height, int width)
{
	title.setHight(height);
	title.setMaxWidth(width);
};
void MessageBox1::setButtonSize(int height, int width)
{
	button.setHight(height);
	button.setMaxWidth(width);
};
//void MessageBox1::setPanelSize(int height, int width)
//{
	//panel.setHight(height);
	//panel.setMaxWidth(width);
//};
//void MessageBox1::draw(Graphics &g, int left, int top, size_t layer)
//{
	//Panel::draw(g, left, top, layer);
//};

void MessageBox1::invisible()
{
	setLayer(5);
	button.setLayer(5);
	text.setLayer(5);
	title.setLayer(5);
	g.clearScreen();
	//delete(this);
}