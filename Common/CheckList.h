#pragma once

#include <string>

#include "Button.h"
#include "Panel.h"

using namespace std;

class CheckList;
struct UpdateListener : public MouseListener
{
	UpdateListener(CheckList &box, size_t index);
	void mousePressed(Button &b, int x, int y, bool isLeft);

private:
	CheckList &_box;
	size_t _index;
};

class CheckList : public Panel
{
public:
	CheckList(int height, int width, vector<string> options);
	virtual ~CheckList() = default;

	virtual vector<size_t> getSelectedIndices() const;
	virtual void selectIndex(size_t index);
	virtual void deselectIndex(size_t index);

	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char character);
	virtual void setLayer(size_t layer);
	virtual void alterSelectedIndex(size_t index);
protected:
	virtual void addControl(Control& control, int left, int top);
	
	vector<string> _options;
	vector<size_t> _selectedIndices;
	size_t _listIndex;
	
};