#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;

	long long i = 0, j = 0, n = s.size();

	unordered_map<long long, long long>mp;
	long long l = 0, v = 0;

	while(i < n && j < n)
	{
		if('a' <= s[j] && s[j] <= 'z')
		{
			s[j] = toupper(s[j]);
		}
		mp[s[j]]++;
		while(mp[s[j]] > 1 && i <= j)
		{
			if(j - i > v) 
			{
				l = i; 
				v = j - i;
			}
			mp[s[i]]--;
			i++;
		}
		j++;
	}

	cout << l + 1 << " " << v;
}