#include <iostream>
using namespace std;
int main()
{
	int cnto=0, cntm=0, turn;
	bool p1=0, p2=0, p3=0;
	for(int i=0; true; ++i)
	{
		if(i==0)
		{
			cout<<1<<endl;
			cout.flush();
		}
		else
		{
			if(i%2!=0)
			{
				cout<<0<<endl;
				cout.flush();
			}
			else
			{
				if(i%7==4||i%7==6||i%7==2)
				{
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