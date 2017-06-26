#include <iostream>
using namespace std;
int main()
{
	int cnto=0, cntm=0, turn;
	bool p1=0, p2=0, p3=0;
	for(int i=0; true; ++i){
		if(i==0){
			cout<<1<<endl;
			cout.flush();
		}
		else{
			if(i%2==0)
			{
				cout<<0<<endl;
				cout.flush();
			}
			else{
				if(i<=5)
				{
					if(i==3)
					{
						cout<<1<<endl;
						cout.flush();
					}
					else
					{
						cout<<2<<endl;
						cout.flush();
					}
				}
				else
				{
					if(i<=13){
						if(i==7||i==9){
							cout<<1<<endl;
							cout.flush();
						}
						else
						{
							cout<<2<<endl;
							cout.flush();
						}
					}
					else
					{
						if((i-13)%8==2||(i-13)%8==4||(i-13)%8==6){
							cout<<1<<endl;
							cout.flush();
						}
						else
						{
							cout<<3<<endl;
							cout.flush();
						}
					}
				}
			}	
		}	
		cin>>turn;
		if(turn>=2){
			cnto=0;
		}
		if(turn==1){
			++cnto;
		}
	}
	return 0;
}