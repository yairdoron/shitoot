#include <algorithm>

#include "Button.h"
#include "Panel.h"
#include "CheckList.h"

using namespace std;


CheckList::CheckList(int height, int width, vector<string> options):Panel(height, width), _options(options),
_selectedIndices(), _listIndex(0)
{
	

	for (int i = 0; i < options.size(); i++)
	{
		Button* btnOption = new Button(width);
		struct UpdateListener* listener = new struct UpdateListener(*this, i);
		btnOption->setText("[ ] " + options[i]);
		btnOption->addListener(*listener);
		addControl(*btnOption, 0, i);
	}

	setCanGetFocus(true);
}

vector<size_t> CheckList::getSelectedIndices() const
{
	return _selectedIndices;
}

void CheckList::selectIndex(size_t index)
{
	if ((index < 0) || (index >= _options.size()))
	{
		throw "invalid index";
	}


	if (find(_selectedIndices.begin(), _selectedIndices.end(), index) == _selectedIndices.end())
	{
		_selectedIndices.push_back(index);
		auto newSelectedBtn = (reinterpret_cast<Button*>(controls[index]));
		newSelectedBtn->setText("[*] " + _options[index]);
	}
}

void CheckList::deselectIndex(size_t index)
{
	if ((index < 0) || (index >= _options.size()))
	{
		throw "invalid index";
	}

	auto selectedIndex = find(_selectedIndices.begin(), _selectedIndices.end(), index);
	if (selectedIndex != _selectedIndices.end())
	{
		_selectedIndices.erase(selectedIndex);
		auto newDeselectedBtn = (reinterpret_cast<Button*>(controls[index]));
		newDeselectedBtn->setText("[ ] " + _options[index]);
	}
}

void CheckList::addControl(Control & control, int left, int top)
{
	Panel::addControl(control, left, top);
}

void CheckList::alterSelectedIndex(size_t index)
{
	if (find(_selectedIndices.begin(), _selectedIndices.end(), index) == _selectedIndices.end())
	{
		selectIndex(index);
	}
	else
	{
		deselectIndex(index);
	}
}

void CheckList::mousePressed(int x, int y, bool isLeft)
{
	if (!isVisible())
	{
		return;
	}

	Panel::mousePressed(x, y, isLeft);

	if (this != Control::getFocus())
	{
		controls[_listIndex]->setBackground(getBackground());
		controls[_listIndex]->setForeground(getForeground());
	}
}

void CheckList::keyDown(int keyCode, char character)
{
	if ((this != Control::getFocus()) || (!isVisible()))
	{
		return;
	}

	int change = 0;

	switch (keyCode)
	{
	case VK_RETURN:
	case VK_SPACE:
		alterSelectedIndex(_listIndex);
		return;

	case VK_DOWN:
		change = 1;
		break;

	case VK_UP:
		change = -1;
		break;

	default:
		return;
	}

	controls[_listIndex]->setBackground(getBackground());
	controls[_listIndex]->setForeground(getForeground());

	if ((change == -1) && (_listIndex == 0))
	{
		_listIndex = controls.size() - 1;
	}
	else
	{
		_listIndex = (_listIndex + change) % controls.size();
	}

	controls[_listIndex]->setBackground(getForeground());
	controls[_listIndex]->setForeground(getBackground());
}

void CheckList::setLayer(size_t layer)
{
	for (auto c : controls)
	{
		c->setLayer(layer);
	}
	Panel::setLayer(layer);
}

UpdateListener::UpdateListener(CheckList &box, size_t index) : _box(box), _index(index)
{}


void UpdateListener::mousePressed(Button &b, int x, int y, bool isLeft)
{
	_box.alterSelectedIndex(_index);
}

