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
				cout<<3<<endl;
				cout.flush();
				cntm=0;
			}
			else
			{
				cout<<2<<endl;
				cout.flush();
				cntm--;
			}
		}
		else
		{
			if(cnto==0&&cntm>=1&&cntm<2)
			{
				cout<<1<<endl;
				cout.flush();
				++cntm;
			}
			else
			{
				if(cntm>=3)
				{
					cout<<0<<endl;
					cout.flush();
				}
				else
				{
					if(cnto>=1)
					{
						cout<<0<<endl;
						cout.flush();
					}
					else
					{
						cout<<1<<endl;
						cout.flush();
						++cntm;
					}
				}
			}
		}
		cin>>turn;
		if(turn==1)
		{
			++cnto;
		}
	}
	return 0;
}