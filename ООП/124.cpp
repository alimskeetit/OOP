#include <iostream>
#include "Header124.h"
using namespace std;

int main() {
	MyClass obj;
	int a, b, i = 0;
	char ch;

	cin >> a >> ch >> b;

	obj.operation(a, ch, b);

	while (++i != 3) {
		cin >> ch;
		cin >> b;
		obj.operation(ch, b);
	}
	cout << obj.get_S();
}