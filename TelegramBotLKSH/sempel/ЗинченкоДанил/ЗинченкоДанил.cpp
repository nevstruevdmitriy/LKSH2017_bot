#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<deque>
#include<fstream>
#include<unordered_map>
#include<bitset>
#include<cstdio>


using namespace std;

/*
_______^(0,0)^___________^(0,0)^_________^(0,0)^____________________^(0,0)^_________^(0,0)^___________^(0,0)^_______
___^(0,0)^^(0,0)^______^(0,0)^_______^(0,0)^^(0,0)^______________^(0,0)^^(0,0)^_______^(0,0)^______^(0,0)^^(0,0)^___
__^(0,0)^__^(0,0)^____^(0,0)^_______^(0,0)^  ^(0,0)^____________^(0,0)^  ^(0,0)^_______^(0,0)^____^(0,0)^__^(0,0)^__
_^(0,0)^____^(0,0)^__^(0,0)^________^(0,0)^  ^(0,0)^____________^(0,0)^  ^(0,0)^________^(0,0)^__^(0,0)^____^(0,0)^_
_____________________^(0,0)^________^(0,0)^  ^(0,0)^____________^(0,0)^  ^(0,0)^________^(0,0)^_____________________
_____________________^(0,0)^________^(0,0)^  ^(0,0)^____________^(0,0)^  ^(0,0)^________^(0,0)^_____________________
_____________________^(0,0)^________^(0,0)^  ^(0,0)^____________^(0,0)^  ^(0,0)^________^(0,0)^_____________________
______________________^(0,0)^_______^(0,0)^  ^(0,0)^____________^(0,0)^  ^(0,0)^________^(0,0)^_____________________
_______________________^(0,0)^_______^(0,0)^^(0,0)^______________^(0,0)^^(0,0)^________^(0,0)^______________________
________________________^(0,0)^__________^(0,0)^______^(0,0)^_______^(0,0)^__________^(0,0)^________________________
________________________________________________________^(0,0)^_____________________________________________________
______________________________________________________^(0,0)^_______________________________________________________
@LiS
*/

int globalpatron1 = 0;
int globalpatron2 = 0;

int main() {
	srand(time(NULL));
	/*srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);*/
	//freopen("tree.in", "r", stdin);
	//freopen("tree.out", "w", stdout);
	int count = -1, xd;
	while (true)
	{
		count++;
		int t;
		if (count == 0)
		{
			cout << 1 << endl << 0 << endl << 0 << endl << 2 << endl << 0 << endl << 1 << endl << 0 << endl << 2 << endl;
			continue;
		}
		cin >> xd;
		if (globalpatron1 == 3)
		{
			cout << 3 << endl;
		}
		if (xd == 0)
		{
			if (globalpatron1)
			{
				cout << 2 << endl;
				globalpatron1--;
			}
			else
			{
				cout << 1 << endl;
				globalpatron1++;
			}
		}
		if (xd == 1)
		{
			globalpatron2++;
			if (globalpatron2 == 1)
				cout << 0 << endl;
			else
			{
				if (globalpatron1)
				{
					cout << 2 << endl;
					globalpatron1--;
				}
				else
				{
					cout << 1 << endl;
					globalpatron1++;
				}
			}
		}
		if (xd == 2)
		{
			globalpatron2--;
			cout << 1 << endl;
			globalpatron1++;
		}
	}
}
