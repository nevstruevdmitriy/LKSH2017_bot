#include <iostream>
using namespace std;

int main() {
	// your code goes here
	 int turn,p=0;
 while (true) 
 {
 
  if(p<2)
  {
  		p++;
  		cout << 1 << endl;
		cout.flush();
		
  	}
  	else{
  		p--;
  		cout << 2 << endl;
		cout.flush();
		
  	}
  
  
  cin >> turn;
  
 }
	return 0;
}
