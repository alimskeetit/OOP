#ifndef header531_h
#define header531_h
class Class1 {
	int a;
public:
	Class1(int& a1) : a(a1) {}
	int foo(int& x);
};

class Class2 : public Class1 {
	int a;
public:
	Class2(int& a1, int& a2) :Class1(a1), a(a2) {}
	int foo(int& x);
};

class Class3 : public Class2 {
	int a;
public:
	Class3(int& a1, int& a2, int& a3) : Class2(a1, a2), a(a3) {}
	int foo(int& x);
};

class Class4 : public Class3 {
	int a;
public:
	Class4(int& a1, int& a2, int& a3, int& a4) : Class3(a1, a2, a3), a(a4) {}
	int foo(int& x);
};
#endif