#include<bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long>adj[100000];
int d[100000];

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

	cin >> n >> k;

	long long v;
	for(long long u = 1; u <= n; u++)
	{
		long long j; cin >> j;
		for(long long i = 0; i < j; i++)
		{
			cin >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	dfs(k);

	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 1) cout << i << " ";
	}
}