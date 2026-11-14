#include<bits/stdc++.h>
using namespace std;

long long n, m, t;
char mat[1020][1020];
long long d[1020][1020], ans[1020][1020], pic[1020][1020];
long long cnt = 0;
queue<pair<long long, long long>>q;
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};

void bfs()
{
    while(!q.empty())
    {
        auto [x, y] = q.front();

        long long mx, my;
        for(long long k = 0; k < 4; k++)
        {
            mx = x + dx[k];
            my = y + dy[k];

            if(mat[mx][my] == '.' && d[mx][my] == 0)
            {
                q.push({mx, my});
                d[mx][my] = 1;
            }

            // if(mat[mx][my] == '*' && pic[mx][my] == 0)
            // {
            //     pic[mx][my] = 1;
            //     cnt++;
            // }
            if(mat[mx][my] == '*')
            {
                cnt++;
            }
        }

        q.pop();
    }
}

void bfs_fill()
{
    while(!q.empty())
    {
        auto [x, y] = q.front();

        long long mx, my;
        for(long long k = 0; k < 4; k++)
        {
            mx = x + dx[k];
            my = y + dy[k];

            if(mat[mx][my] == '.' && d[mx][my] == 1)
            {
                q.push({mx, my});
                ans[mx][my] = cnt;
                d[mx][my] = -1;
            }
        }

        q.pop();
    }
}

void setup()
{
    memset(d, 0, sizeof(d));
    memset(mat, '#', sizeof(mat));
    memset(ans, 0, sizeof(ans));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    setup();

    cin >> n >> m >> t;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= m; j++)
        {
            if(mat[i][j] == '.' && d[i][j] == 0)
            {
                // cout << i << " " << j << endl;
                cnt = 0;
                // memset(pic, 0, sizeof(pic));
                d[i][j] = 1;
                q.push({i, j});
                bfs();
                ans[i][j] = cnt;
                d[i][j] = -1;
                q.push({i, j});
                bfs_fill();
            }
        }
    }

    // for(long long i = 1; i <= n; i++)
    // {
    //     for(long long j = 1; j <= m; j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    long long x, y;
    while(t--)
    {
        cin >> x >> y;
        cout << ans[x][y] << "\n";
    }
}