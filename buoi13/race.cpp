#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<long long>a(n);
    for(auto &x : a) cin >> x;

    vector<long long>b, c;
    b.push_back(a[0]);
    long long m = 0;
    for(long long i = 1; i < n; i++)
    {
        if(a[i] != a[m])
        {
            c.push_back(i - m);
            m = i;
            b.push_back(a[i]);
        }
    }
    c.push_back(n - m);

    vector<long long>pf(1,0);
    for(auto &x : c)
    {
        pf.push_back(*pf.rbegin() + x);
    }

    long long ans = 0;
    m = c.size();
    
    for(long long i = 0; i < m; i++)
    {
        ans += c[i] * (c[i] - 1) / 2;
    }
    
    long long p = 0;
    for(long long j = 1; j < m; j++)
    {
        ans += c[j] * (pf[j] - pf[p]);
        if(j + 1 < m && (b[j + 1] > b[j]) == (b[j] > b[j - 1])) p = j;
    }
    
    cout << ans;
}