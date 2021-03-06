#pragma once

#include <string>
#include "Label.h"
using namespace std;

class Button;

struct MouseListener {
		//pure virtual struct method
		virtual void mousePressed(Button &button, int x, int y, bool isLeft) = 0;
	
};

class Button : public Label
 {
	private:
		vector<struct MouseListener*> listeners;
		public:
			Button(int width);
			~Button();
			
			virtual void mousePressed(int x, int y, bool left);
			void addListener(struct MouseListener &listener);
};