#include "Label.h"

Label::Label(int width) : Control(TEXT_HEIGHT, width)
{
	
}

void Label::setText(string value)
{
	_text = value;
}

string Label::getText() const
{
	return _text;
}

void Label::draw(Graphics & g, int left, int top, size_t layer) const
{

		Control::draw(g, left, top, layer);
		g.write( left, top, _text);

}