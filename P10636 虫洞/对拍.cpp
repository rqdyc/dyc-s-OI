#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 110;
const ll M = N * (N - 1);
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
// struct cmp
// {
//     template <class T1>
//     size_t operator()(T1 a)
//     {
//         return hash<point>()(a);
//     }
// };
struct edge
{
    ll x, y, z;
    ll last;
    ll next;
} e[M << 1];
ll elast[N];
ll rtot = 0;
void add(ll x, ll y, ll z, ll last)
{
    rtot++;
    e[rtot].x = x;
    e[rtot].y = y;
    e[rtot].z = z;
    e[rtot].last = last;
    e[rtot].next = elast[x];
    elast[x] = rtot;
}
bool operator<(point a, point b)
{
    if (a.x == b.x)
    {
        if (a.y == b.y)
        {
            return a.z < b.z;
        }
        return a.y < b.y;
    }
    return a.x < b.x;
}
map<point, ll> m;
hole l[N];
ll dis[N];
point xx, yy;
ll tot = 0;
void spfa(ll st)
{
    for (ll i = 1; i <= tot; i++)
    {
        dis[i] = 1e17;
    }
    dis[st] = 0;
    bool flag = 1;
    while (flag)
    {
        flag = 0;
        for (ll i = 1; i <= rtot; i++)
        {
            ll x = e[i].x, y = e[i].y;
            // cout << x << " " << y << " " << e[i].z << " ";
            if (dis[y] > max(dis[x], e[i].last) + e[i].z)
            {
                flag = 1;
                dis[y] = max(dis[x], e[i].last) + e[i].z;
            }
            // cout << dis[x] << " " << dis[y] << endl;
        }
    }
}
int main()
{
    freopen("Testdata000.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        m.clear();
        memset(elast, 0, sizeof(elast));
        rtot = 0;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> l[i].in.x >> l[i].in.y >> l[i].in.z >> l[i].out.x >> l[i].out.y >> l[i].out.z >> l[i].t >> l[i].d;
        }
        cin >> xx.x >> xx.y >> xx.z >> yy.x >> yy.y >> yy.z;
        tot = 1;
        m[xx] = tot;
        // cout << m[xx] << endl;
        for (ll i = 1; i <= n; i++)
        {
            tot++;
            // cout << m[l[i].in] << " ";
            m[l[i].in] = tot;
            // cout << m[l[i].in] << endl;
            tot++;
            // cout << m[l[i].out] << " ";
            m[l[i].out] = tot;
            // cout << m[l[i].out] << endl; /*  */
        }
        tot++;
        m[yy] = tot;
        // cout << m.size() << endl;
        for (auto it : m)
        {
            auto x = it.first;
            ll xid = it.second;
            // cout << x.x << " " << x.y << " " << x.z << " " << xid << endl;
            for (auto it2 : m)
            {
                auto y = it2.first;
                ll yid = it2.second;
                if (xid == yid)
                {
                    continue;
                }
                // cout << getans(x, y) << endl;
                add(xid, yid, getans(x, y), -1e17);
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            auto x = l[i].in, y = l[i].out;
            ll xid = m[x], yid = m[y];
            add(xid, yid, l[i].d, l[i].t);
        }
        spfa(1);
        cout << dis[tot] << endl;
    }
}