#include<bits/stdc++.h>
using namespace std;

long long n, m;
char a[1020][1020];
long long d[1020][1020];
long long dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
long long dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
queue<pair<long long, long long>>q;
long long nx, ny;
long long cnt = 0;

void bfs()
{
	while(!q.empty())
	{
		auto [x, y] = q.front();

		for(long long k = 0; k < 8; k++)
		{
			nx = x + dx[k];
			ny = y + dy[k];

			// cout << a[nx][ny] << " " << d[nx][ny] << endl;

			if(a[nx][ny] == 'W' && d[nx][ny] == 0)
			{
				d[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	memset(d, 0, sizeof(d));
	memset(a, '.', sizeof(a));

	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			// cout << a[i][j] << " ";
		}
		// cout << endl;
	}

	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= m; j++)
		{
			if(a[i][j] == 'W' && d[i][j] == 0)
			{
				cnt++;
				d[i][j] = 1;
				q.push({i, j});
				bfs();
			}
		}
	}

	cout << cnt;
}