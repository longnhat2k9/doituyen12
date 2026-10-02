#include<bits/stdc++.h>
using namespace std;

char a[1020][1020];
long long d[1020][1020];
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};
queue<pair<long long, long long>>q;
long long m, n, cnt = 0, cntm, mx = 0;

#define fi first
#define se second

void bfs()
{
	cntm = 0;
	while(!q.empty())
	{
		cntm++;
		auto f = q.front();
		d[f.fi][f.se] = cnt;

		for(long long k = 0; k < 4; k++)
		{
			if(a[f.fi + dx[k]][f.se + dy[k]] == a[f.fi][f.se] &&
				d[f.fi + dx[k]][f.se + dy[k]] == 0)
			{
				q.push({f.fi + dx[k], f.se + dy[k]});
			}
		}

		q.pop();
	}
	mx = max(mx, cntm);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(d, 0, sizeof(d));
	memset(a, 'a', sizeof(a));

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

	cout << cnt << endl << mx;
}