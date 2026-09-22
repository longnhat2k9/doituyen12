#include<bits/stdc++.h>
using namespace std;

long long n, s, t;
vector<long long>adj[100000];
long long d[100000];
long long p[100000];
queue<long long>q;

void bfs()
{
	long long u;
	while(!q.empty())
	{
		u = q.front();

		for(auto &v : adj[u])
		{
			if(d[v] == 0)
			{
				p[v] = u;
				q.push(v);
				d[v] = 1;
			}
			if(v == t)
			{
				p[v] = u;
				d[v] = 1;
				return;
			}
		}
		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(p, 0, sizeof(p));
	memset(d, 0, sizeof(d));

	long long u, v; 
	cin >> n >> s >> t;

	while(!cin.eof())
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(s);
	bfs();

	if(d[t] == 0) cout << -1;
	else
	{
		vector<long long>ans;
		while(s != t)
		{
			ans.push_back(t);
			t = p[t];
		}
		ans.push_back(s);
		reverse(ans.begin(), ans.end());
		for(auto &x : ans) cout << x << " ";
	}
}