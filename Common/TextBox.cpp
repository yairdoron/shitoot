#include "TextBox.h"


TextBox::TextBox(int width) : Label(width), _cursorPosition(0)
{
	setCanGetFocus(true);
}
void TextBox::draw(Graphics & g, int left, int top, size_t layer) const
{
	Label::draw(g, left, top, layer);

	if (layer == getLayer() + 1 && this == getFocus())
	{
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.moveTo(getLeft() + left + _cursorPosition, getTop() + top);
	}
}
