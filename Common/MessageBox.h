#pragma once

#include <string>

#include "Panel.h"

using namespace std;

class MessageBoxP : public Panel
{
public:
	MessageBoxP(int width, int height);
	~MessageBoxP();

	virtual string getText();
	virtual void setText(string text);

	virtual string getTitle();
	virtual void setTitle(string title);

	virtual string getResult();

	virtual void show();

	virtual void setLayer(size_t layer);

protected:
	virtual void addControl(Control& control, int left, int top);

protected:
	struct AnswerListener : public MouseListener
	{
		AnswerListener(MessageBoxP &box) : _box(box)
		{}

		void mousePressed(Button &b, int x, int y, bool isLeft)
		{
			_box.hide();
			_box.result = b.getText();
		}

	private:
		MessageBoxP &_box;
		size_t _index;
	};

protected:
	Label My_Context;
	Label Title;
	string result;
};

