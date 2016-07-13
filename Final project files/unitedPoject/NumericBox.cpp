#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max) :Panel(4, width), plus_button(5), minus_button(5), screen(3, ""), minus(*this), plus(*this), minValue(min), maxValue(max)
{
	//iControl::hight = 4;
	setLayer(1);
	plus_button.setLayer(1);
	plus_button.AddListener(plus);
	plus_button.SetValue("+");
	plus_button.setBorder(BorderType::Single);
	plus_button.setHight(3);
	plus_button.setMaxWidth(3);
	minus_button.setLayer(1);
	minus_button.AddListener(minus);
	minus_button.SetValue("-");
	minus_button.setBorder(BorderType::Single);
	minus_button.setHight(3);
	minus_button.setMaxWidth(3);
	screen.setLayer(1);
	if (min <= 0 && max >= 0) SetValue(0);
	else{SetValue(max);}
	Panel::AddControler(plus_button, 0, 0);
	Panel::AddControler(screen, getMaxWidth()/2, 1);
	Panel::AddControler(minus_button, getMaxWidth()-minus_button.getMaxWidth()-1, 1);

}
void NumericBox::draw(Graphics &g, int left, int top, size_t layer)
{
	if (visible)Panel::draw(g, left, top, layer);
}
void NumericBox::mousePressed(int x, int y, bool isLeft)
{
	if (visible)Panel::mousePressed(x, y, isLeft);
}
void NumericBox::inc()
{
	SetValue(GetValue() + 1);
}

void NumericBox::dec()
{
	SetValue(GetValue() - 1);
}

bool NumericBox::SetValue(int value)
{
	if (value <= maxValue&&value >= minValue)
	{
		NumericBox::value = value;
		screen.SetValue(to_string(value));
		return true;
	}
	return false;
}