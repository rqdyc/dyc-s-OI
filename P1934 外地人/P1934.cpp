#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll tot = 0;
unordered_map<string, string> m1;
map<string, ll> m2;
string ask, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> ask >> ans;
		m1[ans] = ask;
		m2[ans] = ++tot;
	}
	for (ll i = 1; i <= m; i++)
	{
		cin >> ask;
		if (m2[ask])
		{
			cout << m1[ask] << "\n";
		}
		else
		{
			cout << "eh\n";
		}
	}
}
