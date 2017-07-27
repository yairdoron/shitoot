#pragma once
#include "Graphics.h"
#include <vector>
#include "SimpleBorderFactory.h"


using namespace std;

class Control
{

private:

	int left;
	int top;
	size_t layer;
	int _width;
	int _height;
	BorderType _border;
	Color _background;
	Color _foreground;
	
protected:

	Control(int height, int width);
	virtual ~Control() = default;

public:

	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};
	

	void draw(Graphics& g, int x, int y, size_t layer) const;   //  V

	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	

	virtual int getLeft()const;
	virtual void setLeft(int left);

	virtual int getTop() const;
	virtual void setTop(int top);

	virtual int getWidth() const;
	virtual void setWidth(int width);

	virtual int getHeight() const;
	virtual void setHeight(int height);
	
	virtual size_t getLayer();
	

	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };



	////////my adds//////////

	virtual void setBorder(BorderType border);	// the sons will set it up
	virtual void setLayer(size_t layer);
	
};

