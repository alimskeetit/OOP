#include <iostream>
#include <vector>
using namespace std;

typedef unsigned char byte;
class Element {
	byte memory, shape;
public:
	Element(byte memory, byte shape): memory(memory), shape(shape) {}
	byte get_memory() {
		return memory;
	}
	byte get_shape() {
		return shape;
	}
	void operator&(Element &other);
	void operator|(Element &other);
};

void Element::operator&(Element& other) {
	byte new_shape = this->shape & other.get_shape();
	byte mid_step = this->memory & new_shape & other.get_memory() & new_shape;
	this->memory = this->memory & ~new_shape;
	this->memory = this->memory | mid_step;
}



void Element::operator|(Element& other) {
	this->memory = this->memory | (other.get_memory() & (this->shape & other.get_shape()));
}


int main() {
	vector<Element> elements;
	int n, a, b;
	char operation;
	cin >> n;
	elements.reserve(n);

	for (int i = 0; i != n; i++) {
		cin >> hex >> a >> hex >> b;
		elements.push_back(*new Element((byte)a, (byte)b));
	}

	while (cin >> a >> operation >> b) {
		--a; --b;
		switch (operation)
		{
			case '&':
				elements[a] & elements[b];
				break;
			case '|':
				elements[a] | elements[b];
				break;
		}
		b = a;
	}
	cout << hex << int(elements[b].get_memory());
}