#pragma once

#include <string>

#include "Button.h"
#include "Panel.h"

using namespace std;

class CheckList : public Panel
{
public:
	CheckList(int height, int width, vector<string> options) :Panel(height, width);
	virtual ~CheckList() = default;

	virtual vector<size_t> getPressedCubes() const;
	virtual void selectIndex(size_t index);
	virtual void deselectIndex(size_t index);

	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char character);
	virtual void setLayer(size_t layer);

protected:
	virtual void addControl(Control& control, int left, int top);
	virtual void alterSelectedIndex(size_t index);

	vector<string> _options;
	vector<size_t> _pressedCubes;
	size_t _listIndex;
	
};