#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long>x, pair<long long, long long> y)
{
	return x.first < y.first;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long l, n;
	pair<long long, float>a[n];
	for(auto &x : a) 
	{
		cin >> x.first >> x.second;
		x.second  =  float(l) / x.second + float(x.first); 
	}

	sort(a, a + n, cmp);

	
}