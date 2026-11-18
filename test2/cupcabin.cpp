#include<bits/stdc++.h>
using namespace std;

long long n, k, ans = 0;

bool ck(long long m, vector<long long>a)
{
    sort(a.begin(), a.begin() + m, greater<long long>());
    long long sum = 0;
    for(long long i = 0; i < m; i += 2)
    {
        sum += a[i];
    }
    return k >= sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    vector<long long>a(n);
    for(auto &x : a) cin >> x;

    long long l = 1, r = n, m;
    while(l <= r)
    {
        m = (l + r) / 2;
        if(ck(m, a) == true)
        {
            l = m + 1;
            ans = m;
            continue;
        }
        r = m - 1;
    }
    cout << ans;
}