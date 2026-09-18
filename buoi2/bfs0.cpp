#include<bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long>adj[100000];
int d[100000];
queue<long long>q;

void bfs()
{
	long long u;
	while(!q.empty())
	{
		u = q.front();
		d[u] = 1;
		for(auto &v : adj[u])
		{
			if(d[v] == 0) q.push(v);
		}
		q.pop();
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

	q.push(1);
	bfs();

	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 1) cout << i << " ";
	}
}