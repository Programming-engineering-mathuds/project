#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max) :Panel(3, width), plus_button(3), minus_button(3), screen(2, ""), minus(*this), plus(*this), minValue(min), maxValue(max)
{
	//iControl::hight = 4;
	setLayer(1);
	plus_button.setLayer(1);
	plus_button.AddListener(plus);
	plus_button.setBorder(BorderType::Single);
	plus_button.setHight(1);
	plus_button.setMaxWidth(3);
	plus_button.SetValue("+");

	minus_button.setLayer(1);
	minus_button.AddListener(minus);
	minus_button.setBorder(BorderType::Single);
	minus_button.setHight(1);
	minus_button.setMaxWidth(3);
	minus_button.SetValue("-");

	screen.setLayer(1);
	if (min <= 0 && max >= 0) SetValue(0);
	else{SetValue(max);}
	Panel::AddControler(plus_button, 0, 0);
	Panel::AddControler(screen, (getMaxWidth()/2)-screen.getMaxWidth(), 0);
	Panel::AddControler(minus_button, getMaxWidth()-minus_button.getMaxWidth()-1,0);

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