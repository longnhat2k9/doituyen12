#include<bits/stdc++.h>
using namespace std;

long long m, n;
char a[1020][1020];
long long d[1020][1020];

long long cnt;
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};

void dfs(long long ux, long long uy)
{
    cnt++;
    d[ux][uy] = 1;
    long long x, y;
    for(long long k = 0; k < 4; k++)
    {
        x = ux + dx[k];
        y = uy + dy[k];

        if(d[x][y] == 0 && a[x][y] == a[ux][uy])
        {
            dfs(x, y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    vector<long long>res;
    memset(a, '#', sizeof(a));
    memset(d, 0, sizeof(d));
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
                cnt = 0;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n" << *res.rbegin();
}
