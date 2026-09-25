#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long cnt = 0;
vector<long long>adj[1000];
long long d[1000];

void dfs(long long u)
{
	d[u] = cnt;
	for(auto &v : adj[u])
	{
		if(d[v] != cnt) dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	long long u, v;
	for(long long i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 0)
		{
			cnt++;
			dfs(i);
		}
	}

	set<long long>dc;

	for(long long i = 1; i <= n; i++)
	{
		dc.insert(d[i]);
	}

	cout << dc.size();
}