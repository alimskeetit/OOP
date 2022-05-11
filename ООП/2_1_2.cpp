#include <iostream>
#include <math.h>
#include "Triangle.h"
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	Triangle tri(a, b, c);
	cout << "P = " << tri.perimetr() << endl;
	cout << "S = " << tri.area();
}