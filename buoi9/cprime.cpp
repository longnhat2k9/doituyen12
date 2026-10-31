#include<bits/stdc++.h>
using namespace std;

long long Mx = 5 * 1e6;
vector<long long>a(Mx + 1, 1);

void sang()
{
	a[0] = a[1] = 0;
	for(long long i = 2; i <= sqrt(Mx); i++)
	{
		if(a[i] == 1)
		{
			for(long long j = i * i; j <= Mx; j += i)
			{
				a[j] = 0;
			}
		}
	}

	for(long long i = 2; i <= Mx; i++) a[i] += a[i - 1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	sang();

	long long t, x, y; cin >> t;
	while(t--)
	{
		cin >> x >> y;
		cout << a[y] - a[x - 1] << "\n";
	}
}