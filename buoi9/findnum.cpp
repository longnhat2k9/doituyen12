#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	vector<int>a;
	bool z = 0;
	long long sum = 0;
	long long t;
	for(auto &x : s)
	{
		t = x - '0';
		a.push_back(t);
		sum += t;
		if(t == 0) z = 1;
	}

	if(sum % 3 == 0 && z == 1)
	{
		sort(a.begin(), a.end(), greater<int>());
		for(auto &x : a) cout << x;
		return 0;
	}

	cout << -1;
}