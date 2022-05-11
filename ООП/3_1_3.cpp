#include <iostream>
#include "header3_1_3.h"
#include "funcs.h"
using namespace std;

int main() {
	int chislo;
	
	Stack obj1 = *create_obj();
	Stack obj2 = *create_obj();

	do
	{
		cin >> chislo;
	} while (obj1.add_element(chislo) && obj2.add_element(chislo));
	
	obj1.charachteristics();
	obj2.charachteristics();
	
	format1();
	cout << obj1.get_name();
	format1();
	cout << obj2.get_name();
	show_elements(obj1, obj2);
}