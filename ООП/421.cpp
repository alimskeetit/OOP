#include <iostream>
#include <string>
using namespace std;

class Cl1 {
	string name;
public: 
	Cl1(string name = "") {
		this->name = name + "_1";
	}
	void out() {
		cout << name;
	}
};

class Cl2 : public virtual Cl1 {
	string name;
public:
	Cl2(string name = ""): Cl1(name) {
		this->name = name + "_2";
	}
};

class Cl3 : public virtual Cl1 {
	string name;
public:
	Cl3(string name = ""): Cl1(name) {
		this->name = name + "_3";
	}
};

class Cl4 : public virtual Cl1 {
	string name;
public:
	Cl4(string name = ""): Cl1(name) {
		this->name = name + "_4";
	}
};

class Cl5 : public virtual Cl1 {
	string name;
public:
	Cl5(string name = ""):	Cl1(name) {
		this->name = name + "_5";
	}
};

class Cl6 : public Cl2, public Cl3 {
	string name;
public:
	Cl6(string name = ""): Cl2(name), Cl3(name) {
		this->name = name + "_6";
	}
};

class Cl7 : public Cl4, public Cl5 {
	string name;
public:
	Cl7(string name = ""): Cl4(name), Cl5(name) {
		this->name = name + "_7";
	}
};

class Cl8 : public Cl6, public Cl7 {
	string name;
public:
	Cl8(string name): Cl6(name), Cl7(name) {
		this->name = name + "_8";
	}
};


int main() {
	Cl1* x;
	string ident;
	cin >> ident;
	Cl8 obj(ident);
	x = &obj;
}