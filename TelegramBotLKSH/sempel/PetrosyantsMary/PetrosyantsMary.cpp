#include <iostream>
using namespace std;

int main() {
	// your code goes here
	 int turn,p=0, r=0;
 while (true) 
 {
 
  if(p<1)
  {
  		p++;
  		cout << 1 << endl;
		cout.flush();
		r++;
		
  	}
	if( r==1 && p==1){
		r--;
		cout << 0 << endl;
		cout.flush();
	}
  	else
  	{
  		
  		p--;
  		cout << 2 << endl;
		cout.flush();
		
  	}
  
  
  cin >> turn;
  
 } 
	return 0;
}