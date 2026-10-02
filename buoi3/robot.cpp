#include<bits/stdc++.h>
using namespace std;

long long m, n, sx, sy, tx, ty;
char a[1020][1020];
long long d[1020][1020];
long long dx[5] = {0, 0, 1, 0, -1};
long long dy[5] = {0, 1, 0, -1, 0};
vector<pair<long long, long long>>ans;
queue<pair<long long, long long>> q;

#define fi first
#define se second

bool bfs() {

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        if (f.fi == tx && f.se == ty) return true; 

        for (long long k = 1; k <= 4; k++) {
            long long nx = f.fi + dx[k];
            long long ny = f.se + dy[k];

            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
                if (a[nx][ny] == '0' && d[nx][ny] == 0) {
                    d[nx][ny] = k; 
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

void recall()
{
	long long x = tx, y = ty, k = d[x][y];

	while(x != sx || y != sy)
	{
		ans.push_back({x, y});
		k = d[x][y];			
		x -= dx[k];
		y -= dy[k];
		// break;
	}
	ans.push_back({sx, sy});
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> m >> n >> sx >> sy >> tx >> ty;

	memset(a, '1', sizeof(a));
	memset(d, 0, sizeof(d));

	for(long long i = 1; i <= m; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	d[sx][sy] = 10;
    q.push({sx, sy});

	if(bfs() == true)
	{
		// ans.push_back({tx, ty});
		recall();
		reverse(ans.begin(), ans.end());
		for(auto &x : ans) cout << x.first << " " << x.second << endl;

		return 0;
	}

	cout << "-1";
}