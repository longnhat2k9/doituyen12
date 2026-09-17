#include<bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long>adj[100000];
int d[100000];
long long s, t;

void dfs(long long u)
{
	d[u] = 1;
	for(auto &v : adj[u])
	{
		if(v == t) s = -10;
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

	long long q; cin >> q;
	while(q--)
	{
		memset(d, 0, sizeof(d));
		cin >> s >> t;
		d[s] = 1;
		dfs(s);
		if(s == -10) cout << 1 << endl;
		else cout << -1 << endl;
	}
}