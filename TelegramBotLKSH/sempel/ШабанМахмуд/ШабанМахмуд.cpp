#include <iostream>
using namespace std;
int main() {
	int k, i = 0;
	cout << 1 << endl;
	cout.flush();
	while (cin >> k) {
		i++;
		if (i < 3)
			cout << 1 << endl;
		else
			cout << 3 << endl;
		cout.flush();
	}
	return 0;
}
