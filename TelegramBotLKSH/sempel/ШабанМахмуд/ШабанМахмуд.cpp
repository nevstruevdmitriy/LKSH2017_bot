#include <iostream>
using namespace std;
int main() {
	int k, i = 0;
	cout << 1 << endl;
	cout.flush();
	i++;
	while (cin >> k) {
		if (i % 5 == 1)
			cout << 0 << endl;
		else if (i % 5 == 2)
			cout << 1 << endl;
		else if (i % 3 != 5)
			cout << 2 << endl;
		else
			cout << 1 << endl;
		cout.flush();
		i++;
	}
	return 0;
}