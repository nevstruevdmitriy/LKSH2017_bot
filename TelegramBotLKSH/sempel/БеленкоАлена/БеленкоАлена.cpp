#include <iostream>

using namespace std;

int main() {
	int turn, cnt = 0;
	while (true) {
		int k = rand() % 2;
		if (cnt >= 3)
		{
			cout << 3 << endl;
			cnt -= 3;
		}
		else
		{
			cout << k << endl;
		}

		if (k == 1)
		{
			cnt++;
		}
		cout.flush();
		cin >> turn;
	}
}