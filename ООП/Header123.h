#ifndef Header123_h
#define Header123_h

#include <iostream>
using namespace std;

class MyClass {
	long long n;
	int count = 0;
public:
	void set_n();
	long long get_n();
	void set_count();
	int get_count();
};
#endif