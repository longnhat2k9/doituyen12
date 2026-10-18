#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long m, n; cin >> m >> n;

	vector<long long>a, b;
	long long u, v, x, y;
	for(long long i = 0; i < n; i++)
	{
		cin >> u >> v;
		auto it2 = lower_bound(b.begin(), b.end(), u); 
		auto it = upper_bound(a.begin(), a.end(), v); 

		if(it2 == b.end())
		{
			a.push_back(u);
			b.push_back(v);
		}
		else if(it == a.end())
		{
			x = it2 - b.begin();
			y = it - a.begin();
			a.erase(a.begin() + x, a.end());
			b.erase(b.begin() + x, b.end());
			a.push_back(u);
			b.push_back(v);
		}
		else 
		{
			x = it2 - b.begin();
			y = it - a.begin();
			a.erase(a.begin() + x, a.begin() + y);
			b.erase(b.begin() + x, b.begin() + y);
			a.push_back(u);
			b.push_back(v);
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
		}
	}

	cout << a.size();
}
