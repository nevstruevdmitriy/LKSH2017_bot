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
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
*/

#define ll double
#define pb push_back
#define mp make_pair
#define s() size()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int v = 0;
	int t = 0;
	while (true)
	{
		if (v && rand() % 100 >= 30)
			cout << 0 << endl;
		else
		{
			cout << 1 << endl;
			t++;
		}
		if (t >= 3)
		{
			cout << 3 << endl;
			t -= 3;
		}
		if (rand() % 100 > 55 && t > 0)
		{
			cout << 2 << endl; 
			t--;
		}
		v++;
	}
}