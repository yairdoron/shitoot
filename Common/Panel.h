#pragma once

#include <vector>

#include "Control.h"

using namespace std;

class Panel : public Control
{
public:
	Panel(int height, int width);
	~Panel();

	 void getAllControls(vector<Control*>* controls);

	// Callbacks
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
	virtual void mousePressed(int x, int y, bool left);
	virtual void keyDown(int keyCode, char character);

	virtual void addControl(Control& control, int left, int top);


protected:
	vector<Control*> controls;
};