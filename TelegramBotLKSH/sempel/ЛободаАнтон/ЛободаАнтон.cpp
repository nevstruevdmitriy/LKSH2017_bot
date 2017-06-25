#include <iostream>
using namespace std;

void te(int ans){
      cout << ans << endl;
      cout.flush();
      int t;
      cin >> t;
}

/*
      0 çàùèòà
      1 ïåðåçàðÿäêà
      2 áåíã
      3 ÁÅÍÃ ÁÅÍÃ ÁÅÍÃ
*/

int main() {
      
      int p=0;
      te(1);
      te(0);
      te(2);
      for(int i=1; true; ++i){
                 
                 te(1);
                 ++p;
                 if(i == 2)te(2); else te(0);
                 te(0);
                 if(p>=3)
                 te(3);
                   
      }
      
}
