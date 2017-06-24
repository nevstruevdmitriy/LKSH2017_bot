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
double v[3] = { 33, 33, 33 };

void func(int e)
{
	for (int i = 0; i < 3; i++)
		if (e == i)
			v[i] += (100 - v[i]) / 2;
		else
			v[i] /= 2;
}

void bang() {
	if (globalpatron1 == 3)
	{
		cout << 3 << endl;
		exit(0);
	}
	int e0 = rand() % 100, e1 = rand() % 100, e2 = rand() % 100;
	bool tr0 = (e0 <= v[0]), tr1 = (e1 <= v[1]), tr2 = (e2 <= v[2]);
	vector<pair<int, int>> otv;
	if (tr0)
		otv.push_back({ e0 *-1, 0 });
	if (tr1)
		otv.push_back({ e1 *-1, 1 });
	if (tr2 && globalpatron1 > 0)
		otv.push_back({ e2 *-1, 2 });
	sort(otv.begin(), otv.end());
	if (otv.size())
	{
		if ((*otv.begin()).second == 2)
			globalpatron1--;
		if ((*otv.begin()).second == 1)
			globalpatron1++;
		cout << (*otv.begin()).second << endl;
	}
	else
	{
		otv.push_back({ e0 *-1, 0 });
		otv.push_back({ e1 *-1, 1 });
		if (globalpatron1 > 0)
			otv.push_back({ e2 *-1, 2 });
		sort(otv.begin(), otv.end());
		if ((*otv.begin()).second == 2)
			globalpatron1--;
		if ((*otv.begin()).second == 1)
			globalpatron1++;
		cout << (*otv.begin()).second << endl;
	}
}

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
			cout << 1 << endl;
			globalpatron1++;
			continue;
		}
		cin >> xd;
		if (xd == 0)
		{
			func(0);
			func(2);
		}
		if (xd == 1)
		{
			func(0);
			func(2);
			globalpatron2++;
		}
		if (xd == 2)
		{
			func(1);
			func(2);
			globalpatron2--;
		}
		if (globalpatron2 == 0)
			v[0] = 0, v[1] = 35, v[2] = 65;
		bang();
	}
}