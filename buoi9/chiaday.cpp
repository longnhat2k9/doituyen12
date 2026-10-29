#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n; cin >> n;

	long long a[n + 1]; a[0] = 0;
	for(long long i = 1; i <= n; i++) 
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}

	long long dp[n + 1];

	long long Mx = 1e18;
	fill(dp, dp + n + 1, Mx); dp[0] = 0;

	unordered_map<long long, long long>mp;
	for(auto &x : a) mp[0] = 0;

	vector<long long>lt(31); lt[0] = 1;
		
	for(long long i = 1; i < 31; i++) lt[i] = lt[i - 1] * 2;

	for(long long i = 1; i <= n; i++)
	{
		for(auto &t : lt)
		{
			long long x = a[i] - t;
			if(x < 0) break;

			if(mp.find(x) != mp.end())
			{
				mp[a[i]] = dp[i] = min(mp[x] + 1, dp[i]);
			}
		}
	}

	// for(long long i = 0; i < n; i++) cout << dp[i] << " ";

	if(dp[n] == Mx) dp[n] = -1;
	cout << dp[n];
}