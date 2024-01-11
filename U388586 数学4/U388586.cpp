#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll P = 998244353;
ll n;
ll ans = 0;
int main()
{
    cin >> n;
    for (register ll l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += (r - l + 1) % P * (n / l);
        ans %= P;
    }
    cout << (ans + P) % P << endl;
}