#include<bits/stdc++.h>
using namespace std;

const long long Mx = 1e5 + 7;
long long n, m; 
vector<long long>adj[Mx];
queue<long long>q;
long long d[Mx];

bool bfs()
{
    long long u;
    while(!q.empty())
    {
        u = q.front();
        
        for(auto &v : adj[u])
        {
            if(d[v] == 0)
            {
                d[v] = u;
                q.push(v);
            }

            if(v == n) return true;
        }

        q.pop();
    }

    return false;
}

void trace()
{
    vector<long long>ans;
    while(n != -1)
    {
        ans.push_back(n);
        n = d[n];
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(long long i = 0; i < m; i++)
    {
        long long u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    q.push(1);
    d[1] = -1;
    bool ck = bfs();
    if(ck == false)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    trace();
}