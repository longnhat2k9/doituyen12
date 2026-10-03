#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

long long m, n;
long long sx, sy, tx, ty;
char a[1020][1020];
long long d[1020][1020];
queue<pair<long long, long long>>q;
long long dx[5] = {0, 1, 0, -1, 0};
long long dy[5] = {0, 0, -1, 0, 1};
char dir[5] = {'.', 'S', 'W', 'N', 'E'};
vector<char>ans;

void setup()
{
    memset(a, '+', sizeof(a));
    memset(d, 0, sizeof(d));
}

void bfs()
{
    while(!q.empty())
    {
        auto [fx, fy] = q.front();
        
        for(long long k = 1; k <= 4; k++)
        {
            auto x = fx + dx[k];
            auto y = fy + dy[k];
            
            if(a[x][y] == '.' &&
                d[x][y] == 0)
            {
                d[x][y] = k;
                q.push({x, y});
            }
            
            if(a[x][y] == '+')
            {
                tx = fx;
                ty = fy;
                return;
            }
        }
        
        q.pop();
    }
}

void recall()
{
    long long x = tx, y = ty, k = d[x][y];
    while(x != sx || y != sy)
    {
        // ans.push_back({x, y});
        ans.push_back(dir[k]);
        x -= dx[k];
        y -= dy[k];
        k = d[x][y];
    }
}

int main()
{
    cin >> m >> n;
    
    setup();
    for(long long i = 1; i <= m; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == '*')
            {
                sx = i;
                sy = j;
                d[i][j] = -1;
            }
        }
    }
    
    q.push({sx, sy});
    bfs();
    recall();
    // ans.push_back({sx, sy});
    reverse(ans.begin(), ans.end());
    
    /*
    for(auto &[x, y] : ans)
    {
        cout << x << " " << y << endl;
    }
    */
    
    for(auto &x : ans) cout << x;
    
    return 0;
}