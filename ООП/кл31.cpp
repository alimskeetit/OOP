#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base {
protected:
	string name;
	Base* ptr_head;
	vector<Base*> childs;
public:
	bool ready = false;
	Base(Base* ptr_head = nullptr, string name = "") : ptr_head(ptr_head), name(name) {};
	void set_name();
	void set_name(string name);
	string get_name() { return name; };
	void out();
	void set_parent(Base& parent);
	Base* get_parent() { return ptr_head; };
	void new_out(string(*f)(Base& obj) = nullptr, int j = 1);
	Base* find(const string& name);
	void set_ready();
};

string is_ready(Base& obj);

class cl1 : public Base {
public:
	cl1(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class cl2: public Base {
public:
	cl2(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class cl3 : public Base {
public:
	cl3(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class cl4 : public Base {
public:
	cl4(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class cl5 : public Base {
public:
	cl5(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class cl6 : public Base {
public:
	cl6(Base* ptr_head = nullptr, string name = "") : Base(ptr_head, name) {};
	vector<Base*>& get_childs() { return childs; };
};

class App : Base {
public:
	App(Base* ptr_head) : Base(ptr_head) {};
	void build_tree();
	void build_tree_new();
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
	cout << this->get_name() << "  ";
	for (auto it : this->childs) {
		cout << (*it).get_name();
		if (it != this->childs.back()) cout << "  ";
	}
	if (this->childs.back()->childs.size()) {
		childs.back()->out();
	}
}

void Base::new_out(string (*f)(Base& obj), int j) {
	for (auto it : this->childs) {
		cout << endl;
		for (int i = 0; i != j; cout << "    ", ++i);
		cout << it->get_name();
		if (f) cout << f(*it);
		if (it->childs.size()) it->new_out(f, j + 1);
	}
}

Base* Base::find(const string& name)
{	
	if (this->name == name) return this;
	Base* find_ptr;
	for (auto it : this->childs) {
		if (it->get_name() == name) return it;
		if (it->childs.size()) {
			find_ptr = it->find(name);
			if (find_ptr) return find_ptr;
		}
	}
	return nullptr;
}

void Base::set_ready() {
	string name;
	int f;
	Base* ptr_find, *ptr_parent;
	while (cin >> name >> f) {
		ptr_find = this->find(name); //нашли того, кому установим готовность
		ptr_parent = ptr_find->get_parent();//берем родителя того, кого нашли
		ptr_find->ready = f;//ставим, что объект готов. если объект на самом деле не готов, то это исправится в цикле
		while (ptr_parent) { //пока не дошли до головного
			if (ptr_parent->ready) ptr_parent = ptr_parent->get_parent();//если родитель готов, то идем вверх по иерархии к родителю родителя
			else {														//если не готов, то готовность того, кого нашли 0
				ptr_find->ready = false;
				break;
			}
		}
	}
}

string is_ready(Base& obj) {
	return (obj.ready) ? " is ready" : " is not ready";
}


void App::build_tree() {
	this->set_name();
	cl1* obj1 = (cl1*)this; //самый-самый-самый корень
	while (true) {
		string name;
		cin >> name; //имя родителя
		cl1* obj2 = new cl1();
		obj2->set_name();//имя ребёнка

		if (name == obj2->get_name()) break; //условие конца иерархии

		if (name != obj1->get_name()) { //если родитель новый, то
			for (auto it = obj1->get_childs().begin(); it != obj1->get_childs().end(); ++it) { //в детях предыдущего ищем новго родителя
				if (name == (*it)->get_name()) {
					obj1 = (cl1*)(*it); //??? но работает))) ------ костыль
					break;
				}
			}
		}
		obj2->set_parent(*obj1);
	}
}

void App::build_tree_new() {
	this->set_name();
	cl1* obj1 = (cl1*)this; //самый-самый-самый корень
	while (true) {
		int i;
		string name, child_name;
		cin >> name; //имя родителя
		if (name == "endtree") break; //условие конца иерархии
		cin >> child_name;
		cin >> i;
		Base* obj2 = nullptr;
		switch (i)
		{
		case 2:
			obj2 = new cl2();
			break;
		case 3: 
			obj2 = new cl3();
			break;
		case 4:
			obj2 = new cl4();
			break;
		case 5:
			obj2 = new cl5();
			break;
		case 6:
			obj2 = new cl6();
			break;
		default:
			break;
		}
		obj2->set_name(child_name);

		if (name != obj1->get_name()) { //если родитель новый, то
			for (auto it = obj1->get_childs().begin(); it != obj1->get_childs().end(); ++it) { //в детях предыдущего ищем новго родителя
				if (name == (*it)->get_name()) {
					obj1 = (cl1*)(*it); //??? но работает))) ------ костыль
					break;
				}
			}
		}
		obj2->set_parent(*this->find(name));
	}
}

bool App::exe() {
	cout << "Object tree\n";
	cout << this->get_name();
	this->new_out();
	this->set_ready();
	cout << "The tree of objects and their readiness\n";
	cout << this->get_name();
	this->new_out(is_ready);
	return 0;
}

int main() {
	App app(nullptr);
	app.build_tree_new();
	return app.exe();
}