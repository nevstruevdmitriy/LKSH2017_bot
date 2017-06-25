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
                  if(p<3) tern(1);   //???????
                  if(p<3) ++p;
                  if(p<3) he_tern();
                  if(p<3) tern(0);   //??????
                  if(p<3) he_tern();
                  if(p<3) tern(2);   //???????
                  if(p<3) he_tern();
                  if(p>=3) tern(3);
      }
      
}
