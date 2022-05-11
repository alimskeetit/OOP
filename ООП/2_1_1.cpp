#include <iostream>
#include "MyClass.h"
using namespace std;

MyClass::MyClass() {
	cout << "Constructor\n";
}

MyClass::~MyClass() {
	cout << "Destructor";
}

int main() {
	MyClass a;

	return 0;
}