#pragma once


#include <vector>

#include "Control.h"

using namespace std;

class Panel : public Control
{
public:
	Panel(int height, int width);
	~Panel();

	virtual void getAllControls(vector<Control*>* controls);

	virtual void draw(Graphics &g, int left, int top, unsigned int layer) const;
	virtual void mousePressed(int x, int y, bool Left);
	virtual void keyDown(int keyCode, char character);

	virtual void addControl(Control& control, int left, int top);

	virtual void setForeground(Color color);

	virtual void setBackground(Color color);

protected:
	vector<Control*> controls;
};