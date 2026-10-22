#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long>x, pair<long long, long long> y)
{
	return x.first < y.first;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, k;
	cin >> n >> k;
	pair<long long, long long> a[n];
	for(long long i = 0; i < n; i++) 
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	sort(a, a + n, cmp);

	long long h[n + 1];
	h[0] = h[a[0].second] = 0;
	for(long long i = 1; i < n; i++)
	{
		if(a[i].first == a[i - 1].first) h[a[i].second] = h[a[i - 1].second];
		else h[a[i].second] = i;
	}

	for(long long i = 1; i <= n; i++)
	{
		h[i] += h[i - 1];
	}

	long long mx = 0, st, sz;

	for(long long i = 0; i <= n - k; i++)
	{
		sz = h[i + k] - h[i];
		if(sz > mx) 
		{
			mx = sz;
			st = i + 1;
		}
	}

	cout << st;
}