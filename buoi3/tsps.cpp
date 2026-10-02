#include<bits/stdc++.h>
using namespace std;

char a[1020][1020];
long long m, n;
long long d[1020][1020];
queue<pair<long long, long long>>q;
long long cnt = 0;
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};


#define fi first
#define se second

void bfs()
{
	while(!q.empty())
	{
		auto f = q.front();

		d[f.fi][f.se] = cnt;
		for(long long k = 0; k < 4; k++)
		{
			if(a[f.fi][f.se] == a[f.fi + dx[k]][f.se + dy[k]] &&
				d[f.fi + dx[k]][f.se + dy[k]] == 0)
			{
				q.push({f.fi + dx[k], f.se + dy[k]});
			}
		}
		q.pop();
	}
}

int main()
{
	memset(d, 0, sizeof(d));
	memset(a, '1', sizeof(a));

	cin >> m >> n;
	for(long long i = 1; i <= m; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	for(long long i = 1; i <= m; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			if(d[i][j] == 0)
			{
				cnt++;
				q.push({i, j});
				bfs();
			}
		}
	}

	long long a, b, x, y;
	while(!cin.eof())
	{
		cin >> a >> b >> x >> y;
		if(d[a][b] == d[x][y]) cout << 1 << endl;
		else cout << 0 << endl;
	}
}