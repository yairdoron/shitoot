#include "TextBox.h"


TextBox::TextBox(int width) : Label(width), _cursorPosition(0)
{
	setCanGetFocus(true);
}
void TextBox::draw(Graphics & g, int left, int top, size_t layer) const
{
//to do
}
