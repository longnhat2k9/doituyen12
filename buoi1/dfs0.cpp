#include<bits/stdc++.h>
using namespace std;

int d[100000];
long long n, k;
vector<long long>adj[100000];

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
		adj[v].push_back(u);
	}

	d[1] = 1;
	dfs(1);

	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 1) cout << i << " ";
	}
}