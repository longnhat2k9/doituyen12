#include<bits/stdc++.h>
using namespace std;

long long m, n;
char mat[1020][1020];
long long d[1020][1020];
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {-1, 0, 1, 0};

void setup()
{
    memset(d, 0, sizeof(d));
    // memset(mat, '#', sizeof(mat)); // optional
}

void dfs(long long i, long long j)
{
    d[i][j] = 1;
    long long u, v; 
    for(long long k = 0; k < 4; k++)
    {
        u = i + dx[k];
        v = j + dy[k];
        if(mat[u][v] == '.' && d[u][v] == 0) dfs(u, v);
    }    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    setup();

    cin >> m >> n;
    for(long long i = 1; i <= m; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }

    long long cnt = 0;
    for(long long i = 1; i <= m; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            if(mat[i][j] == '.' && d[i][j] == 0)
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt;
}