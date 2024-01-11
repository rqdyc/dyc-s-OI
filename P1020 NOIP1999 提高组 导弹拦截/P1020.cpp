#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
ll n;
ll a[N];
ll dp[N];
ll c[N];
ll s[N];
ll lowbit(ll x)
{
    return x & (-x);
}
void modify(ll x, ll sum)
{
    x = N - x;
    for (ll i = x; i < N; i += lowbit(i))
        c[i] = max(c[i], sum);
}
ll getsum(ll x)
{
    x = N - x;
    ll ans = -1;
    for (ll i = x; i >= 1; i -= lowbit(i))
    {
        ans = max(ans, c[i]);
    }
    return ans;
}
ll ans1, ans2;
struct node
{
    ll val, id;
};
node rtt[N];
bool cmp1(node a, node b)
{
    return a.val < b.val;
}
bool cmp2(node a, node b)
{
    return a.id < b.id;
}
map<ll, ll> m;
void rt()
{
    for (ll i = 1; i <= n; i++)
    {
        rtt[i].val = rtt[i].id = 0;
        rtt[i].val = a[i];
        rtt[i].id = i;
    }
    sort(rtt + 1, rtt + n + 1, cmp1);
    ll tot = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!m[rtt[i].val])
        {
            m[rtt[i].val] = ++tot;
        }
        rtt[i].val = m[rtt[i].val];
    }
    sort(rtt + 1, rtt + n + 1, cmp2);
    for (ll i = 1; i <= n; i++)
    {
        a[i] = rtt[i].val;
    }
}
int main()
{
    n = 1;
    while (scanf("%lld", &a[n]) != EOF)
    {
        n++;
    }
    n--;
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = 1;
        ll l = 0, r = ans2 + 1;
        while (r - l > 1)
        {
            ll mid = (l + r) >> 1;
            if (s[mid] < a[i])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        dp[i] = l + 1;
        s[dp[i]] = a[i];
        ans2 = max(ans2, dp[i]);
    }
    rt();
    memset(dp, 0, sizeof(dp));
    ans1 = dp[1] = 1;
    modify(a[1], 1);
    for (ll i = 2; i <= n; i++)
    {
        dp[i] = getsum(a[i]) + 1;
        modify(a[i], dp[i]);
        ans1 = max(ans1, dp[i]);
    }
    printf("%lld\n%lld\n", ans1, ans2);
    return 0;
}