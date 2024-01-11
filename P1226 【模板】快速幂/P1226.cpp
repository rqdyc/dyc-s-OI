#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll qpow(ll a_, ll n_, ll p_)
{
    ll ans_ = 1;
    a_ %= p_;
    while (n_)
    {
        if (n_ & 1)
            ans_ = ans_ * a_ % p_;
        n_ /= 2;
        a_ = a_ * a_ % p_;
    }
    return ans_;
}
ll a, b, p;
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> p;
    ans = qpow(a, b, p);
    cout << a << "^" << b << " mod " << p << "=" << ans << endl;
    return 0;
}