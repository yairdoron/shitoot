#include "NumericBox.h"


struct NumericBoxUpdateListener;

NumericBox::NumericBox(int width, int min, int max) : Panel(1, width), _buttonMinus(1), _label(width - 2), _buttonPlus(1),
	_val(min), _min(min), _max(max)
{

	NumericBoxUpdateListener* updateListener = new NumericBoxUpdateListener(*this);

	_buttonMinus.setText("-");
	_buttonPlus.setText("+");
	_buttonMinus.addListener(*updateListener);
	_buttonPlus.addListener(*updateListener);
	addControl(_buttonMinus, 0, 0);
	addControl(_label, 1, 0);
	addControl(_buttonPlus, width - 1, 0);
}

NumericBox::~NumericBox()
{
}

void NumericBox::setParam(int value)
{
	if (value<_max && value>_min)
	{
		_val = value;
	}
	else if (value < _min) {
		_val = _min;
	}
	else if (value > _max) {
		_val = _max;
	}
	_label.setText(to_string(_val));
}
int NumericBox::getParam() const
{
	return _val;
}
int NumericBox::getMin() const
{
	return _min;
}

int NumericBox::getMax() const
{
	return _max;
}


struct NumericBoxUpdateListener : public MouseListener
{

private:
	NumericBox &myBox;

public:
	NumericBoxUpdateListener(NumericBox &box) : myBox(box)
	{}


	void mousePressed(Button &button, int x, int y, bool isLeft)
	{

		std::string buttonText = button.getText();
		int value = myBox.getParam();
		if (buttonText == "-")
		{
			value--;
		}
		if (buttonText == "+")
		{
			value++;
		}
		myBox.setParam(value);

	}
};


void NumericBox::addControl(Control & control, int left, int top)
{
	Panel::addControl(control, left, top);
}

void NumericBox::setLayer(size_t layer)
{
	for (auto c : controls)
	{
		c->setLayer(layer);
	}
	Panel::setLayer(layer);
}


