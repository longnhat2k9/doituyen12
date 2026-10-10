#include<bits/stdc++.h>
using namespace std;

long long m, n;
char a[1020][1020];
int d[1020][1020];
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
queue<pair<long long, long long>>q;
long long cnt = 0;

void bfs()
{
	while(!q.empty())
	{
		auto [x, y] = q.front();

		for(long long k = 0; k < 4; k++)
		{
			long long nx = x + dx[k];
			long long ny = y + dy[k];

			if(a[nx][ny] == '0' && d[nx][ny] == 0)
			{
				d[nx][ny] = 1;
				q.push({nx, ny});
				cnt++;
			}

			if(a[nx][ny] == '#') 
			{
				cnt = 0;
				return;
			}
		}

		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(a, '#', sizeof(a));
	memset(d, 0, sizeof(d));

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
			if(a[i][j] == '0' && d[i][j] == 0)
			{
				while(!q.empty())
				{
					q.pop();
				}
				cnt = 1;

				q.push({i, j});
				d[i][j] = 1;
				bfs();

				if(cnt != 0)
				{
					cout << cnt;
					return 0;
				}
			}
		}
	}

	cout << 0;
}