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
      0 Защита
      1 Перезарядка
      2 бенг!
      3 Бенг! Бенг! Бенг!
*/

int main() {
     
      while(true){
            tern(1);   //зарядка
            he_tern();
            tern(0);   //защита
            he_tern();
            tern(2);   //выстрел
            he_tern();
      }
      
}