#include <iostream>
#include "Header123.h"
using namespace std;

int main() {
	MyClass obj;
	obj.set_n();
	obj.set_count();
	cout << "n = " << obj.get_n() << endl;
	cout << "N = " << obj.get_count();
}