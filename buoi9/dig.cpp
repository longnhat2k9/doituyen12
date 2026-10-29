#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long t; cin >> t;
	long long a, b;
	while(t--)
	{
		cin >> a >> b;
		__int128 s = (a + b);
		__int128 s2 = (b - a + 1);
		s = s * s2 / 2;
		s = s % 9;
		a = s;
		if(a == 0) a = 9;
		cout << a << "\n";
	}
}