#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 55;
ll n, c;
ll wes[N], w[N];
ll dp[N][N][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
        {
            dp[i][j][0] = dp[i][j][1] = 1145141919810;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> wes[i] >> w[i];
        w[i] = w[i - 1] + w[i];
    }
    dp[c][c][1] = dp[c][c][0] = 0;
    for (ll k = 2; k <= n; k++)
    {
        for (ll i = 1; i <= n - k + 1; i++)
        {
            ll j = i + k - 1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (wes[i + 1] - wes[i]) * (w[i] + w[n] - w[j]), dp[i + 1][j][1] + (wes[j] - wes[i]) * (w[i] + w[n] - w[j]));
            dp[i][j][1] = min(dp[i][j - 1][0] + (wes[j] - wes[i]) * (w[i - 1] + w[n] - w[j - 1]), dp[i][j - 1][1] + (wes[j] - wes[j - 1]) * (w[i - 1] + w[n] - w[j - 1]));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << endl;
    return 0;
}
