#include <iostream>
using namespace std;

class base {
protected:
	int n, * arr;
public:
	virtual void in_out() {
		cin >> n;
		arr = new int[n];
		for (int i = 0; i != n; cin >> arr[i++]);
	}
};

class cl1 : public base {
public:
	int func() {
		for (int i = 1; i != n; ++i) {
			arr[0] -= arr[i];
		}
		return arr[0];
	}
};

class cl2 : public cl1 {
public: 
	int func() {
		int sum;
		for (int i = 0; i != n; sum += arr[i++]);
		return sum;
	}
};

class cl3 : public cl2 {
public:
	void in_out() {
		cout << n << endl;
		for (int i = 0; i != n; cout << arr[i]);
		cout << endl;
		cout << cl1::func() << endl;
		cout << cl2::func();
	}
};

int main() {
	base* ptr = new base();
	ptr->in_out();
	ptr->(cl3::in_out());
}