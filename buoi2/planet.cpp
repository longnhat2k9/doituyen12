#include<bits/stdc++.h>
using namespace std;

const long long MX = 2*100000 + 1; 
long long n, k;
long long adj[MX];
int d[MX];
queue<pair<long long, int>>q;
long long u, v;
bool ck = false;

void bfs()
{
	pair<long long, int> x;
	long long fi, se;
	while(!q.empty())
	{
		x = q.front();
		fi = x.first;
		se = x.second;
		d[fi] = 1;
		if(adj[fi] == v) 
		{
			while(!q.empty()) q.pop();
			cout << se + 1 << endl;
			ck = true;
			return;
		}
		if(d[adj[fi]] == 0) q.push({adj[fi], se + 1});
		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for(long long i = 1; i <= n; i++) cin >> adj[i];

	while(k--)
	{
		ck = false;
		memset(d, 0, sizeof(d));
		cin >> u >> v;
		if(u != v)
		{
			q.push({u, 0});
			bfs();
			if(ck == false) cout << -1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}

}