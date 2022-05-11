#include "header3_1_3.h"
Stack::Stack(char* p_name, int size) : name(p_name), size(size)
{
}

bool Stack::add_element(const int& chislo) {
	if (n == size) return false;
	int* b = new int[++n];
	b[0] = chislo;
	for (int i = 0; i != n - 1; ++i) {
		b[i + 1] = a[i];
	}
	delete a;
	a = b;
	return true;
}

bool Stack::get_element(int& chislo) {
	if (n == 0) return false;
	chislo = *a;
	int* b = new int[--n];
	for (int i = 0; i != n; ++i) {
		b[i] = a[i + 1];
	}
	delete a;
	a = b;
	return true;
}

void Stack::charachteristics() {
	cout << get_name() << " " << get_size() << endl;
}