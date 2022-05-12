#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Base {
protected:
	string name;
	Base* ptr_head;
	vector<Base*> childs;
	void unready_em_all();
public:
	string last_adress;
	bool ready = false;
	Base(Base* ptr_head = nullptr, string name = "") : ptr_head(ptr_head), name(name) {};
	void set_name();
	void set_name(string name);
	string get_name() { return name; };
	void out();
	void set_parent(Base& parent);
	Base* get_parent() { return ptr_head; };
	void new_out(string(*f)(Base& obj) = nullptr, int j = 1);
	Base* find_(const string& name);
	void set_ready();
};

string is_ready(Base& obj);

vector<string> decode(string str) {
	vector<string> vec;
	string new_str;
	int count = 0;
	for (int i = 0; i != str.length(); ++i) {
		if (str[i] == '/') ++count;
	}
	vec.reserve(count + 1);
	str += '/';
	for (int i = 0; i != str.length(); ++i) {
		if (str[i] != '/') new_str += str[i];
		else {
			if (new_str != "") vec.push_back(new_str);
			new_str = "";
		}
	}
	return vec;
}

string set_find_moment(Base *obj1) {
	vector<string> vec;
	Base* obj = obj1;
	string string_to_return, str, set;
	cin >> str;
	while (true) {
		if (str == "FIND") {
			cin >> str;
			string_to_return += str + "     ";
			if (str == ".") str = set;
			else {
				vec = decode(str);
				for (auto& name : vec) {
					obj = obj->find_(name);
				}
				if (obj) str = obj->get_name();
			}
			string_to_return += (obj) ? "Object name: " + str : "Object is not found";
		}
		else if (str == "SET") {
			cin >> str;
			vec = decode(str);
			for (auto& name : vec) {
				obj = obj->find_(name);
			}
			if (obj) set = obj->get_name();
			if (obj) string_to_return += "Object is set: " + set;
			else string_to_return += "Object is not found: " + set + " " + str;
		}
		else if (str == "END") {
			string_to_return.pop_back();
			return string_to_return;
		}
		string_to_return += '\n';
		obj = obj1;
		cin >> str;
	}
}

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
	bool build_tree_new_new();
	bool exe(bool f = 0);
};

void Base::set_name() {
	cin >> this->name;
}

void Base::set_parent(Base& parent) {
	parent.childs.push_back(this); //родителю добавляем нового ребёнка
	if (this->get_parent()) {
		auto it_child = find(this->ptr_head->childs.begin(), this->ptr_head->childs.end(), this); //найти указатель на this в детях старого родителя
		this->ptr_head->childs.erase(it_child); //удалить this в детях старого родителя
	}
	this->ptr_head = &parent; //this присвоить нового ребёнка
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

bool App::exe(bool f) {
	//вывод дерева
	cout << "Object tree\n";
	cout << this->get_name();
	this->new_out();
	if (f) { //если build_tree_new_new построен с ошибкой, то
		cout << "The head object " << this->last_adress << " is not found"; 
		return 0;
	}
	cout << set_find_moment(this);
	return 0;
}


void Base::set_name(string name) {
	this->name = name;
}

void Base::new_out(string(*f)(Base& obj), int j) {
	for (auto it : this->childs) {
		cout << endl;
		for (int i = 0; i != j; cout << "    ", ++i);
		cout << it->get_name();
		if (f) cout << f(*it);
		if (it->childs.size()) it->new_out(f, j + 1);
	}
}

Base* Base::find_(const string& name) {
	if (this->name == name) return this;
	Base* find_ptr;
	for (auto it : this->childs) {
		if (it->get_name() == name) return it;
		if (it->childs.size()) {
			find_ptr = it->find_(name);
			if (find_ptr) return find_ptr;
		}
	}
	return nullptr;
}

void Base::set_ready() {
	string name;
	int f;
	Base* ptr_find, * ptr_parent;
	while (cin >> name >> f) {
		ptr_find = this->find_(name);
		ptr_parent = ptr_find->get_parent();
		ptr_find->ready = f;
		if (f) {
			while (ptr_parent) {
				if (ptr_parent->ready) ptr_parent = ptr_parent->get_parent();
				else {
					ptr_find->ready = false;
					break;
				}
			}
		}
		else {
			ptr_find->unready_em_all();
		}
	}
}

void Base::unready_em_all() {
	for (auto it : this->childs) {
		it->ready = false;
		if (it->childs.size()) it->unready_em_all();
	}
}

void App::build_tree_new() {
	this->set_name();
	cl1* obj1 = (cl1*)this;
	while (true) {
		int i;
		string name, child_name;
		cin >> name;
		if (name == "endtree") break;
		cin >> child_name;
		cin >> i;
		Base* obj2 = nullptr;
		switch (i) {
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
		default: break;
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
		obj2->set_parent(*this->find_(name));
	}
}



bool App::build_tree_new_new() {
	this->set_name();
	vector<string> vec;
	cl1* obj1 = (cl1*)this; //корневой объект
	while (true) {
		int i;
		string name, child_name;
		cin >> name;
		this->last_adress = name;//запомним последний адресс для того, чтобы в случае ошибки вывести его.
		if (name == "endtree") break; //конец ввода иерархии
		

		obj1 = (cl1*)this;//начинаем искать от корневого
		if (name != "/") {//если имя родителя не /, то есть не головной
			vec = decode(name);//вызываем функцию decode расшифровывающую адрес, и получаем вектор имён
			for (auto& name : vec) {
				obj1 = (cl1*)obj1->find_(name);//находим указатель на родителя, к которому пришпандорим ребенка
			}
		}
		if (!obj1) return 1; //если родитель не найден, то возвращаем 1, как ошибку.
		cin >> child_name;//ввод имени ребёнка
		cin >> i;//ввод класса ребёнка
		Base* obj2 = nullptr;
		switch (i) {
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
		default: break;
		}
		obj2->set_name(child_name);//устанавливаем новому объекту имя ребенка
		obj2->set_parent(*obj1);//устанавливаем родителя для obj2 и ребенка для obj1
	}
	return 0;
}

string is_ready(Base& obj) {
	return (obj.ready) ? " is ready" : " is not ready";
}

int main() {
	App app(nullptr);

	return app.exe(app.build_tree_new_new());
}