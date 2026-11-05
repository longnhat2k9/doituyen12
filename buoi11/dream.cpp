#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, k; cin >> n >> k;
	map<long long, vector<long long>>mp;

	for(long long i = 1; i <= n; i++)
	{
		long long x; cin >> x;
		mp[x].push_back(i);
	}

	long long cnt = 0;

	for(auto &x : mp)
	{
		long long u, v;
		auto a = x.second;
		u = 0, v = 0;
		while(u <= v && v < a.size())
		{
			if(a[v] - a[u] <= k) 
			{
				v++;
				continue;
			}
			else 
			{
				cnt++;
				u = v;
			}
		}
		cnt++;
	}

	cout << cnt;
}