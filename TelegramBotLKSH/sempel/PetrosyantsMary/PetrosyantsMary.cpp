#include <iostream>
using namespace std;

int main() {
	// your code goes here
	 int turn,p=0, r=1;
 while (true) 
 {
 
  if(p<1)
  {
  		p++;
  		cout << 1 << endl;
		cout.flush();
		r--;
		
  	}
  	
	if( r<=2 && p==1){
	
		cout << 0 << endl;
		cout.flush();
		r++;
	}
	else{
		if(p==3){
			cout << 3 << endl;
			cout.flush();
			r=1;
			p=0;
		}
		else{
			p++;
  			cout << 1 << endl;
			cout.flush();
		}
		
		
	}
  	
  
  
  cin >> turn;
  
 } 
	return 0;
}