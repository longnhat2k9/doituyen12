#include<bits/stdc++.h>
using namespace std;

long long n;
vector<long long>adj[100000];
int d[100000];

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

	cin >> n;
	memset(d, 0, sizeof(d));

	long long x;
	for(long long u = 1; u <= n; u++)
	{
		for(long long v = 1; v <= n; v++)
		{
			cin >> x;
			if(x == 1) adj[u].push_back(v);
		}
	}

	long long cnt = 0;
	for(long long i = 1; i <= n; i++)
	{
		if(d[i] == 0)
		{
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
}