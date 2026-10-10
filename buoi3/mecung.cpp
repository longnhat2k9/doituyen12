#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

long long m, n, sx, sy, tx, ty;
long long a[1020][1020];
long long d[1020][1020];
long long dx[5] = {0, 1, 0, -1, 0};
long long dy[5] = {0, 0, 1, 0, -1};
queue<pair<long long, long long>>q;
vector<pair<long long, long long>>ans;

void setup()
{
	memset(d, 0, sizeof(d));
	memset(a, 2, sizeof(a));
	q.push({sx, sy});
	d[sx][sy] = -1;
}

bool bfs()
{
	while(!q.empty())
	{
		auto [x, y] = q.front();
		// cout << x << " " << y << " " << d[x][y] << " " << a[x][y] << endl;
		
		for(long long k = 1; k <= 4; k++)
		{
			// cout << x + dx[k] << " " << y + dy[k] << " " << a[x + dx[k]][y + dy[k]] << endl;
			if(d[x + dx[k]][y + dy[k]] == 0 &&
				a[x + dx[k]][y + dy[k]] == 0)
			{
				d[x + dx[k]][y + dy[k]] = k;
				q.push({x + dx[k], y + dy[k]});
			}

			// khi dung memset(a, 2, sizeof(a)) thi gia tri duoc ghi vao la 144680345676153346, co the tu in ra console de biet duoc
			if(a[x + dx[k]][y + dy[k]] == 144680345676153346) 
			{
				tx = x;
				ty = y;
				d[x + dx[k]][y + dy[k]] = k;
				// cout << tx << " " << ty << endl;
				return true;
			}
		}
		
		q.pop();
	}
	return false;
}

void recall()
{
	auto x = tx, y = ty, k = d[x][y];
	while(x != sx || y != sy)
	{
		ans.push_back({x, y});
		x -= dx[k];
		y -= dy[k];
		k = d[x][y];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> sx >> sy;
	setup();
	for(long long i = 1; i <= m; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			// cout << a[i][j];
		}
		// cout << endl;
	}

	if(bfs() == false)
	{
		cout << 0;
		return 0;
	}

	recall();

	ans.push_back({sx, sy});
	reverse(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for(auto &x :  ans) cout << x.fi << " " << x.se << endl;
}