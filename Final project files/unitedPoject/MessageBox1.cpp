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
void  MessageBox1::draw(Graphics &g, int left, int top, size_t layer)
{
	if (visible)Panel::draw(g, left, top, layer);
}
void MessageBox1::mousePressed(int x, int y, bool isLeft)
{
	if (visible)Panel::mousePressed(x, y, isLeft);
}
void MessageBox1::invisible()
{
	visible = false;
	can_Get_Focus = false;
}