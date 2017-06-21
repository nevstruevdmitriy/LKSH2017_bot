#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;

int main() {
	for (int i = 0; i < 113; ++i) {
		cout << "0" << endl;
		sleep(0.5);
	}
	return 0;
}
