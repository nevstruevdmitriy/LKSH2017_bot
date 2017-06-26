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
	}
	return 0;
}