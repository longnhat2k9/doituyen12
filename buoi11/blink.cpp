#include<bits/stdc++.h>
using namespace std;

long long n, b;

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
    vector<long long>org = a;
    
    long long t = 1;
    swap(a);
    
    while(a != org && t < b)
    {
        t++;
        swap(a);
    }
    
    long long x = b % t;
    while(x--)
    {
        swap(a);
    }
    
    for(auto & k : a) cout << k << "\n";
}