#include "ComboBox.h"



ComboBox::ComboBox(int width, vector<string> options) : Panel(options.size() , width), btnValue(width),
panelOptions(options.size(), width), selectedIndex(0), options(options), listIndex(0), oldLayer(0), listBorder(BorderType::None) 
{
	struct ShowListListener* listener = new struct ShowListListener(*this);
	btnValue.addListener(*listener);

	panelOptions.hide();
	for (int i = 0; i < options.size(); i++)
	{
		Button* btnOption = new Button(width);
		struct UpdateListener* listener = new struct UpdateListener(*this, i);
		btnOption->setText(options[i]);
		btnOption->addListener(*listener);
		btnOption->setLayer(4);
		panelOptions.addControl(*btnOption, 0, i);
	}
	panelOptions.setLayer(4);

	addControl(btnValue, 0, 0);
	addControl(panelOptions, 0, 1);

	setCanGetFocus(true);
}


ComboBox::~ComboBox() {}

size_t ComboBox::getSelectedIndex() const
{
	return selectedIndex;
}

void ComboBox::setSelectedIndex(size_t index)
{
	if ((index < 0) || (index >= options.size()))
		throw "invalid index";

	btnValue.setText(options[index]);
	selectedIndex = index;
	panelOptions.hide();
	btnValue.setBorder(listBorder);
	Panel::setBorder(BorderType::None);
}

void ComboBox::setForeground(Color color)
{
	Panel::setForeground(color);
	btnValue.setForeground(color);
}

void ComboBox::setBackground(Color color)
{
	Panel::setBackground(color);
	btnValue.setBackground(color);
}

void ComboBox::setBorder(BorderType border)
{
	listBorder = border;
	if (panelOptions.isVisible())
	{
		Panel::setBorder(listBorder);
		btnValue.setBorder(BorderType::None);
	}
	else 
	{
		Panel::setBorder(BorderType::None);
		btnValue.setBorder(listBorder);
	}
}

void ComboBox::mousePressed(int x, int y, bool left)
{
	Panel::mousePressed(x, y, left);
}

void ComboBox::setLayer(size_t layer)
{
	btnValue.setLayer(layer);
	Panel::setLayer(layer);
}

void ComboBox::addControl(Control &control, int left, int top) {
	Panel::addControl(control, left, top);
}

void ComboBox::keyDown(int key, char c) {
	int change = 0;

	switch (key)
	{
	case VK_RETURN:
	case VK_SPACE:
		setSelectedIndex(listIndex);
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

	vector<Control*> controls;
	panelOptions.getAllControls(&controls);

	controls[listIndex]->setBackground(getBackground());
	controls[listIndex]->setForeground(getForeground());

	if ((change == -1) && (listIndex == 0))
	{
		listIndex = controls.size() - 1;
	}
	else
	{
		listIndex = (listIndex + change) % controls.size();
	}

	controls[listIndex]->setBackground(getForeground());
	controls[listIndex]->setForeground(getBackground());
}

