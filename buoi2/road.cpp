#include<bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long>adj[210];
pair<long long, long long> toado[210];
vector<pair<long long, long long>> road;

int d[210];

#define x first
#define y second

long long ck(long long a, long long b, long long c)
{
	long long k = (toado[b].x - toado[a].x) * (toado[c].y - toado[a].y) - (toado[b].y - toado[a].y) * (toado[c].x - toado[a].x);
	if(k < 0) return -1;
	else if(k > 0) return 1;
	else return 0;
}

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

	cin >> n >> m;

	long long u, v;
	for(long long i = 1; i <= n; i++)
	{
		cin >> toado[i].x >> toado[i].y;
	}

	for(long long i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		for(auto &k : road)
		{
			if(ck(k.x, k.y, u) != ck(k.x, k.y, v)) 
			{
				adj[u].push_back(k.x);
				adj[k.x].push_back(u);
			}
		}
		road.push_back({u, v});
	}

	memset(d, 0, sizeof(d));
	dfs(1);

	for(long long i = 1; i <= n; i++) if(d[i] == 1) cout << i << " ";
}