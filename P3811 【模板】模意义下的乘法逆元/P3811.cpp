#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 3e6 + 10;
ll n, mod;
ll inv[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mod;
    cout << (inv[1] = 1) << endl;
    for (ll i = 2; i <= n; i++)
    {
        printf("%lld\n", (inv[i] = (mod - mod / i) * inv[mod % i] % mod));
    }
}