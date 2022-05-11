#include <iostream>
using namespace std;

void line(int n, int N);

int main() {
	int N;
	
	cin >> N;

	if (!(1 <= N && N <= 9)) cout << "N is wrong: " << N;
	else for (unsigned int i = 0; i != N; line(++i, N));
	return 0;
}

void line(int n, int N) {
	for (unsigned int i = 1; i != n + 1 ; ++i) {
		cout << i;
		if (i == n) {
			if (n != N) cout << endl;
		}
		else cout << " ";
	}
}