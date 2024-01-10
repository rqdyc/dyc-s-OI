#pragma GCC optimze(3)
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N 110
ll T;
ll n;
struct point
{
    ll x, y, z;
};
struct hole
{
    point in;
    point out;
    ll t, d;
};
ll getans(point x, point y)
{
    return ceil(sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2) + pow(x.z - y.z, 2)));
}
hole l[N];
point xx, yy;
ll dis[N];
ll pre[N];
bitset<N> vis, vis2;
ll Map[N][N];
ll tottt = 0;
void spfa(ll st)
{
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
        pre[i] = 0;
    }
    vis.set();
    vis[0] = 1;
    dis[st] = 0;
    bool flag = 1;
    for (ll ii = 1; ii <= n; ii++)
    {
        flag = 0;
        for (ll x = 1; x <= n; x++)
        {
            for (ll y = 1; y <= n; y++)
            {
                if (dis[y] > max(dis[x] + Map[x][y], l[y].t) + l[y].d)
                {
                    flag = 1;
                    dis[y] = max(dis[x] + Map[x][y], l[y].t) + l[y].d;
                    pre[y] = x;
                }
            }
        }
        if (!flag)
        {
            break;
        }
        for (ll i = 1; i <= n; i++)
        {
            ll x = i, spend = 1e9;
            vis2.set();
            while (!vis[x])
            {
                vis[x] = 1;
                vis2[x] = 1;
                x = pre[x];
            }
            if (!vis2[x])
            {
                continue;
            }
            tottt++;
            while (vis2[x])
            {
                spend = min(spend, -l[x].t + dis[pre[x]] + Map[pre[x]][x]);
                vis2[x] = 0;
                x = pre[x];
            }
            if (spend <= 0)
            {
                continue;
            }
            while (!vis2[x])
            {
                dis[x] -= spend;
                vis2[x] = 1;
                x = pre[x];
            }
        }
    }
}
int main()
{
    // freopen("Testdata009.in", "r", stdin);
    // freopen("ans.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> l[i].in.x >> l[i].in.y >> l[i].in.z >> l[i].out.x >> l[i].out.y >> l[i].out.z >> l[i].t >> l[i].d;
        }
        cin >> xx.x >> xx.y >> xx.z >> yy.x >> yy.y >> yy.z;
        l[n + 1].t = l[n + 2].t = -1e9;
        l[n + 1].in = l[n + 1].out = xx;
        l[n + 2].in = l[n + 2].out = yy;
        l[n + 1].d = l[n + 2].d = 0;
        n += 2;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                Map[i][j] = getans(l[i].out, l[j].in);
            }
        }
        spfa(n - 1);
        cout << dis[n] << "\n";
        // cout << T << " " << clock() << endl;
    }
    // cout << clock() << " " << tottt << endl;
    return 0;
}