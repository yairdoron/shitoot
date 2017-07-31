#pragma once
#include "Graphics.h"
#include <vector>
#include "SimpleBorderFactory.h"


using namespace std;

class Control
{

private:

	int tleft;
	int ttop;
	size_t layer;
	int _width;
	int _height;
	BorderType _border;
	Color background;
	Color foreground;
	bool _visible;
	bool _canGetFocus;
	
protected:

	Control(int height, int width);
	virtual ~Control() = default;

public:

	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};
	
	
	virtual void draw(Graphics& g, int x, int y, size_t layer) const;   //  V

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


	
	virtual size_t getLayer() const;
	

	virtual void getAllControls(vector<Control*>* controls) {};
	
	virtual bool canGetFocus() const;
	virtual void setCanGetFocus(bool canGetFocus); // TODO: set to protected


	virtual Color getForeground() const;
	virtual void setForeground(Color color);

	virtual Color getBackground() const;
	virtual void setBackground(Color color);

	virtual bool isVisible() const;

	virtual void setBorder(BorderType border);	// the sons will set it up
	virtual void setLayer(size_t layer);

	virtual void  show();
	virtual void hide();
	
};

