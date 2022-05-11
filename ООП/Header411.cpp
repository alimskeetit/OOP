#include "Header411.h"

void Base::set_name() {
	cin >> this->name;
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

bool App::exe() {
	cout << this->get_name();
	this->out();
	return 0;
}