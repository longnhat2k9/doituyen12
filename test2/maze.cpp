#include<bits/stdc++.h>
using namespace std;

long long n, m;
const long long Mx = 1020;
char mat[1020][1020];
int d[1020][1020];
long long ncnt[1020][1020];
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};
long long cnt, mcnt = 0; 
long long mx, my;
queue<pair<long long, long long>>q;
stack<pair<long long, long long>>rock;

void bfs()
{
    cnt = 1;
    while(!q.empty())
    {
        auto [x, y] = q.front();

        for(long long k = 0; k < 4; k++)
        {
            mx = x + dx[k];
            my = y + dy[k];

            if(mat[mx][my] == '.' && d[mx][my] == 0)
            {
                d[mx][my] = mcnt;
                q.push({mx, my});
                cnt++;
            }
        }

        q.pop();
    }
}

void bfs_fill()
{
    long long mx, my;
    while(!q.empty())
    {
        auto [x, y] = q.front();

        for(long long k = 0; k < 4; k++)
        {
            mx = x + dx[k];
            my = y + dy[k];

            if(mat[mx][my] == '.' && d[mx][my] == mcnt)
            {
                ncnt[mx][my] = cnt;
                q.push({mx, my});
                d[mx][my] = 0 - mcnt;
            }
            if(mat[mx][my] == '*' && d[mx][my] == 0) 
            {
                rock.push({mx, my});
                d[mx][my] = -1;
            }
        }

        q.pop();
    }
}

void rock_fill()
{
    while(!rock.empty())
    {
        auto [x, y] = rock.top();
        ncnt[x][y] += cnt;
        d[x][y] = 0;
        rock.pop();
    }
}

void setup()
{
    memset(d, 0, sizeof(d));
    memset(mat, '#', sizeof(mat));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    // setup();
    cin >> n >> m;
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
                mcnt++;
                q.push({i, j});
                d[i][j] = mcnt;
                bfs();
                q.push({i, j});
                ncnt[i][j] = cnt;
                bfs_fill();
                rock_fill();
            }
        }
    }

    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= m; j++)
        {
            if(mat[i][j] == '*') 
            {
                cout << (ncnt[i][j] + 1) % 10;
                continue;
            }
            cout << mat[i][j];

        }
        cout << "\n";
    }

    // for(long long i = 1; i <= n; i++)
    // {
    //     for(long long j = 1; j <= m; j++)
    //     {
    //         cout << d[i][j];
    //     }
    //     cout << "\n";
    // }
    // for(long long i = 1; i <= n; i++)
    // {
    //     for(long long j = 1; j <= m; j++)
    //     {
    //         cout << ncnt[i][j];
    //     }
    //     cout << "\n";
    // }
}