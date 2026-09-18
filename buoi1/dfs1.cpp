#include<bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long>adj[100000];
int d[100000];
long long s, t;
long long cnt = 1;

void dfs(long long u)
{
	d[u] = cnt;
	for(auto &v : adj[u])
	{		
		if(d[v] == 0) dfs(v);
	}
}

int main()
{
	cin >> n >> k;
	long long u, v;
	for(long long i = 0; i < k; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(d, 0, sizeof(d));
	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}

	long long q; cin >> q;
	while(q--)
	{
		cin >> s >> t;
		if(d[s] == d[t]) cout << 1 << endl;
		else cout << -1 << endl;
	}
}