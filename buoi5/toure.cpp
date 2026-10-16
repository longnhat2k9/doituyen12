#include<bits/stdc++.h>
using namespace std;

long long n, m;
const long long M = 1e6;
long long a[M];
vector<long long>adj[M];
vector<pair<long long, long long>>edge[M];
long long mx = -1, mn = 1e18, mid;
vector<long long> d(M), parent(M);
queue<long long>q;

void setup()
{
	fill(d.begin(), d.end(), 0);
	while(!q.empty()) q.pop();
	q.push(1);
	d[1] = 1;
}

bool bfs()
{
	while(!q.empty())
	{
		auto u = q.front();
		if(u == n) return true;

		for(auto &v : adj[u])
		{
			if(d[v] == 0 && abs(a[u] - a[v]) <= mid)
			{
				parent[v] = u;
				d[v] = 1;
				q.push(v);
			} 
		}

		q.pop();
	}
	
	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for(long long i = 1; i <= n; i++) cin >> a[i];

	long long u, v;
	for(long long i = 1; i <= m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		edge[u].push_back({v, i});
		adj[v].push_back(u);
		edge[v].push_back({u, i});
		mx = max(mx, abs(a[u] - a[v]));
		mn = min(mn, abs(a[u] - a[v]));
	}

	long long ans;

	while(mx >= mn)
	{
		setup();
		mid = (mx + mn) / 2;
		if(bfs() == 1)
		{
			ans = mid;
			mx = mid - 1;
		}
		else 
		{
			mn = mid + 1;
		}
	}

	cout << ans << endl;;
	mid = ans;
	bfs();

	vector<long long>trace;

	for(long long i = n; i > 1; )
	{
		for(auto &x : edge[i])
		{
			if(x.first == parent[i]) 
			{
				trace.push_back(x.second);
				break;
			}
		}
		i = parent[i];
	}

	reverse(trace.begin(), trace.end());
	for(auto &x : trace) cout << x << " ";
}