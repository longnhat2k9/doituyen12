#include<bits/stdc++.h>
using namespace std;

long long n, m;
const long long M = 1e6 + 9, MM = 1e3;
long long a[M], b[M];
long long d[MM][MM];
vector<long long>ans;

void lcs()
{
	memset(d, 0, sizeof(d));
	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= m; j++)
		{
			if(a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	cout << d[n][m];
}

void s2()
{
	long long cnt = 0;
	long long i = 1, j = 1;
	while(i <= n && j <= m)
	{
		if(a[i] == b[j]) 
		{
			cnt++;
			i++; j++;
		}
		else
		{
			if(a[i] > b[j]) j++;
			else i++;
		}

	}
	cout << cnt;
}

void lis()
{
	long long sz;
	unordered_map<long long, vector<long long>>mp;
	for(long long i = 1; i <= n; i++)
	{
		mp[a[i]].push_back(i);
	}

	vector<long long>p;
	for(long long i = 1; i <= m; i++)
	{
		auto it = mp.find(b[i]);
		if(it == mp.end())continue;
		vector<long long>&s = it -> second;
		sz = s.size();
		if(sz > 0)
		{
			for(long long j = sz - 1; j >= 0; j--)
			{
				p.push_back(s[j]);
			}
		}
	}

	vector<long long>lis;

	for(auto &x : p)
	{
		auto it = lower_bound(lis.begin(), lis.end(), x);
		if(it == lis.end()) lis.push_back(x);
		else *it = x;
	}

	cout << lis.size();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
 	for(long long i = 1; i <= n; i++) cin >> a[i];
	for(long long j = 1; j <= m; j++) cin >> b[j];

	if(is_sorted(a + 1, a + n + 1) == 1 && is_sorted(b + 1, b + m + 1) == 1) s2();
	else if(m > 1e3) lis();
	else lcs();
}
