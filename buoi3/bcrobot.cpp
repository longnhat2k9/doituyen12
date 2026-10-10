#include<bits/stdc++.h>
using namespace std;

long long n;
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
char a[1020][1020];
int d[1020][1020];
queue<pair<long long, long long>>q;

bool bfs1()
{
	d[1][1] = 1;
	while(!q.empty())
	{
		auto [x, y] = q.front();
		
		for(long long k = 0; k < 2; k++)
		{
			if(a[x + dx[k]][y + dy[k]] == '.')
			{
				d[x + dx[k]][y + dy[k]]++;
				q.push({x + dx[k], y + dy[k]});
			}

		}
		q.pop();
	}
	return (d[n][n] != 0);
}

bool bfs2()
{
	d[1][1] = 1;
	while(!q.empty())
	{
		auto [x, y] = q.front();
		
		for(long long k = 0; k < 4; k++)
		{
			if(x + dx[k] == n && y + dy[k] == n) return true;
			if(d[x + dx[k]][y + dy[k]] == 0 && a[x + dx[k]][y + dy[k]] == '.')
			{
				d[x + dx[k]][y + dy[k]] = 1;
				q.push({x + dx[k], y + dy[k]});
			}

		}
		q.pop();
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(a, '#', sizeof(a));
	memset(d, 0, sizeof(d));

	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	q.push({1, 1});
	bool ck1 = bfs1();
	long long mem = d[n][n];
	memset(d, 0, sizeof(d));
	q.push({1, 1});
	bool ck2 = bfs2();

	if(ck1 && ck2) cout << mem;
	else if(!ck1 && ck2) cout << "THE GAME IS A LIE";
	else cout << "INCONCEIVABLE";
}