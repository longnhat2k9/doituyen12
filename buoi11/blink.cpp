#include<bits/stdc++.h>
using namespace std;

long long n, b;

map<vector<long long>, long long>mp;

void swap(vector<long long>&a)
{
    vector<long long> org = a;
    if(org[n - 1] == 1)
    {
        a[0]++;
        if(a[0] == 2) a[0] = 0;
    }
    
    for(long long i = 1; i < n; i++)
    {
        if(org[i - 1] == 1)
        {
            a[i]++;
            if(a[i] == 2) a[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> b;
    vector<long long>a(n, 0);
    for(auto &x : a) cin >> x;
    
    mp[a] = 0;
    long long t = 1;
    swap(a); mp[a] = t;
    long long r;
    
    while(t < b)
    {
        t++;
        swap(a);
        if(mp[a] != 0) 
        {
            r = mp[a];
            break;
        }
        mp[a] = t;
    }

    if(t == b)
    {
        for(auto & k : a) cout << k << "\n";
        return 0;
    }

    t -= r;
    
    long long x = (b - r) % t + r;
    for(auto &c : mp)
    {
        if(c.second == x)
        {
            a = c.first;
            break;
        }
    }
    
    for(auto & k : a) cout << k << "\n";
}