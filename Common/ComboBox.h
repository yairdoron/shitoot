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
	size_t oldLayer;
	Panel panelOptions;
	BorderType listBorder;

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

	virtual void addControl(Control &control, int left, int top);

	//
	struct UpdateListener : public MouseListener {
		ComboBox &myBox;
		size_t index;

		//ctor
		UpdateListener(ComboBox &box, size_t i) : myBox(box), index(i) {}

		void mousePressed(Button &btn, int x, int y, bool left) {
			myBox.setSelectedIndex(index);
			myBox.setLayer(myBox.oldLayer);
			myBox.oldLayer = 0;
			setFocus(myBox);
		}
	};

	struct ShowListListener : public MouseListener {
		ComboBox &myBox;
		//
		ShowListListener(ComboBox &box) : myBox(box) {}

		void mousePressed(Button &btn, int x, int y, bool left) {
			if (myBox.panelOptions.isVisible()) {
				myBox.panelOptions.show();
				setFocus(myBox);
			}
			else {
				myBox.panelOptions.hide();
				setFocus(myBox);
			}
		}
	};
};
