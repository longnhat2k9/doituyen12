#include<bits/stdc++.h>
using namespace std;

long long m, n;
char a[1020][1020];
long long d[1020][1020];
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
queue<pair<long long, long long>>q;
long long nx, ny;

void bfs()
{
	while(!q.empty())
	{
		auto [x, y] = q.front();

		if(d[x][y] == -1)
		{
			for(long long k = 0; k < 4; k++)
			{
				nx = x + dx[k];
				ny = y + dy[k];

				if(a[nx][ny] == '.' && d[nx][ny] == 0)
				{
					d[nx][ny] = k + 1;
					q.push({nx, ny});
				}
			}
		}
		else if(d[x][y] > 0)
		{
			long long k = d[x][y] - 1;
			nx = x + dx[k];
			ny = y + dy[k];
			if(a[nx][ny] == '.' && d[nx][ny] == 0)
			{
				d[nx][ny] = k + 1;
				q.push({nx, ny});
			}
			else if(a[nx][ny] == '#')
			{
				for(k = 0; k < 4; k++)
				{
					nx = x + dx[k];
					ny = y + dy[k];
	
					if(a[nx][ny] == '.' && d[nx][ny] == 0)
					{
						d[nx][ny] = k + 1;
						q.push({nx, ny});
					}
				}
			}
		}

		d[x][y] = -2;
		// cout << x << " " << y << endl;
		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> m >> n;
	memset(a, '#', sizeof(a));
	memset(d, 0, sizeof(d));

	for(long long i = 1; i <= m; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	d[2][2] = -1;
	q.push({2, 2});
	bfs();
	long long ans = 0;
	for(long long i = 1; i <= m; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			if(d[i][j] == -2) ans++;
			// cout << d[i][j] << " ";
		}
		// cout << endl;
	}

	cout << ans;
}