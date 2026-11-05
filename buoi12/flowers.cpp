#include<bits/stdc++.h>
using namespace std;

long long n, m, x; 
const long long Mx = 1e3 + 10;
vector<long long>adj[Mx];
queue<long long>q;
long long d[Mx];
long long p[Mx];

void bfs()
{
	while(!q.empty())
	{
		long long u = q.front();
		for(auto &v : adj[u])
		{
			if(v == n)
			{
				d[v] = 1;
				p[v] = u;
				return;
			}
			if(d[v] == 0)
			{
				q.push(v);
				d[v] = 1;
				p[v] = u;
			}
		}
		q.pop();
	}
}

void trace()
{
	vector<long long> ans(1, n);
	long long u = n;
	while(u > 1)
	{
		ans.push_back(p[u]);
		u = p[u];
	}

	reverse(ans.begin(), ans.end());
	cout << x - ans.size() + 2 << "\n";
	for(auto &x : ans) cout << x << " ";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x;
	for(long long i = 0; i < m; i++)
	{
		long long u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fill(d, d + Mx, 0);
	fill(p, p + Mx, 0);
	q.push(1);
	bfs();

	trace();
}