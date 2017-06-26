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
		else if (cntTurns == 1){
			cout << 0 << endl;
		}
		
		else{
			if (DNIWE && enemyBul < 3){
				cout << 1 << endl;
				DNIWE = 0;
			}
			else{
				cout << 0 << endl;
			}
			if (!DNIWE){
				if (DNO && turn != 1){
					DNO = 0;
					cout << 1 << endl;
				}
				else{
					if (enemyBul == 2){
						if (turn == 1 && bullets>0 && bullets < 3){
							cout << 2 << endl;
							bullets=0;
							++enemyBul;
						}
						if (turn == 1 && bullets == 0){
							cout << 1 << endl;
							++bullets;
							++enemyBul;
						}
						if (turn == 0 && bullets > 0 && bullets < 3){
							cout << 1 << endl;
							++bullets;
						}
						if (turn == 0 && bullets > 2){
							cout << 3 << endl;
							bullets=0;
						}
						if (turn == 1 && bullets > 2){
							cout << 3 << endl;
							bullets = 0;
						}
						if (turn >1 && bullets > 2){
							cout << 3 << endl;
							bullets = 0;
						}
						if (turn >1 && bullets > 0 && bullets<2){
							cout << 2 << endl;
							bullets = 0;
						}
						if (turn >1 && bullets ==0){
							cout << 1 << endl;
							++bullets;
						}
					}
				}
			}
			if (!DNIWE || !DNO){
				if (turn == 1){
					cout << 0 << endl;
					++enemyBul;
				}
				else{

					if (bullets == 3){
						cout << 3 << endl;
						bullets = 0;
					}
					else{
						if (turn == 0 && bullets < 3 && bullets >= 0){
							cout << 2 << endl;
							bullets = 0;
						}
						if (turn == 0 && bullets == 0){
							cout << 0;
							DNO = 1;
						}

						if (turn == 2 && bullets > 0 && bullets < 3){
							cout << 2 << endl;
							enemyBul = 0;
							bullets = 0;
						}
						if (turn == 2 && bullets >= 3){
							cout << 3 << endl;
							enemyBul = 0;
							bullets = 0;
						}
						if (turn == 2 && bullets == 0){
							cout << 1 << endl;
							enemyBul = 0;
							++bullets;
						}
						if (turn == 3 && bullets > 0 && bullets < 3){
							cout << 2 << endl;
							enemyBul = 0;
							bullets = 0;
						}
						if (turn == 3 && bullets >= 3){
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
				}
			}
			
		}
		++cntTurns;
		cout.flush();
		cin >> turn;
	}
}