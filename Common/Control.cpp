#include "Control.h"



Control::Control(int height, int width) :

	top(1),
	left(2),
	layer(0),
	_width(width),
	_height(height),
	_border(BorderType::None),
	background(Color::Black),
	foreground(Color::White),
	_visible(true),
	_canGetFocus(false)
	{
	
	}


bool Control::isVisible() const
{
	return _visible;
}


bool Control::canGetFocus() const
{
	return _canGetFocus && isVisible();
}

void Control::setCanGetFocus(bool canGetFocus)
{
	_canGetFocus = canGetFocus;
}


int Control::getLeft() const
{
	return left;
}

void Control::setLeft(int left)
{
	Control::left = left;
}

int Control::getTop() const
{
	return top;
}

void Control::setTop(int top)
{
	Control::top = top;
}

int Control::getWidth() const
{
	return _width;
}

void Control::setWidth(int width)
{
	_width = width;
}

int Control::getHeight() const
{
	return _height;
}

void Control::setHeight(int height)
{
	_height = height;
}

unsigned int Control::getLayer() const
{
	return layer;
}

void Control::setLayer(unsigned int layerr)
{
	layer = layerr;
}


void Control::setBorder(BorderType border)
{
	_border = border;
}

Color Control::getForeground() const
{
	return foreground;
}

void Control::setForeground(Color color)
{
	foreground = color;
}
Color Control::getBackground() const
{
	return background;
}

void Control::setBackground(Color color)
{
	background = color;
}


void Control::draw(Graphics & g, int left, int top, size_t layer) const
{
	

	g.setBackground(background);
	g.setForeground(foreground);

	const BorderDrawer& borderDrawer = SimpleBorderFactory::instance().getBorderDrawer(_border);
	borderDrawer.draw(g, getLeft() + left, getTop() + top, getWidth(), getHeight());   ///  we define the write of the border

}

void Control::show() { _visible = true; }
void Control::hide() { _visible = false; }




