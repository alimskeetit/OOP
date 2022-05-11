#include "Header124.h"

void MyClass::operation(int a, char ch, int b) {
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
	operation(S, ch, b);
}

int MyClass::get_S() {
	return S;
}