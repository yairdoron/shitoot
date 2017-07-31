#include "Panel.h"

Panel::Panel(int height, int width) : Control(height, width)
 {
}

void Panel::getAllControls(vector<Control*>* other_control_list)
 {
if (other_control_list != nullptr)
		 {
		for (unsigned int i = 0; i<controls.size(); i++)	other_control_list->push_back(controls[i]);
		}
	
		}

void Panel::draw(Graphics & g, int left, int top, unsigned int layer) const
 {
	if (layer >= getLayer())
	for (unsigned int i = 0; i<controls.size(); i++) controls[i]->draw(g, left + getLeft(), top + getTop(), layer);
	
		Control::draw(g, left, top, layer);
	}

void Panel::mousePressed(int x, int y, bool Left)
 {
	
		if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight()))
		 {
		if (canGetFocus())
			 {
			Control::setFocus(*this);
			}
		
			for (unsigned int i = 0; i<controls.size(); i++)
			 {
			controls[i]->mousePressed(x - getLeft(), y - getTop(), Left);
			}
		}
	}

void Panel::keyDown(int keyCode, char character)
 {
	
		for (unsigned int i = 0; i<controls.size(); i++)
		 {
		controls[i]->keyDown(keyCode, character);
		}
	}

void Panel::addControl(Control & control, int left, int top)
 {
    control.setLeft(left);
	control.setTop(top);
	controls.push_back(&control);
	}

void Panel::setForeground(Color color)
{
	Control::setForeground(color);
	for (unsigned int i = 0; i<controls.size(); i++)
	{
		controls[i]->setForeground(color);
	}
}
void Panel::setBackground(Color color)
{
	Control::setBackground(color);
	for (unsigned int i = 0; i<controls.size(); i++)
	{
		controls[i]->setBackground(color);
	}
}
Panel::~Panel() {}