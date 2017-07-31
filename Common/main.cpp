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
	Label1.setBorder(BorderType::None);

	TextBox TextB(20);
	TextB.setBorder(BorderType::None);


	TextBox TextB2(25);


	Panel main(50, 40);
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.setLayer(0);
	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);



//	main.addControl(Label1, 25, 2);
	main.addControl(cCountry, 25, 8);
//	main.addControl(TextB, 25, 2);
//	main.addControl(TextB2, 25, 5);

	EventEngine engine;

	main.setForeground(Color::White);
	engine.run(main);
	return 0;
}