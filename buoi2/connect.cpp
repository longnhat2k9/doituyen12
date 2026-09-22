#include<bits/stdc++.h>
using namespace std;

vector<long long>adj[100010];
long long d[100010];
long long cnt = 1;
long long n, k;

void dfs(long long u)
{
	d[u] = cnt;
	for(auto &v : adj[u])
	{
		if(d[v] == 0) cout << v << " ", dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("CONNECT.INP", "r", stdin);
    freopen("CONNECT.OUT", "w", stdout);

	cin >> n >> k;
	long long u, v;
	for(long long i = 0; i < k; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 0) 
		{
		    cout << i << " ";
		    dfs(i);
		    cout << "\n";
		}
	}

}