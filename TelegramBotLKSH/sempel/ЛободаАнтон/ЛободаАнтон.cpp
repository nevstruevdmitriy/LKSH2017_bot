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
      0 çàùèòà
      1 ïåğåçàğÿäêà
      2 áåíã
      3 ÁÅÍÃ ÁÅÍÃ ÁÅÍÃ
*/

int main() {
      
      int t;
     
      while(true){
                   tern(1);   //???????
                   he_tern();
                   tern(0);   //??????
                   he_tern();
                   tern(2);   //???????
                   he_tern();
                   tern(1);
                   cin >> t;
                   if(t != 1)tern(1);
                   else{
                        
                        tern(0);
                        tern(1);
                        tern(2);
                        
                   }
                   he_tern();
                   tern(0);
                   he_tern();
                   tern(1);
                   tern(3);
                   he_tern();
      }
      
}
