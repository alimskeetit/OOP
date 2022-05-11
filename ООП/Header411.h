#ifndef Header411_h
#define Header411_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base {
protected:
	string name;
	Base* ptr_head;
	vector<Base*> childs;
public:
	Base(Base* ptr_head = nullptr, string name = "") : ptr_head(ptr_head), name(name) {};
	void set_name();
	string get_name() { return name; };
	void out();
	void set_parent(Base& parent);
	Base* get_parent() { return ptr_head; };
};

class cl1 : public Base {
public:
	cl1(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class App : Base {
public:
	App(Base* ptr_head) : Base(ptr_head) {};
	void build_tree();
	bool exe();
};

#endif // !Header411_h