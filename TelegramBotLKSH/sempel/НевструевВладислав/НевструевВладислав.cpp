#include <iostream>
#include <random>

using namespace std;

mt19937 rr(random_device{}());

int main() {
	for (int i = 1; i <= 112; ++i) {
		if (rr() % 10 == 2) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	cout << 3 << endl;
}