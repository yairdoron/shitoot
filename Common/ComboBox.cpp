#include "ComboBox.h"


ComboBox::ComboBox(int width, vector<string> options) : Panel(options.size() , width), btnValue(width),
panelOptions(options.size(), width), selectedIndex(0), options(options), listIndex(0), oldLayer(0), listBorder(BorderType::None) {}


ComboBox::~ComboBox() {}

size_t ComboBox::getSelectedIndex() const
{
	return selectedIndex;
}

void ComboBox::setSelectedIndex(size_t index)
{
	if ((index < 0) || (index >= options.size()))
		throw "invalid index";

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