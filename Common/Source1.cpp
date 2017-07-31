#include <ComboBox.h>
#include<iostream>
#include<vector>
publi static void main() {
	vector<string> options = new vector<string>;
	vector<string> list;
	list.push_back("withdraw");
	list.push_back("depsit");

	ComboBox cbox= new ComboBox(50, list);

	cout << "please choose an option:";


}