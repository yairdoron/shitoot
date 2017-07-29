#include "TextBox.h"


TextBox::TextBox(int width) : Label(width), _cursorPosition(0)
{
	setCanGetFocus(true);
}

void TextBox::draw(Graphics & g, int left, int top, size_t layer) const
{
	if (!isVisible())
	{
		return;
	}

	Label::draw(g, left, top, layer);

	if (layer == getLayer() + 1 && this == getFocus())
	{
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.moveTo(getLeft() + left + _cursorPosition, getTop() + top);
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	if (!isLeft || !isVisible())
	{
		return;
	}

	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight()))
	{
		//g.write(getLeft() + left, getTop() + top, _value + string(getWidth() - _value.size(), ' '));

		Control::setFocus(*this);

		_cursorPosition = ((x - getLeft()) >= getText().size()) ? getText().size() - 1 : x - getLeft();
	}
}
