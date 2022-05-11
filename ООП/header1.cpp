#include "header1.h"

void MyClass::operation(int a, char ch, int b) {
	i++;
	switch (ch)
	{
	case '+':
		S = a + b;
		break;
	case '-':
		S = a - b;
		break;
	case '*':
		S = a * b;
		break;
	case '%':
		S = a % b;
	}
}

void MyClass::operation(char ch, int b) {
	i++;
	switch (ch)
	{
	case '+':
		S += b;
		break;
	case '-':
		S -= b;
		break;
	case '*':
		S *= b;
		break;
	case '%':
		S %= b;
	}
}

int MyClass::get_S() {
	return S;
}

int MyClass::get_i() {
	return i;
}