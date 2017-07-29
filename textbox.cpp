
public class TextBox {
	private string _input;
	private int _width;
	public TextBox()
	{
		this._input = "";
		this._width = 0;
	}
	public TextBox(int width=100)
	{
		this._input = "";
		this._width = width;
	}
	public TextBox(string input)
	{
		this._input = input;
		this._width = input.length()*2;

	}
	public setForeground(Color color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color | FOREGROUND_INTENSITY);
	}
	public setText(string str) {
		this._input = str;
	}
	public static void main{
		TextBox textBox1(10);
		textBox1.setForeground(Color::Red);
		textBox1.setText(L"hello");
		Panel panel;
		panel.addControl(textBox1, 4, 16);
		Control::setFocus(&textBox1);
		EventEngine engine;
		engine.run(panel);
	}
};