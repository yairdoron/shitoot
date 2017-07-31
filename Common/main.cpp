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

using namespace std;



int main()
{


	Label Label1(20);
	Label1.setText("Name: ");
	TextBox TextB(20);
	TextB.setBorder(BorderType::Single);
	TextBox TextB2(25);


	Panel main(20, 50);

	main.addControl(Label1, 1, 2);
	main.addControl(TextB, 25, 2);
	main.addControl(TextB2, 25, 5);
	Control::setFocus(TextB);
	EventEngine engine;
	engine.run(main);
	return 0;
}