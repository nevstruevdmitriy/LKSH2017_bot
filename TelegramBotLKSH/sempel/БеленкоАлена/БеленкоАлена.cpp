#include <iostream>

using namespace std;
int a[114];
int main() {
	a[1] = 1;
	a[2] = 2;
	a[3] = 1;
	a[4] = 1;
	a[5] = 1;
	a[6] = 3;
	int i = 1;
	int turn, cnt = 0;
	while (true) {
		if (i <= 6)
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