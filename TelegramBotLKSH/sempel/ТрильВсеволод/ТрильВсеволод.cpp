#include <iostream>
using namespace std;
int main()
{
	int cnto=0, cntm=0, turn;
	while(true)
	{
		if(cnto>=2)
		{
			if(cntm>=3)
			{
				cout<<3;
				cntm=0;
			}
			else
			{
				cout<<2;	
			}
		}
		else
		{
			if(cnto==0&&cntm>0&&cntm<3)
			{
				cout<<2;
			}
			else
			{
				if(cntm>=3)
				{
					cout<<0;
				}
				else
				{
					if(cntm==0&&cnto>=1)
					{
						cout<<0;
					}
					else
					{
						cout<<1;
						++cntm;
					}
				}
			}
		}
		cout.flush();
		cin>>turn;
		if(turn==1)
		{
			++cnto;
		}
	}
	return 0;
}