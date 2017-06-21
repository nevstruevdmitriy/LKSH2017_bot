#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

mt19937 rr(random_device{}());

int main() {
	srand(time(0));
	for (int i = 1; i <= 112; ++i) {
		if (rr() % 10 == 2) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
		int a;
		//cin >> a;
	}
	cout << 3 << endl;
}
