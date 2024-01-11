#include <bits/stdc++.h>
using namespace std;
#define lll __int128_t
const lll P = 998244353;
int n;
lll rn;
lll ans = 1;
lll inv24 = 291154603;
long long rans = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rn = n;
    ans = ans * ((rn + 1) * (rn + 2)) % P;
    ans %= P;
    ans = ans * ((rn + 3) * (rn + 4)) % P;
    ans %= P;
    ans = ans * inv24;
    ans %= P;
    rans = ans;
    printf("%lld", (rans + P) % P);
}