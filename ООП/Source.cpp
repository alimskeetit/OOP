#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Base {
protected:
	string name;
	Base* ptr_head;
	vector<Base*> childs;
public:
	Base(Base* ptr_head = nullptr, string name = "") : ptr_head(ptr_head), name(name) {};
	void set_name();
	void set_name(string);
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

class cl2 : public Base {
public:
	cl2(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class App : Base {
public:
	App(Base* ptr_head) : Base(ptr_head) {};
	void build_tree();
	bool exe();
};

void Base::set_name() {
	cin >> this->name;
}

void Base::set_name(string name) {
	this->name = name;
}

void Base::set_parent(Base& parent) {
	parent.childs.push_back(this);
	this->ptr_head = &parent;
}

void Base::out() {
	cout << endl;
	cout << this->get_name() << " ";
	for (auto it : this->childs) {
		cout << (*it).get_name() << " ";
	}
	if (this->childs.back()->childs.size()) {
		childs.back()->out();
	}
}

void App::build_tree() {
	this->set_name();
	cl1* obj1 = new cl1(nullptr, this->get_name());
	cl1* OBJ = obj1;
	while (true) {
		string name;
		cin >> name; //имя родителя
		cl1* obj2 = new cl1();
		obj2->set_name();//имя ребёнка

		if (name == obj2->get_name()) break;

		if (name != obj1->get_name()) {
			for (auto it = obj1->get_childs().begin(); it != obj1->get_childs().end(); ++it) {
				if (name == (*it)->get_name()) {
					//cl1* tmp = new cl1(nullptr, name);
					//tmp->set_parent(*obj1);

					obj1 = new cl1(obj1, name);
					break;
				}
			}
		}
		
		obj2->set_parent(*obj1);
	}
}

bool App::exe() {
	cout << this->get_name();
	this->out();
	return 0;
}

int main() {
	App app(nullptr);
	app.build_tree();
	return app.exe();
}