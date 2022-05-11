#include <iostream>
#include "header531.h"
using namespace std;

int main() {
	Class4* ptr;
	int a1, a2, a3, a4;
	int x, num;
	cin >> a1 >> a2 >> a3 >> a4;
	cout << a1 << "    " << a2 << "    " << a3 << "    " << a4;
	ptr = new Class4(a1, a2, a3, a4);
	cin >> x;
	while (x) {
		cin >> num;
		cout << endl << "Class " << num << "    " << "F( " << x << " ) = ";
		switch (num)
		{
		case 1:
			cout << ptr->Class1::foo(x);
			break;
		case 2:
			cout << ptr->Class2::foo(x);
			break;
		case 3:
			cout << ptr->Class3::foo(x);
			break;
		case 4:
			cout << ptr->Class4::foo(x);
			break;
		default:
			break;
		}
		cin >> x;
	}
}