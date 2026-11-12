#include<bits/stdc++.h>
using namespace std;

long long m, n;
char mat[1020][1020];
long long d[1020][1020];
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {-1, 0, 1, 0};
char key[4] = {'L', 'D', 'R', 'U'};
pair<long long, long long> s, t; //start & end point

void setup()
{
    memset(d, 0, sizeof(d));
    // memset(mat, '#', sizeof(mat)); // optional
}

queue<pair<long long, long long>>q;
bool bfs()
{
    long long u, v;
    while(!q.empty())
    {
        auto [i, j] = q.front();
        for(long long k = 0; k < 4; k++)
        {
            u = i + dx[k];
            v = j + dy[k];

            if((mat[u][v] == '.' || mat[u][v] == 'B') && d[u][v] == 0) 
            {
                d[u][v] = k + 1;
                q.push({u, v});
            }

            if(u == t.first && v == t.second) return true;
        }

        q.pop();
    }

    return false;
}

void trace()
{
    auto [i, j] = t;
    // vector<char> res;
    string res = "";
    long long k;    
    while(d[i][j] != -1)
    {
        k = d[i][j];
        // res.push_back(key[k - 1]);
        res += key[k - 1];
        i = i - dx[k - 1];
        j = j - dy[k - 1];
    }

    reverse(res.begin(), res.end());

    cout << res.size() << "\n";
    cout << res;
    // for(auto &x : res) cout << x;
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
            if(mat[i][j] == 'A') s = {i, j};
            if(mat[i][j] == 'B') t = {i, j};
        }
    }

    d[s.first][s.second] = -1;

    q.push(s);

    bool ck = bfs();

    if(ck == false)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES \n";
        trace();
    }
}