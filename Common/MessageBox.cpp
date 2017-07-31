#include "Label.h"
#include "Button.h"

#include "MessageBox.h"

MessageBoxP::MessageBoxP(int width,int height) :
	Panel(height, width), My_Context(width), Title(width-2)
{
	struct AnswerListener* listener = new struct AnswerListener(*this);

	if ((width < 12) || (height < 7))
	{
		throw "Invalid height or width";
	}

	auto btnOk = new Button(2);
	btnOk->setText("OK");
	btnOk->addListener(*listener);

	auto btnCancel = new Button(6);
	btnCancel->setText("Cancel");
	btnCancel->addListener(*listener);

	setBorder(BorderType::Single);
	Title.setBorder(BorderType::Single);
	addControl(Title, 1, 1);
	addControl(My_Context, 0, 3);
	btnOk->setBorder(BorderType::Single);
	addControl(*btnOk, 1, height - 2);
	btnCancel->setBorder(BorderType::Single);
	addControl(*btnCancel, width - 7, height-2);

	hide();
}

string MessageBoxP::getText()
{
	return My_Context.getText();
}

void MessageBoxP::setText(string text)
{
	My_Context.setText(text);
}

string MessageBoxP::getTitle()
{
	return Title.getText();
}

void MessageBoxP::setTitle(string title)
{
	Title.setText(title);
}

string MessageBoxP::getResult()
{
	return result;
}

void MessageBoxP::show()
{
	result = "";
	Panel::show();
}

void MessageBoxP::addControl(Control & control, int left, int top)
{
	Panel::addControl(control, left, top);
}

void MessageBoxP::setLayer(size_t layer)
{
	for (auto c : controls)
	{
		c->setLayer(layer);
	}
	Panel::setLayer(layer);
}
MessageBoxP::~MessageBoxP(){}