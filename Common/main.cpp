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
#include "RadioList.h"
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

void defaultForm() {
	Label header(20);
	header.setText("  New Bank Customer");
	header.setBorder(BorderType::Double);
	header.setForeground(Color::Black);
	header.setBackground(Color::White);
	Label lName(20);
	lName.setText("Name: ");
	Label lAddress(20);
	lAddress.setText("Address: ");
	Label lOccupation(20);
	lOccupation.setText("Occupation: ");
	Label lSex(20);
	lSex.setText("Sex:");
	Label lAge(20);
	lAge.setText("Age:");
	TextBox tName(20);
	tName.setBorder(BorderType::Single);
	TextBox tAddress(20);
	tAddress.setBorder(BorderType::Single);
	TextBox tOccupation(20);
	tOccupation.setBorder(BorderType::Single);
	RadioList rSex(2, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setParam(23);
	nAge.setBorder(BorderType::Single);
	MyListener listener(tAddress);
	Button bSubmit(10);
	bSubmit.setText("Submit");
	bSubmit.addListener(listener);
	bSubmit.setBorder(BorderType::Double);
	Panel main(28,50);
	main.addControl(header, 15, 2);
	main.addControl(lName, 1, 5);
	main.addControl(lAddress, 1, 8);
	main.addControl(lOccupation, 1, 11);
	main.addControl(lSex, 1, 16);
	main.addControl(lAge, 1, 22);
	main.addControl(tName, 25, 5);
	main.addControl(tAddress, 25, 8);
	main.addControl(tOccupation, 25, 11);
	main.addControl(rSex, 25, 16);
	main.addControl(nAge, 25, 22);
	main.addControl(bSubmit, 1, 25);
	EventEngine engine;
	engine.run(main);
}

void label(Panel &main) {
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo);
	Label label(20);
	label.setText("test");
	main.addControl(label, 1, SBInfo.dwCursorPosition.Y + 5);
}

int main()
{
	int pick, height, width, top, left, exit = 0;
	cout << "Welcome to banking forms software\nPlease pick:\n1) Default Bank Form\n2) Design Custom Form" << endl;
	cin >> pick;
	if (pick == 1) {
		defaultForm();
	}
	else if (pick == 2) {
		cout << "Please enter form height:" << endl;
		cin >> height;
		cout << "Please enter form width:" << endl;
		cin >> width;
		Panel main(height, width);
		while (!exit) {
			cout << "What component would you like to add:\n1) Label\n2) TextBox\n3) MessageBox\n4) NumericBox\n5) ComboBox\n" <<
				"6) RadioBox\n7) CheckBox\n8) Button\n9) EXIT" << endl;
			cin >> pick;
			switch (pick) {
			case 1:	
				label(main);
				break;
			default: 
				exit = 1;
				break;
					
			}
		}
		Label label(20);
		label.setText("test");
		main.addControl(label, 1, 5);
		EventEngine engine;
		engine.run(main);
	}
	else cout << "Error in pick, exiting software";
	return 0;
}