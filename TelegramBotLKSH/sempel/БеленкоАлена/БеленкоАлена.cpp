#include <iostream>

using namespace std;
int a[114];
int main() {
	a[1] = 1;
	a[2] = 1;
	a[3] = 0;
	a[4] = 1;
	a[5] = 3;
	int turn, cnt = 0;
	int i = 1;
	while (true) {
		if (i <= 5)
		{
			cout << a[i]<<endl;
			i++;
		}
		else
		{
			i = 1;
			cout << a[i]<<endl;
		}
		cout.flush();
		cin >> turn;
	}
}