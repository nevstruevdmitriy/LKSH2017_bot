#include <iostream>
using namespace std;

void te(int ans){
      cout << ans << endl;
      cout.flush();
      int t;
      cin >> t;
}

/*
      0 ������
      1 �����������
      2 ����
      3 ���� ���� ����
*/

int main() {
      
      int p=0;
      
      while(true){
                 
                 te(1);
                 ++p;
                 te(0);
                 te(0);
                 if(p>=3)
                 te(3);
                   
      }
      
}
