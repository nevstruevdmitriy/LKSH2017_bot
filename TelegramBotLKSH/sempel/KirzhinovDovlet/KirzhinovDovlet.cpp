#include <iostream>

using namespace std;

int main() {
	int turn;
	bool DNO=0;
	bool DNIWE = 0;
	int cntTurns = 0, bullets = 0, enemyBul = 0;
	while (true) {
		if (!cntTurns) {
			cout << 1 << endl;
			++bullets;
		}
		else{
			if (DNIWE && enemyBul < 3){
				cout << 1 << endl;
				DNIWE = 0;
			}
			if (DNO && turn!=1){
				DNO = 0;
				cout << 1 << endl;
			}
			if (turn == 1){
				cout << 0 << endl;
				++enemyBul;
			}
			if (enemyBul >= 3){
				cout << 0 << endl;
				DNIWE = 1;
			}
			if (turn == 0 && bullets == 3){
				cout << 3 << endl;
				bullets = 0;
			}
			if (turn == 0 && bullets <3 && bullets>=0){
				cout << 2 << endl;
				bullets = 0;
			}
			if (turn == 0 && bullets == 0){
				cout << 0;
				DNO = 1;
			}
			
			if (turn == 2 && bullets>0 && bullets<3){
				cout << 2<<endl;
				enemyBul = 0;
				bullets = 0;
			}
			if (turn == 2 &&  bullets>=3){
				cout << 3 << endl;
				enemyBul = 0;
				bullets = 0;
			}
			if (turn == 2 && bullets==0){
				cout << 1 << endl;
				enemyBul = 0;
				++bullets;
			}
			if (turn == 3 && bullets > 0 && bullets < 3){
				cout << 2 << endl;
				enemyBul = 0;
				bullets = 0;
			}
			if (turn == 3 && bullets>=3){
				cout << 3 << endl;
				enemyBul = 0;
				bullets = 0;
			}
			if (turn == 3 && bullets == 0){
				cout << 1 << endl;
				enemyBul = 0;
				++bullets;
			}
			
			
		}
		++cntTurns;
		cout.flush();
		cin >> turn;
	}
}