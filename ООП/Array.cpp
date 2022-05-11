#include "Array.h"
#include <iostream>
using namespace std;

void Array::SetArray() {
	for (int i = 0; i != size; cin >> ar[i++]);
}

void Array::GetArray() {
	for (int i = 0; i != size; cout.width(5), cout << ar[i++]);
}

void Array::ReverseArray() {
	for (int i = 0, j = size - 1; i < j; ++i, --j) {
		swap(ar[i], ar[j]);
	}
}