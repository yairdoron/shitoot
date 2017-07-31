
#include <string>
#include "Panel.h"
#include "Button.h"
#include "Panel.h"


class NumericBox : Panel
{
private:
	int _val;
	int _min;
	int _max;
	Button _buttonMinus;
	Label _label;
	Button _buttonPlus;

public:
	NumericBox(int width, int min, int max);
    ~NumericBox();
	void setParam(int value);
	int getParam() const;
	int getMin() const;
	int getMax() const;

	virtual void setLayer(size_t layer);
	virtual void addControl(Control& control, int left, int top);
};