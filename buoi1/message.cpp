#include<bits/stdc++.h>
using namespace std;

int d[801];
long long n, k;
vector<long long>adj[801];

void dfs(long long u)
{
	d[u] = 1;
	for(auto &v : adj[u])
	{
		if(d[v] == 0) dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(d, 0, sizeof(d));

	cin >> n >> k;
	long long u, v;
	for(long long i = 0; i < k; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
	}

	// for(auto &x : adj) sort(x.begin(), x.end());

	long long cnt = 0, mn = 1e18;
	for(long long j = 1; j <= n; j++)
	{
		// cout << j << endl;
		cnt = 0;
		memset(d, 0, sizeof(d));
		for(long long i = j; i <= n; i++)
		{
			if(d[i] == 0)
			{
				cnt++;
				dfs(i);
				// for(long long j = 1; j <= n; j++) cout << d[j] << " ";
				// cout << endl;
			}
		}
		for(long long i = 1; i < j; i++)
		{
			if(d[i] == 0)
			{
				cnt++;
				dfs(i);
				// for(long long j = 1; j <= n; j++) cout << d[j] << " ";
				// cout << endl;
			}
		}
		mn = min(mn, cnt);
	}
	

	cout << mn;
}