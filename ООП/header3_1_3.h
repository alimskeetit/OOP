#ifndef header3_1_3_h
#define header3_1_3_h
#include <iostream>
using namespace std;
class Stack
{
	int size, n = 0;
	int* a = new int[size];
	char* name;
public:
	Stack(char* p_name, int size);
	bool add_element(const int& chislo);
	bool get_element(int& chislo);
	char* get_name() { return name; };
	int get_size() { return size; };
	void charachteristics();
};
#endif // !header3_1_3_h