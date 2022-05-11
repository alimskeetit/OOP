#include <iostream>
#include "Array.h"
using namespace std;

int main() {

	Array a;
	
	a.SetArray();
	cout << "N = " << a.GetSize() << endl;
	a.GetArray();
	cout << endl;
	a.ReverseArray();
	a.GetArray();
	
	return 0;
}