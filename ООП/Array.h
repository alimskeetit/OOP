#ifndef Array_h
#define Array_h
#include <iostream>
using namespace std;
class Array
{
	int ar[10], size;
public:
	Array() { cin >> size; };
	int GetSize();
	void SetArray();
	void GetArray();
	void ReverseArray();
};

int Array::GetSize() {
	return size;
}
#endif 
