#include <iostream>
using namespace std;

void tern(int ans){
      cout << ans << endl;
      cout.flush();
}

/*
      0 çàùèòà
      1 ïåğåçàğÿäêà
      2 áåíã
      3 ÁÅÍÃ ÁÅÍÃ ÁÅÍÃ
*/

int main() {
      
       int t;
       tern(1);
       cin >> t;
       while(true){
                cin >> t;
                if(t != 0)tern (2);
                else tern(0)   
       }
       
}
