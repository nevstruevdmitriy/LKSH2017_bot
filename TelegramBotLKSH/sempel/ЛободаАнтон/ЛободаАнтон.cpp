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
      0 ??????
      1 ???????????
      2 ????!
      3 ????! ????! ????!
*/

int main() {
      
      int p=0;
     
      while(true){
            if(p<0){
                  tern(1);   //???????
                  ++p;
                  he_tern();
                  tern(0);   //??????
                  he_tern();
                  tern(2);   //???????
                  he_tern();
            }
            else{
                  tern(3);
            }
      }
      
}
