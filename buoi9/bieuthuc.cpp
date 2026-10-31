#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, k; cin >> n >> k; k;
	long long s = 0;
	vector<long long>a(n - 1); cin >> s;
	for(auto &x : a) cin >> x;
	sort(a.begin(), a.end(), greater<long long>());
	
	for(long long i = 0; i < n; i++)
	{
		if(i < k) s += a[i];
		else s -= a[i];
	}

	cout << s;
}