#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long m, n; cin >> m >> n;
	vector<pair<long long, long long>>a(n);
	for(auto &x : a)
	{
		cin >> x.first >> x.second;
	}

	reverse(a.begin(), a.end());
	set<pair<long long, long long>>st;

	long long cnt = 0;
	bool ck;
	for(auto &x : a)
	{
		auto b = st.lower_bound({x.first, 1e18});
		
		if(b != st.end() && max(x.first, b -> first) <= min(x.second, b -> second))
		{
			long long m = min(b -> first, x.first);
			long long n = max(b -> second, x.second);
			st.erase(b);
			st.insert({m, n});
			continue;
		}

		if(b != st.begin()) b--;

		if(b != st.end() && max(x.first, b -> first) <= min(x.second, b -> second))
		{
			long long m = min(b -> first, x.first);
			long long n = max(b -> second, x.second);
			st.erase(b);
			st.insert({m, n});
			continue;
		}

		cnt++;

		st.insert(x);
	}

	cout << cnt;
}
