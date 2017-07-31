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
#include "CheckList.h"
#include <vector>

using namespace std;

int main()
{

	Label Label1(20);
	Label1.setText("Name: ");

	TextBox TextB(20);
	TextB.setBorder(BorderType::Double);
	

	TextBox TextB2(25);


	Panel main(50, 40);

	vector<string> options;
	options.push_back("100");
	int x = 60;

	CheckList checklist(x, x, options);

	main.addControl(Label1, 3, 2);

	main.addControl(TextB, 25, 2);
	main.addControl(TextB2, 25, 5);
	main.addControl(checklist, 60, 30);
	EventEngine engine;

	main.setBackground(Color::Purple);


	main.setForeground(Color::White);
	engine.run(main);
	return 1;
}