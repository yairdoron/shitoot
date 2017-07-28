#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Control.h"
#include "../Common/Label.h"
//#include "../Common/Panel.h"
#include "../Common/TextBox.h"




void main()
{
	Graphics g = Graphics();
	
	//g.write("hello");

	TextBox FirstTextBox(40);
	FirstTextBox.SetText("My Text box");
	FirstTextBox.setBorder(BorderType::Single);


	Label FirstLabel(10);
	//FirstLabel.setText("yairyyryry");
	//FirstLabel.setBorder(BorderType::Single);
	FirstLabel.draw(g, 8, 8, 0);

	EventEngine engine;
	//g.write(FirstLabel.getText());
	engine.run(FirstLabel);

	


}