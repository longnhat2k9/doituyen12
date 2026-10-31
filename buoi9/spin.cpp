#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long M, K, n, T;
	cin >> M >> K >> n >> T;
	vector<long long>b(n);
	for(auto &x : b) cin >> x;

	long long t = K;
	long long a = (K * (K + 1)) / 2;
	sort(b.begin(), b.end());
	for(auto &x : b) 
	{
		if(x <= t) 
		{
			t++;
			a -= x;
			a += t;
		}
		else break;		
	}

	if(t > M) 
	{
		cout << -1;
		return 0;
	}


	cout << T * K + a;
}