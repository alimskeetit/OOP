#include <iostream>
using namespace std;


class MyClass {
	int n, *arr;
public: 
	MyClass() {
		cin >> n;
		arr = new int[n];
		for (int i = 0; i != n; ++i) {
			arr[i] = i * i;
		}
	}
	void out() {
		for (int i = n - 1; i != -1; cout.width(5), cout << arr[i--]);
	}
};

int main() {
	MyClass* obj = new MyClass();
	obj->out();
	delete obj;
}