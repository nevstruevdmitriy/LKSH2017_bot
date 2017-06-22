#include <iostream>

using namespace std;

int main() {
	int turná cnt = 0;
	while (true) {
		int k = rand() % 2;
		if (k == 1)
		{
			cnt++;
		}
		if (cnt == 3)
		{
			cout << 3 << endl;
		}
		else
		{
			cout << k << endl;
		}
		cout.flush();
		cin >> turn;
	}
}