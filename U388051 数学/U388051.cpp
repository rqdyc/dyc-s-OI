#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll P = 998244353;
ll n;
ll ans = 0;
ll wes = 0;
ll la = 1;
ll st = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (st <= n)
    {
        ll rtt=1;
        
        ans += max(0ll, (min(n, la) - st + 1) % P * rtt) % P;
        // cout << st << " " << la << " " << wes << " " << max(0ll, (min(n, la) - st + 1) % P * wes * (wes + 1) / 2) % P << endl;
        st <<= 1;
        la = (unsigned ll)((unsigned ll)(st << 1) - 1);
        wes++;
        ans %= P;
    }
    cout << ans << endl;
    return 0;
}