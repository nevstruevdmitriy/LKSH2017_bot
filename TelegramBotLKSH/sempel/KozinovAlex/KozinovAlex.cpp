#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAX_TEST = 10;

int cnt, cntE = 0;
void try_shot() {
    int enemy;

    cout << 1 << endl;
    cout.flush();
    cin >> enemy;
    cout << 0 << endl;
    cout.flush();
    cin >> enemy;
    cout << 0 << endl;
    cout.flush();
    cin >> enemy;
    cout << 2 << endl;
    cout.flush();
    cin >> enemy;
}

int main(int argc, char* argv[])
{
    while(true) {
        try_shot();
    }
}
