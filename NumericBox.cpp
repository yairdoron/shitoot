#include "NumericBox.h"



NumericBox::NumericBox()
{
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
