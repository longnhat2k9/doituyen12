#include<bits/stdc++.h>
using namespace std;

const long long M = 2e6 + 9;
vector<long long>a(M + 1, 1);

void sang()
{
	for(long long i = 2; i <= sqrt(M); i++)
	{
		if(a[i] == 1) for(long long j = i * i; j <= M; j += i)
		{
			a[j] = 0;
		}
	}
	a[M] = M;
	for(long long i = M - 1; i > 0; i--)
	{
		if(a[i] == 1)
		{
			a[i] = i;
		}
		else
		{
			a[i] = a[i + 1];
		}
	}
}

void cs()
{
	long long k; cin >> k;
	long long x, y;
	x = a[k + 1];
	y = a[x + k];
	cout << x * y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	sang();
	long long t; cin >> t;
	while(t--) cs();
}
