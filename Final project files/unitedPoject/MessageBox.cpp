#include "MessageBox.h"

MessageBox::MessageBox(int height, int width) : Panel(height, width), button(2), text(1, ""), title(1, ""),listner(*this)
{
	iControl::hight = height;
	setLayer(4);
	button.setLayer(3);
	button.AddListener(listner);
	text.setLayer(3);
	title.setLayer(3);
	button.SetValue("OK"); 
	button.setBorder(BorderType::Single);
	Panel::AddControler(title, maxWidth / 8, 0);
	Panel::AddControler(text, maxWidth / 8, hight / 4);
	Panel::AddControler(button, maxWidth / 3, hight - 2);
};

void MessageBox::setTextLabelSize(int height, int width)
{
	text.setHight(height);
	text.setMaxWidth(width);
};
void MessageBox::setTitleLabelSize(int height, int width)
{
	title.setHight(height);
	title.setMaxWidth(width);
};
void MessageBox::setButtonSize(int height, int width)
{
	button.setHight(height);
	button.setMaxWidth(width);
};
void  MessageBox::draw(Graphics &g, int left, int top, size_t layer)
{
	if (getVisible())Panel::draw(g, left, top, layer);
}
void MessageBox::mousePressed(int x, int y, bool isLeft)
{
	if (getVisible())Panel::mousePressed(x, y, isLeft);
}
void MessageBox::invisible()
{
	visible = false;
	can_Get_Focus = false;
}