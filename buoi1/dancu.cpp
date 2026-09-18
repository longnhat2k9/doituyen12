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
	memset(d, 0, sizeof(d));

	long long u, v;
	for(long long i = 0; i < k; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	long long cnt = 0;
	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 0)
		{
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
}