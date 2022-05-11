#include "Header123.h"
#include <iostream>
using namespace std;

void MyClass::set_n() {
	cin >> n;
}

long long MyClass::get_n() {
	return n;
}

void MyClass::set_count() {
	long long x = n;
	do {
		count++;
	} while ((x /= 10) != 0);
}

int MyClass::get_count() {
	return count;
}