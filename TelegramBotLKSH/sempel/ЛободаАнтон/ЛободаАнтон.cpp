#include <iostream>
using namespace std;

void tern(int ans){
      cout << ans << endl;
      cout.flush();
}

/*
      0 ������
      1 �����������
      2 ����
      3 ���� ���� ����
*/

int main() {
      
       int t;
       tern(1);
       tern(0);
       tern(2);
       tern(1);
       tern(1);
       tern(0);
       tern(1);
       tern(3);
}
