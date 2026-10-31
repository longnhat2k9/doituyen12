#include<bits/stdc++.h>
using namespace std;

char a[1020][1020];
long long d[1020][1020];
long long m, n, c = 0, f = 0;
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
queue<pair<long long, long long>>q;

#define fi first
#define se second

void bfs()
{
	long long cntc = 0, cntf = 0;
	while(!q.empty())
	{
		auto f = q.front();
		if(a[f.fi][f.se] == 'c') cntc++;
		if(a[f.fi][f.se] == 'f') cntf++;

		// cout << f.fi << " " << f.se << " " << cntc << " " << cntf << " x " << endl;

		for(long long k = 0; k < 4; k++)
		{
			if(d[f.fi + dx[k]][f.se + dy[k]] == 0 &&
				a[f.fi + dx[k]][f.se + dy[k]] != '#')
			{
				d[f.fi + dx[k]][f.se + dy[k]] = 1;
				q.push({f.fi + dx[k], f.se + dy[k]});
			}
		}
		q.pop();
	}

	if(cntc > cntf) c += cntc;
	else f += cntf;
	// cout << cntc << " " << cntf << " " << c << " " << f << endl;
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
			if(d[i][j] == 0 && a[i][j] != '#')
			{
				d[i][j] = 1;
				q.push({i, j});
				bfs();
			}
		}
	}

	cout << f << " " << c;
}