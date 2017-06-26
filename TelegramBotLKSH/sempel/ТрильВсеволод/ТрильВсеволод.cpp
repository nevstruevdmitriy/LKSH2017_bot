#include <iostream>
using namespace std;
int main()
{
	int cnto=0, cntm=0, turn;
	while(true)
	{
		if(cntm<=2)
		{
			cout<<1<<endl;
			cout.flush();
			cntm++;
		}
		else
		{
			if(cnto<=2)
			{
				cout<<0<<endl;
				cout.flush();
			}
			if(cnto>2)
			{
				cout<<2<<endl;
				cout.flush();
				cntm=0;
			}
			
		}
		cin>>turn;
		if(turn>=2)
		{
			cnto=0;
		}
		if(turn==1)
		{
			++cnto;
		}
	}
	return 0;
}