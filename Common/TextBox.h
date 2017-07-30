#pragma once


#include <string>
#include <Windows.h>
#include "Control.h"
#include "Label.h"

using namespace std;



class TextBox : public Control
{
public:
	//constractor
	TextBox(int width);

	virtual ~TextBox() = default;


	// Functions
	void SetText(string value) { _text = value; };
	string GetText() { return _text;  };

	
private:
	int _cursorPosition;
	string _text;
};