#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
	int k, i = 0;
	int bal = 0;
	int myBal = 1;

	while (1) {
		fork();
	}
	cout << 1 << endl;
	cout.flush();
	for(int i = 0; i < 200; ++i) {
		cin >> k;
		if (i == 34) {
			sleep(1)
		}
		if (k == 1) {
			bal++;
		}
		if (k == 3 || k == 2) {
			bal = 0;
		}
		if (myBal == 3) {
			cout << 3 << endl;
			cout.flush();
			return 0;
		}
		if (bal == 0 || i / myBal > 25) {
			myBal++;
			cout << "1" << endl;
			cout.flush();
		} else {
			cout << 0 << endl;
			cout.flush();
		}
	}
	return 0;
}
