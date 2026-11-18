#include<bits/stdc++.h>
using namespace std;

#define fi first.first
#define se first.second
#define th second

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<pair<pair<long long, long long>, long long>>a(n);
    for(auto &x : a)
    {
        cin >> x.fi >> x.se >> x.th;
    }

    sort(a.begin(), a.end());

    vector<pair<pair<long long, long long>, long long>>b;
    for(auto &x : a)
    {
        if(!b.empty() && b.rbegin() -> first == x.first)
        {
            b.rbegin() -> th += x.th;
            continue;
        }
        b.push_back(x);
    }

    n = b.size();
    long long ans = 0, mx = 0;
    vector<long long>dp(n, 0);

    for(long long i = 0; i < n; i++)
    {
        mx = 0;
        for(long long j = 0; j < i; j++)
        {
            if(b[j].se <= b[i].se)
            {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + b[i].th;
        ans = max(dp[i], ans);
    }

    cout << ans;
}