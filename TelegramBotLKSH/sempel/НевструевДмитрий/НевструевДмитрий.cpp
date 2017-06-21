#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;

int main() {
	for (int i = 0; i < 115; ++i) {
		cout << "0" << endl;
		sleep(1);
	}
	return 0;
}
