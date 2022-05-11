#ifndef Class2_h
#define Class2_h

class Class2 {
	int a, b;
public:
	friend int maximum(int a, int b);
	void set_a_b(int a, int b);
	int get_a();
	int get_b();
};
#endif
