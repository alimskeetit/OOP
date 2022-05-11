#include <iostream>
#include "header1.h"
using namespace std;

int main() {
	int a, b;
	char ch;
	MyClass obj;

	cin >> a >> ch >> b;

	obj.operation(a, ch, b);
	
	while (true) {
		cin >> ch;
		if (ch == 'C') break;
		cin >> b;
		obj.operation(ch, b);
		if (obj.get_i() % 3 == 0) cout << obj.get_S();
		if (obj.get_i() == 6) cout << endl;
	}
}