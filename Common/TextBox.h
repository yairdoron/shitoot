#pragma once


#include <string>
#include <Windows.h>
#include "Control.h"
#include "Label.h"

using namespace std;



class TextBox : public Label
{
public:
	//constractor
	TextBox(int width);

	virtual ~TextBox() = default;


	// Functions
	void SetText(string value) { _text = value; };
	string GetText() { return _text;  };
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char character);
	
private:
	int _cursorPosition;
	string _text;
};