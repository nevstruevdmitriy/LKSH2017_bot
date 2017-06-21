#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector <int> vec(113);

/*
0 - защита
1 - зарядка
2 - бэнг
3 - БЭНГ
*/

bool fl;
int c1 = 0, c2 = 0;

void turn(int a) {
    if (!fl) {
        cout << a << endl;
        fl = 1;
        if (a == 1) {
            c1 = min(c1 + 1, 3);
        }
        if (a >= 2) {
            c1 = 0;
        }
    }
}

void get(int i) {
    cin >> vec[i];
    if (vec[i] == 1) {
        c2 = min(c2 + 1, 3);
    }
    if (vec[i] >= 2) {
        c2 = 0;
    }
}

void strategy1() {
    for (int i = 0; i < 113; ++i) {
        fl = 0;
        if (c1 == 3) {
            turn(3);
        }
        if (i == 112) {
            if (c1) {
                turn(2);
            } else {
                turn(0);
            }
        }
        if (c1 == 0 && c2 == 0) {
            turn(1);
        }
    }
}

void strategy2() {
    for (int i = 0; i < 113; ++i) {
        fl = 0;
        int c = c1 * 4 + c2;
        if (i == 112) {
            if (c1) {
                turn(max(c1, 2));
            } else {
                turn(0);
            }
        }
        switch (c) {
            case 0 : turn(1);
                     break;
            case 1 : turn(0);
                     break;
            case 2 : turn(1);
                     break;
            case 3 : turn(1);
                     break;
            case 4 : turn(1);
                     break;
            case 5 : turn(((rand() % 100) <= 50) ? 1 : 0);
                     break;
            case 6 : turn(2);
                     break;
            case 7 : turn(2);
                     break;
            case 8 : turn(1);
                     break;
            case 9 : turn(((rand() % 100) <= 50) ? 1 : 0);
                     break;
            case 10 : turn(rand() % 2 + 1);
                     break;
            case 11 : turn(2);
                     break;
            case 12 : turn(3);
                     break;
            case 13 : turn(0);
                     break;
            case 14 : turn(3);
                     break;
            case 15 : turn(3);
                     break;
        }
        get(i);
    }
}

int main() {
    srand(time(0));
    strategy2();
}
