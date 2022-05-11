#include "header531.h"
int Class1::foo(int& x) {
	return a * x;
}
int Class2::foo(int& x) {
	return a * x * x + Class1::foo(x);
}
int Class3::foo(int& x) {
	return a * x * x * x + Class2::foo(x);
}
int Class4::foo(int& x) {
	return a * x * x * x * x + Class3::foo(x);
}