#include "Control.h"



Control::Control(int height, int width) :

	top(1),
	left(2),
	layer(0),
	_width(width),
	_height(height),
	_border(BorderType::None),
	_background(Color::Black),
	_foreground(Color::White)

	{
	
	}



////////my adds/////////


int Control::getLeft() const
{
	return left;
}

void Control::setLeft(int left)
{
	left = left;
}

int Control::getTop() const
{
	return top;
}

void Control::setTop(int top)
{
	top = top;
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

size_t Control::getLayer() 
{
	return layer;
}

void Control::setLayer(size_t layerr)
{
	layer = layerr;
}


void Control::setBorder(BorderType border)
{
	_border = border;
}




void Control::draw(Graphics & g, int left, int top, size_t layer) const
{
	

	g.setBackground(_background);
	g.setForeground(_foreground);

	const BorderDrawer& borderDrawer = SimpleBorderFactory::instance().getBorderDrawer(_border);
	borderDrawer.draw(g, getLeft() + left, getTop() + top, getWidth(), getHeight());   ///  we define the write of the border

}




