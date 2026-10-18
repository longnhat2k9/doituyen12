#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, double> x, pair<long long, double> y)
{
	return x.first > y.first;
}

int main()
{
	long long l, n; cin >> l >> n;
	pair<long long, double> a[n];
	for(long long i = 0; i < n; i++) 
	{
		cin >> a[i].first >> a[i].second;
		a[i].second = a[i].first + l / a[i].second;
	}

	sort(a, a + n, cmp);

	vector<double>lis;

	for(long long i = 0; i < n; i++)
	{
		auto it = lower_bound(lis.begin(), lis.end(), a[i].second);
		if(it == lis.end())
		{
			lis.push_back(a[i].second);
		}
		else
		{
			*it = a[i].second;
		}
	}

	cout << lis.size();
}