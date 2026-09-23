#include<bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> adj[220];
queue<pair<long long, long long>>q;
long long s, t;
int d[220];

long long bfs()
{
	long long u;
	while(!q.empty())
	{
		u = q.front().first;
		d[u] = 1;
		for(auto &v : adj[u])
		{
			if(d[v] == 0)
			{
				q.push({v, q.front().second + 1});
			}
			if(v == t)
			{
				return q.front().second + 1;
			}
		}
		q.pop();
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	long long u, v;
	for(long long i = 1; i <= n; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cin >> t;
	long long ans = 0;
	for(long long i = 1; i < m; i++)
	{
		s = t;
		cin >> t;
		while(!q.empty())
		{
			q.pop();
		}
		memset(d, 0, sizeof(d));
		q.push({s, 1});
		long long cnt = bfs();
		ans += cnt;
	}

	cout << ans;
}