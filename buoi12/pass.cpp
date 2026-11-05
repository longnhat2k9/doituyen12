#include<bits/stdc++.h>
using namespace std;

long long d[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};

long long mxlen = 0;

void cs()
{
	string s;
	cin >> s;
	long long n = s.size();
	vector<long long>a(n, 0);
	for(long long i = 0; i < n; i++)
	{
		long long k = s[i] - '0';
		a[i] = d[k];
	}

	long long mx = a[0];
	for(long long i = 1; i < n; i++)
	{
		if(a[i] == 1) 
		{
			a[i] += a[i - 1];
			mx = max(a[i], mx);
		}
	}

	mxlen = max(mx, mxlen);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n; cin >> n;
	while(n--) cs();

	cout << mxlen;
}