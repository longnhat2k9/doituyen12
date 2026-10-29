#include<bits/stdc++.h>
using namespace std;

struct team
{
    long long idx, q, t; //index, questions, time
};

bool cmp(team &x, team &y)
{
    if(x.q == y.q) return x.t < y.t;
    return x.q > y.q;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, m; cin >> n >> m;
    vector<team>a(n, {0, 0, 0});
    for(long long i = 0; i < n; i++)
    {
        a[i].idx = i + 1;
        for(long long j = 0; j < m; j++)
        {
            long long x; cin >> x;
            if(x > 0) 
            {
                a[i].q++;
                a[i].t += x;
            }
        }
    }

    sort(a.begin(), a.end(), cmp);
    cout << a[0].idx;
}
