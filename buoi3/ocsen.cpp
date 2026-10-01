#include<bits/stdc++.h>
using namespace std;

long long m, n, x, y;
long long d[2010][2010];
long long a[2010][2010];
queue<pair<long long, long long>>q;
long long ans = 0;
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};

#define fi first
#define se second

void bfs()
{
	while(!q.empty())
	{
		ans++;
		auto f = q.front();
		for(long long k = 0; k < 4; k++)
		{
			if(d[f.fi + dx[k]][f.se + dy[k]] == 0 &&
				a[f.fi + dx[k]][f.se + dy[k]] == 0)
			{
				q.push({f.fi + dx[k], f.se + dy[k]});
				d[f.fi + dx[k]][f.se + dy[k]] = 1;
			}
		}

		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> m >> n >> x >> y;
	memset(a, 1, sizeof(a));
	memset(d, 0, sizeof(d));
	for(long long i = 1; i <= m; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	if(a[x][y] == 1)
	{
		cout << 0;
		return 0;
	}

	q.push({x, y});
	d[x][y] = 1;
	bfs();

	cout << ans;
}