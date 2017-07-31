#include <iostream>
#include <string>
#include "EventEngine.h"
#include "Control.h"
#include "TextBox.h"
#include "Label.h"
#include "Button.h"
#include "Panel.h"
#include "NumericBox.h"
#include "ComboBox.h"
#include "MessageBox.h"
#include "CheckList.h"
#include <vector>

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.setForeground(Color::Orange);
	}
private:
	Control &_c;
};




int main()
{

	Label Label1(20);
	Label1.setText("Name: ");

	TextBox TextB(20);
	TextB.setBorder(BorderType::Double);
	

	TextBox TextB2(25);


	Panel main(50, 60);

	vector<string> options;
	options.push_back("100");
	int x = 60;

	CheckList checklist(x, x, options);

	main.addControl(Label1, 3, 2);

	main.addControl(TextB, 25, 2);


	Button b(10);
	b.setText("submit");
	MyListener l(TextB);

	b.addListener(l);
	main.addControl(b, 25, 5);

	main.addControl(TextB2, 25, 5);
	main.addControl(checklist, 60, 30);

	EventEngine engine;

	//main.setBackground(Color::Purple);
	MessageBoxP b2(30, 20);

	b2.setTitle("MyStupidMessageBox");
	b2.setText("this is SPARTA");

	//main.setForeground(Color::White);
	//main.addControl(b2, 1, 5);
	engine.run(main);
	return 1;
}