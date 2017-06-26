#include <iostream>
using namespace std;

void tern(int n){
	cout << n << endl;
	cout.flush();
}

int main() {
	
	tern(1);
	tern(0);
	tern(0);
	tern(1);
	int t; cin >> t;
	if(t == 2)tern(2);
	else tern(0);
	tern(0);
	tern(1);
	tern(3);
	
	
	return 0;
}
