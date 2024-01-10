#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 310;
const ll K = 7;
bool sum[N];
ll getsum(ll i, ll j)
{
	if (i > j)
		swap(i, j);
	ll ans = 0;
	for (ll k = j, q = 0; k >= i; k--, q++)
	{
		ans += (sum[k]) * (1 << q);
	}
	return ans;
}
ll wes(unsigned ll x)
{
	return 32 - __builtin_clz(x);
}
// ����
ll n, kk;
ll dp[N][N][1 << (K + 1) | 1];
ll str[1 << (K + 1) | 1];
bool tr[(1 << (K + 1)) | 1];
int main()
{
	cin >> n >> kk;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			for (ll s = (1 << kk) - 1; s >= 0; s--)
			{
				dp[i][j][s] = -1145141919810ll; // ��ʼ��
			}
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		cin >> sum[i];
		dp[i][i][sum[i]] = 0;
	}
	for (ll i = 1; i <= (1 << kk); i++)
	{
		cin >> tr[i - 1] >> str[i - 1];
	}
	for (ll k = 2; k <= n; k++)
	{
		for (ll i = 1; i <= n - k + 1; i++)
		{
			ll j = i + k - 1;
			ll sizee = (k - 1) % (kk - 1); //
			if (sizee == 0)
			{
				sizee = kk - 1;
			}
			for (ll l = j - 1; l >= i; l -= (kk - 1))
			{
				for (ll s = (1 << (sizee)) - 1; s >= 0; s--)
				{
					dp[i][j][s << 1] = max(dp[i][j][s << 1], dp[i][l][s] + dp[l + 1][j][0]);
					dp[i][j][s << 1 | 1] = max(dp[i][j][s << 1 | 1], dp[i][l][s] + dp[l + 1][j][1]);
				}
			}
			if (sizee == kk - 1)
			{
				ll r[2];
				r[0] = r[1] = -1145141919810ll;
				for (ll s = (1 << kk) - 1; s >= 0; s--)
				{
					r[tr[s]] = max(r[tr[s]], dp[i][j][s] + str[s]);
				}
				dp[i][j][0] = r[0];
				dp[i][j][1] = r[1];
			}
		}
	}
	ll ans = -1145141919810ll;
	for (ll s = (1 << kk) - 1; s >= 0; s--)
	{
		ans = max(ans, dp[1][n][s]);
	}
	cout << ans << endl;
}
