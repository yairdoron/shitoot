#include "TextBox.h"


TextBox::TextBox(int width) : Label(width), _cursorPosition(0)
{
	setCanGetFocus(true);
}

void TextBox::draw(Graphics & g, int left, int top, size_t layer) const
{
	if (!isVisible())
	{
		return;
	}

	Label::draw(g, left, top, layer);

	if (layer == getLayer() + 1 && this == getFocus())
	{
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.moveTo(getLeft() + left + _cursorPosition, getTop() + top);
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	if (!isLeft || !isVisible())
	{
		return;
	}

	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight()))
	{

		Control::setFocus(*this);

		_cursorPosition = ((x - getLeft()) >= getText().size()) ? getText().size() - 1 : x - getLeft();
	}
}
void TextBox::keyDown(int keyCode, char character)
{
	

	bool delCh = false;
	int curCursorPos = _cursorPosition;

	switch (keyCode)
	{
	case VK_BACK:
		if (_cursorPosition > 0)
		{
			--_cursorPosition;
		}
		delCh = true;
		break;

	case VK_DELETE:
		delCh = true;
		break;

	case VK_RETURN:
		return;

	case VK_LEFT:
		if (_cursorPosition > 0)
		{
			--_cursorPosition;
		}
		return;

	case VK_RIGHT:
		if (_cursorPosition <=getText().size())
		{
			++_cursorPosition;
		}
		return;

	default:
		break;
	}

	if (delCh)
	{
		if (curCursorPos < getText().size())
		{
			string newText = getText();
			newText = newText.substr(0, curCursorPos) + newText.substr(curCursorPos+1, newText.size() - curCursorPos);
			setText(newText);
		}
	}
	else if(character != '\0')
	{


		string updated;
		if (curCursorPos < getText().size())
		{
			updated = getText().substr(0, curCursorPos) + character + getText().substr(curCursorPos, getText().size() - curCursorPos);
		}
		else
		{
			updated = getText() + character;
		}

		setText(updated);

		if (_cursorPosition <= getWidth())
		{
			++_cursorPosition;
		}
		
	}
}
