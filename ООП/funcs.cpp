#include "header3_1_3.h"
Stack* create_obj() {
	char* name = new char[11];
	int size;
	cin >> name >> size;
	Stack* obj = new Stack(name, size);
	return obj;
}

void format1() {
	cout.width(15);
	cout.setf(ios::left);
}

void format2() {
	cout.width(15);
	cout.setf(ios::right);
}

void show_elements(Stack& obj1, Stack& obj2) {
	int element1, element2;
	bool f1, f2;
	while (true) {
		f1 = obj1.get_element(element1);
		f2 = obj2.get_element(element2);

		if (!f1 && !f2) break;
		cout << endl;
		if (f1) {
			format2();
			cout << element1;
			if (!f2) break;
			else {
				format2();
				cout << element2;
			}
		}
	}
}