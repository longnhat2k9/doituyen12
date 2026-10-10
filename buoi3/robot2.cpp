#include<bits/stdc++.h>
using namespace std;

long long n, m; 
char a[1020][1020];
long long d[1020][1020];
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
queue<pair<long long, long long>> q;

void bfs()
{
	long long nx, ny;
	while(!q.empty())
	{
		auto [x, y] = q.front();

		for(long long k = 0; k < 4; k++)
		{
			nx = x + dx[k];
			ny = y + dy[k];

			if(a[nx][ny] == '0' && d[nx][ny] == 0)
			{
				d[nx][ny] = k + 1;
				q.push({nx, ny});
			}

			if(nx == m && ny == n)
			{
				return;
			}
		}

		q.pop();
	}
}

char conv(long long k)
{
	if(k == 1) return 'D';
	if(k == 2) return 'R';
	if(k == 3) return 'U';
	return 'L';
}

void recall()
{
	long long x = m,  y = n;
	vector<char>ans;
	long long k;
	while(d[x][y] != -1)
	{
		k = d[x][y];
		ans.push_back(conv(k));
		x -= dx[k - 1];
		y -= dy[k - 1];
	}

	if(ans.size() % 2 == 1)
	{
		cout << "#";
		return;
	}

	reverse(ans.begin(), ans.end());

	for(long long i = 0; i < ans.size() / 2; i++)
	{
		cout << ans[i];
	}
	cout << endl;
	for(long long i = ans.size() - 1; i >= ans.size() / 2; i--)
	{
		if(ans[i] == 'L') cout << 'R';
		else if(ans[i] == 'R') cout << 'L';
		else if(ans[i] == 'U') cout << 'D';
		else cout << 'U';
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

	d[1][1] = -1;
	q.push({1, 1});
	bfs();

	if(d[m][n] != 0) recall();
}