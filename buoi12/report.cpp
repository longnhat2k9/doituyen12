#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n; cin >> n;
	vector<long long>a(n);
	for(auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	if(a[0] < 0)
	{
		long long i = 0;
		long long s = 0;
		while(a[i] < 0)
		{
			s += a[i];
			i++;
		}
		cout << s;
		return 0;
	}
	cout << a[0];
}