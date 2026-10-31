#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, q; cin >> n;
    unordered_map<long long, long long>mp;
    long long x; 
    for(long long i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    cin >> q;
    while(q--)
    {
        cin >> x;
        cout << mp[x] << "\n";
    }

}

