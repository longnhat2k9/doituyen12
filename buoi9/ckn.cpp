#include<bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> adj[20010];
long long d[20010];

void dfs(long long u)
{
	for(auto &v : adj[u])
	{
		if(d[v] == 0) 
		{
			d[v] = 1;
			dfs(v);
		}
	}
}

queue<long long>q;
void bfs()
{
	while(!q.empty())
	{
		auto u = q.front();
		for(auto &v : adj[u])
		{
			if(d[v] == 0)
			{
				d[v] = 1;
				q.push(v);
			}
		}
		q.pop();
	}
}


int main()
{
	cin >> n >> m;
	for(long long i = 0; i < m; i++)
	{
		long long u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(long long i = 1; i <= n; i++)
	{
		memset(d, 0, sizeof(d));
		d[i] = 1;
		long long cnt = 0;
		for(long long j = 1; j <= n; j++)
		{
			if(d[j] == 0)
			{
				d[j] = 1;
				cnt++;
				q.push(j);
				bfs();
			}
		}

		cout << cnt << "\n";
	}
}