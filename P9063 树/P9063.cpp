#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 3010;
ll n;
ll sons[N];
ll dp[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        sons[x]++;
    }
    for (ll i = 0; i <= n; i++)
    {
        dp[i] = 1e17;
    }
    dp[1] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = n; j - sons[i] >= 1; j--)
        {
            dp[j] = min(dp[j], dp[j - sons[i]] + 1);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (dp[i] == 1e17)
        {
            dp[i] = -1;
        }
        cout << dp[i] << " ";
    }
    return 0;
}