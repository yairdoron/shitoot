
#include <string>
#include "Panel.h"

class NumericBox
{
public:
	int _val;
	int _min;
	int _max;

	NumericBox(int width, int min, int max);
	virtual ~NumericBox();
	void setParam(int value);
	int getParam() const;
	int getMin() const;
	int getMax() const;
};