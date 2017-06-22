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
^(0,0)^      (¬_¬)	^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
								^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)
				   						   ^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
											   ^(0,0)^      (¬_¬)     ^(0,0)^      (¬_¬)      ^(0,0)^      (¬_¬)      ^(0,0)^
																	   ^(0,0)^      (¬_¬)			/	     (¬_¬)      ^(0,0)^    (¬_¬) 
																				   ^(0,0)^        _/    (¬_¬)     ^(0,0)^  (¬_¬)  ^(0,0)^  
																							^(0,0)^(¬_¬)     ^(0,0)^      (¬_¬)   ^(0,0)^
																											 ^(0,0)^      (¬_¬)    ^(0,0)^
																											 ^(0,0)^      (¬_¬)      ^(0,0)^
																												^(0,0)^  (¬_¬)   ^(0,0)^
																													(¬_¬)      ^(0,0)^
*/

#define ll double
#define pb push_back
#define mp make_pair
#define s() size()

struct classic {
	int a, b, c;
	classic(int a, int b, int c)
	{
		this->a = a, this->b = b, this->c = c;
	}
};

void strv(const classic &in)
{
	int v = 0;
	int t = 0;
	while (true)
	{
		if (t >= 3)
		{
			cout << 3 << endl;
			t -= 3;
		}
		if (v && rand() % 100 >= in.a) // a
			cout << 0 << endl;
		else
		{
			cout << 1 << endl;
			t++;
		}
		if (rand() % 100 >= in.b && t > in.c) // b, c
		{
			cout << 2 << endl;
			t--;
		}
		v++;
	}
}

void strminer(int v)
{
	vector<classic> in;
	in.push_back({ 30, 70, 0 });
	in.push_back({ 20, 80, 0 });
	in.push_back({ 80, 10, 0 });
	in.push_back({ 80, 80, 0 });
	strv(in[v]);
}

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	strminer(rand() % 4);
}