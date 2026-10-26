#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n; cin >> n;
	long long a[n + 1]; a[0] = 0;
	long long cnt = 0;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}

	unordered_map<long long, long long>mp;
	for(long long i = 1; i <= n; i++)
	{
		mp[a[i]]++;
	}

	for(auto &x : mp)
	{
		long long m = x.second;
		cnt += m * (m - 1) / 2;
		if(x.first == 0) cnt+= m;
	}

	cout << cnt;
}
