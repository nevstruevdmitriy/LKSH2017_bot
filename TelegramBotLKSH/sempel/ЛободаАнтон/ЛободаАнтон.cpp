#include <iostream>
using namespace std;

void tern(int ans){
      cout << ans << endl;
      cout.flush();
}

/*
      0 çàùèòà
      1 ïåðåçàðÿäêà
      2 áåíã
      3 ÁÅÍÃ ÁÅÍÃ ÁÅÍÃ
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
