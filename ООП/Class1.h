#ifndef Class1_h
#define Class1_h

class Class1 {
	int a;
public:
	Class1(int a = 0);
	friend int maximum(int a, int b);
	int get_a() { return a; };
};

Class1::Class1(int a) : a(a) {}

#endif