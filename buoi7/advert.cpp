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
	for(auto &x : a)
	{
	    long long m = x.first, n = x.second;
		auto b = st.lower_bound({m, n});
		bool ck = false;
		if(b != st.end() && max(m, b -> first) <= min(n, b -> second))
		{
			ck = true;
		}
        auto b1 = b;
		if(b != st.begin() && ck == false) b1--;

		if(b1 != st.end() && max(m, b1 -> first) <= min(n, b1 -> second))
		{
			ck = true;
			b = b1;
		}
		
		while(b != st.end() && max(m, b -> first) <= min(n, b -> second))
		{
		    m = min(m, b -> first);
		    n = max(n, b -> second);
		    b = st.erase(b);
		    ck = true;
		}
		
		if(ck == false) cnt++;
		st.insert({m, n});
	}

	cout << cnt;
}
