#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n; cin >> n;
	vector<long long>a(n), b;
	for(auto &x : a) cin >> x;
	b = a;
	reverse(b.begin(), b.end());
	long long dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= n; j++)
		{
			if(a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} 
			else 
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << n - dp[n][n];
}