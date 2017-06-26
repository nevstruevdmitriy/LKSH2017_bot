#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand(time(0));
	cout << 0 << endl;
	cout.flush();

	int bal = 0;
	
	for (int i = 0; i < 100; ++i) {
		if (rand() % 5 == 0 && bal != 0) {
			cout << 2 << endl;
			bal = 0;
			cout.flush();
		} else if (rand() % 5 == 1) {
			cout << 0 << endl;
			++bal;
			cout.flush();
		} else {
			cout << 1 << endl;
		}
	}

	cout << 3 << endl;
	cout.flush();
	return 0;
}
