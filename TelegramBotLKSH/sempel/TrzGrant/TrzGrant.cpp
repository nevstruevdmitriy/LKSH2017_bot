#include <iostream>

using namespace std;

int main() {
    int turn;
    cout << 0 << endl;
    cout.flush();
    cin >> turn;
    for (int i = 0; i < 3; ++i) {
        cout << 1 << endl;
        cout.flush();
        cin >> turn;
    }
    cout << 3;
}
