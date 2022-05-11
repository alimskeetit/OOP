#include <iostream>
#include "Class1.h"
#include "Class2.h"
using namespace std;

int maximum(int a, int b) {
	return (a >= b) ? a : b;
}
int main() {
	int a, b;
	cin >> a;
	Class1 first(a);
	
	cin >> a >> b;
	Class2 second;
	second.set_a_b(a, b);

	cout << maximum(first.get_a(), maximum(second.get_a(), second.get_b()));
}