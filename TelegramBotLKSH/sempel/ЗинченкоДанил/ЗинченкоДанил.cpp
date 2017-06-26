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
struct fenwick
{
	long long n, m, t;
	vector<vector<vector<long long>>> B;

	fenwick(long long n, long long m, long long t)
	{	
		this->n = n;
		this->m = m;
		this->t = t;
		B.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			B[i].resize(m + 1);
			for (int j = 0; j <= m; j++)
				B[i][j].resize(t + 1);
		}
	}

	void add(long long x1, long long y1, long long z1, long long d)
	{
		for (int x = x1; x <= this->n; x = (x | (x + 1)))
			for (int y = y1; y <= this->m; y = (y | (y + 1)))
				for (int z = z1; z <= this->t; z = (z | (z + 1)))
					B[x][y][z] += d;
	}

	long long rsqfw(long long x1, long long y1, long long z1)
	{
		long long ans = 0;
		for (int x = x1; x >= 0; x = (x & (x + 1)) - 1)
			for (int y = y1; y >= 0; y = (y & (y + 1)) - 1)
				for (int z = z1; z >= 0; z = (z & (z + 1)) - 1)
					ans += B[x][y][z];
		return ans;
	}

	long long rsq(long long x1, long long x2, long long y1, long long y2, long long z1, long long z2)
	{
		return rsqfw(x2, y2, z2) - rsqfw(x2, y1 - 1, z2) - rsqfw(x2, y2, z1 - 1) - rsqfw(x1 - 1, y2, z2) + rsqfw(x1 - 1, y1 - 1, z2) + rsqfw(x1 - 1, y2, z1 - 1) + rsqfw(x2, y1 - 1, z1 - 1) - rsqfw(x1 - 1, y1 - 1, z1 - 1);
	}
};

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.setf(ios::fixed);
	//cout.precision(0);
	//freopen("fenwick.in", "r", stdin);
	//freopen("fenwick.out", "w", stdout);
	long long n;
	cin >> n;
	fenwick f(n, n, n);
	while(true)
	{
		long long x1, x2, y1, y2, z1, z2;
		int a;
		cin >> a;
		if (a == 3)
			return 0;
		cin >> x1 >> y1 >> z1 >> x2;
		if (a == 1)
			f.add(x1, y1, z1, x2);
		else
		{
			cin >> y2 >> z2;
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			if (z1 > z2)
				swap(z1, z2);
			cout << f.rsq(x1, x2, y1, y2, z1, z2) << endl;
		}
	}
}
