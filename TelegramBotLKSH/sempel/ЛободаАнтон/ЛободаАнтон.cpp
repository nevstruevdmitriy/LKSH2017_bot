#include <iostream>
using namespace std;

void tern(int ans){
      cout << ans << endl;
      cout.flush();
}

void he_tern(){
      int t;
      cin >> t;
}

/*
      0 ������
      1 �����������
      2 ����!
      3 ����! ����! ����!
*/

int main() {
     
      while(true){
            tern(1);   //�������
            he_tern();
            tern(0);   //������
            he_tern();
            tern(2);   //�������
            he_tern();
      }
      
}