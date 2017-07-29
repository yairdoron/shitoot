#pragma once
#include <string>
#include "Panel.h"
#include "Button.h"

class ComboBox : public Panel
{
protected:
	vector<string> options;
	size_t selectedIndex;
	size_t listIndex;
	Button btnValue;

public:
	ComboBox(int width, vector<string> options);
	~ComboBox();

	virtual size_t getSelectedIndex() const;
	virtual void setSelectedIndex(size_t index);

	virtual void setForeground(Color color);

	virtual void setBackground(Color color);

	virtual void setBorder(BorderType border);

	virtual void setLayer(size_t layer);

	virtual void mousePressed(int x, int y, bool left);
};

