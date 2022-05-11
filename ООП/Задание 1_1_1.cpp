#include <iostream>
using namespace std;

bool even(int);

int main() {
	int n;
	
	cin >> n;
	if (!(n % 2)) cout << "even";
	else cout << "uneven";
	
	return 0;
}
