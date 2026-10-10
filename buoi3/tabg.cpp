#include<bits/stdc++.h>
using namespace std;

long long m, n;
char a[1020][1020];
int d[1020][1020];
int mat[1020][1020];
int d2[1020];
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
vector<long long> adj[1020];
queue<pair<long long, long long>>q;
long long nx, ny, mx, my;
long long t, cnt;

void bfs1()
{
    while(!q.empty())
    {
        auto [x, y] = q.front();
        
        if(a[x][y] == '*')
        {
            for(long long k = 0; k < 4; k++)
            {
                nx = x + dx[k];
                ny = y + dy[k];
                
                if(a[nx][ny] != '#' && d[nx][ny] == 0)
                {
                    d[nx][ny] = 1;
                    q.push({nx, ny});
                    mx = a[nx][ny] - 'A' + 1;
                    my = 30;
                    mat[mx][my] = mat[my][mx] = 1;
                }
            }
        }
        else
        {
            for(long long k = 0; k < 4; k++)
            {
                nx = x + dx[k];
                ny = y + dy[k];
                
                if(a[nx][ny] != '#' && d[nx][ny] == 0)
                {
                    d[nx][ny] = 1;
                    q.push({nx, ny});
                    if(a[nx][ny] != a[x][y])
                    {
                        mx = a[nx][ny] - 'A' + 1;
                        if(a[nx][ny] == '*') mx = 30;
                        my = a[x][y] - 'A' + 1;
                        mat[mx][my] = mat[my][mx] = 1;
                    }
                }
            }
        }
        
        q.pop();
    }
}

void adj_conv()
{
    for(long long i = 1; i <= 30; i++)
    {
        for(long long j = 1; j <= 30; j++)
        {
            if(mat[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
}

long long bfs2()
{ 
    while(!q.empty())
    {
        auto [u, k] = q.front();
        
        for(auto &v : adj[u])
        {
            if(v == 30) return k;
            if(d2[v] == 0)
            {
                q.push({v, k + 1});
                d2[v] = 1;
            }
        }
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    memset(a, '#', sizeof(a));
    memset(d, 0, sizeof(d));
    
    cin >> m >> n >> t;
    for(long long i = 1; i <= m; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    q.push({1, 1});
    d[1][1] = 1;
    bfs1();
    
    adj_conv();
    
    
    while(t--)
    {
        while(!q.empty()) q.pop();
        memset(d2, 0, sizeof(d2));
        
        cin >> mx >> my;
        if(a[mx][my] == '*') 
        {
            cout << 0 << endl;
            continue;
        }
        q.push({a[mx][my] - 'A' + 1, 1});
        d2[a[mx][my] - 'A' + 1] = 1;
        cout << bfs2() << endl;
    }
}