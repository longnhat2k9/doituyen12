#include<bits/stdc++.h>
using namespace std;

long long n, sx, sy;
char a[1020][1020];
long long d[1020][1020];
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};
queue<pair<long long, long long>>q1;
queue<pair<pair<long long, long long>, long long>> q2;
long long cnt = 0, cnts = 0;
long long nx, ny;

void bfs1()
{
	while(!q1.empty())
	{
		auto [x, y] = q1.front();

		for(long long k = 0; k < 4; k++)
		{
			nx = x + dx[k];
			ny = y + dy[k];

			if(a[nx][ny] == '.' && d[nx][ny] == 0)
			{
				d[nx][ny] = cnt;
				q1.push({nx, ny});
			}

		}

		q1.pop();
	}
}

long long bfs2()
{
	while(!q2.empty())
	{
		auto f = q2.front();
		auto [x, y] = f.first;
		auto m = f.second;

		for(long long k = 0; k < 4; k++)
		{
			nx = x + dx[k];
			ny = y + dy[k];

			if(a[nx][ny] == '#' && d[nx][ny] == 0)
			{
				d[nx][ny] = -1;
				q2.push({{nx, ny}, m + 1});
			}

			if(d[nx][ny] == d[sx][sy])
			{
				d[nx][ny] = -1;
				q2.push({{nx, ny}, 0});
			}

			if(a[nx][ny] == '.' && d[nx][ny] != -1 && d[nx][ny] != cnts)
			{
				return m;
			}
		}
		q2.pop();
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> sx >> sy;

	memset(d, 0, sizeof(d));
	memset(a, '.', sizeof(a));

	for(long long i = 0; i <= n + 1; i++)
	{
		a[i][0] = a[0][i] = a[n + 1][i] = a[i][n + 1] = '#';
	}

	for(long long i = 0; i < n; i++)
	{
		long long x, y; cin >> x >> y;
		a[x][y] = '#';
	}

	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			if(a[i][j] == '.' && d[i][j] == 0)
			{
				cnt++;
				while(!q1.empty()) q1.pop();

				d[i][j] = cnt;
				q1.push({i, j});
				bfs1();
			}
		}
	}

	cnts = d[sx][sy];


	while(!q2.empty()) q2.pop();

	q2.push({{sx, sy}, 0});
	long long ans = bfs2();
	cout << ans;
}