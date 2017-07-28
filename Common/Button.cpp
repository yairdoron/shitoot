#include "Button.h"



Button::Button(int width) : Label(width) {}


Button::~Button() {}

void Button::mousePressed(int x, int y, bool left) {
	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {
		if (canGetFocus()) {
			setFocus(*this);
		}

		for (unsigned int i = 0; i < listeners.size(); i++) {
			listeners[i]->mousePressed(*this, x, y, left);
		}
	}
}

void Button::addListener(MouseListener &listener) {
	listeners.push_back(&listener);
}

