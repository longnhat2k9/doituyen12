#include<bits/stdc++.h>
using namespace std;

char adj[1020][1020];
long long dm[1020][1020], da[1020][1020], p[1020][1020];
long long n, m;
queue<pair<long long, long long>>q;
pair<long long, long long>s;
long long dx[5] = {0, 1, 0, -1, 0};
long long dy[5] = {0, 0, 1, 0, -1};
long long key[5] = {'#', 'D', 'R', 'U', 'L'};

void setup()
{
    for(long long i = 0; i < 1020; i++)
    {
        for(long long j = 0; j < 1020; j++)
        {
            dm[i][j] = 1e18;
            da[i][j] = 0;
            p[i][j] = 0;
            adj[i][j] = '#';
        }
    }
}

void bfsm()
{
    long long mx, my;
    while(!q.empty())
    {
        auto [x, y] = q.front();

        for(long long k = 1; k <= 4; k++)
        {
            mx = x + dx[k];
            my = y + dy[k];
            if(dm[x][y] + 1 < dm[mx][my] && adj[mx][my] == '.')
            {
                q.push({mx, my});
                dm[mx][my] = dm[x][y] + 1;
            }
        }

        q.pop();
    }
}

bool bfsa()
{
    long long ax, ay;
    while(!q.empty())
    {
        auto [x, y] = q.front();
        if(x == 1 || x == n || y == 1 || y == m) return true;

        for(long long k = 1; k <= 4; k++)
        {
            ax = x + dx[k];
            ay = y + dy[k];
            if(da[x][y] + 1 < dm[ax][ay] && adj[ax][ay] == '.' && da[ax][ay] == 0)
            {
                q.push({ax, ay});
                da[ax][ay] = da[x][y] + 1;
                p[ax][ay] = k;
                if(ax == 1 || ax == n || ay == 1 || ay == m) return true;
            }
        }

        q.pop();
    }
    return false;
}

void trace()
{
    auto [x, y] = q.back();
    string ans = "";
    while(p[x][y] != -1)
    {
        auto k = p[x][y];
        ans += key[k];
        x -= dx[k];
        y -= dy[k];
    } 

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n" << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    setup();

    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
            if(adj[i][j] == 'M') q.push({i, j}), dm[i][j] = 0;
            if(adj[i][j] == 'A') s = {i, j}, p[i][j] = -1;
        }
    }

    bfsm();
    q.push(s);
    bool ck = bfsa();
    if(ck == false) 
    {
        cout << "NO";
        return 0;
    }

    cout << "YES \n";
    trace();
}