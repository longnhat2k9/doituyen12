#include<bits/stdc++.h>
using namespace std;

long long n, m;
vector<pair<long long, long long>> adj[10101];
queue<pair<long long, long long>>q;
int d[10101];
long long s, t;

bool bfs()
{
	pair<long long, long long> f;
	while(!q.empty())
	{
		f = q.front();


		d[f.first] = 1;
		for(auto x : adj[f.first])
		{		
			// cout << f.first << " " << x.first << " " << x.second << endl;
			if(d[x.first] == 0)
			{
				q.push({x.first, max(f.second, x.second)});
			}
			if(x.first == t)
			{
				if(max(f.second, x.second) == 2) return 1;
				else return 0;
			}
		} 
		q.pop();
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	long long u, v;
	for(long long i = 2; i <= n; i++)
	{
		cin >> u >> v;
		adj[i].push_back({u, v});
		adj[u].push_back({i, v});
	}

	while(m--)
	{
		// cout << "=====" << endl;
		cin >> s >> t;
		memset(d, 0, sizeof(d));
		while(!q.empty()) 
		{
			q.pop();
		}
		q.push({s, 1});
		if(bfs())
		{
			cout << "YES \n"; 
		}
		else 
		{
			cout << "NO \n";
		}
	}
}