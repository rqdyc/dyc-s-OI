#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
const ll M = 2e5 + 10;
const ll K = 55;
struct edge
{
    ll x, y, z;
    ll next;
} e[M], f[M];
ll elast[N];
ll tot = 0;
void add(ll x, ll y, ll z)
{
    tot++;
    e[tot].x = x;
    e[tot].y = y;
    e[tot].z = z;
    e[tot].next = elast[x];
    elast[x] = tot;
}
ll flast[N];
ll tot2 = 0;
void add2(ll x, ll y, ll z)
{
    tot2++;
    f[tot2].x = x;
    f[tot2].y = y;
    f[tot2].z = z;
    f[tot2].next = flast[x];
    flast[x] = tot2;
}
struct node
{
    ll x;
    ll dis;
    node(ll x = 0, ll dis = 0) : x(x), dis(dis) {}
};
struct cmp
{
    bool operator()(node a, node b)
    {
        return a.dis > b.dis;
    }
};
ll T;
ll n, m, k, p;
ll dis[N];
bool vis2[N];
bool vis[N][K];
ll ans[N][K];
priority_queue<node, vector<node>, cmp> q;
void dijkstra(ll st)
{
    while (!q.empty())
    {
        q.pop();
    }
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e17;
    }
    dis[st] = 0;
    q.push(node(st, dis[st]));
    while (!q.empty())
    {
        ll x = q.top().x;
        q.pop();
        if (vis2[x])
        {
            continue;
        }
        vis2[x] = 1;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            if (dis[y] > dis[x] + e[i].z)
            {
                dis[y] = dis[x] + e[i].z;
                q.push(node(y, dis[y]));
            }
        }
    }
}
bool flag = 0;
ll dijkstra2(ll st, ll ksum)
{
    if (ksum < 0)
    {
        return 0;
    }
    if (vis[st][ksum] == 1)
    {
        flag = 1;
        return 0;
    }
    if (ans[st][ksum] != -1)
    {
        return ans[st][ksum];
    }
    ll anss = 0;
    vis[st][ksum] = 1;
    for (ll i = flast[st]; i; i = f[i].next)
    {
        // cout << st << "->" << f[i].y << endl;
        anss += dijkstra2(f[i].y, ksum + dis[st] - dis[f[i].y] - f[i].z);
        anss %= p;
        if (flag)
        {
            return 0;
        }
    }
    if (st == n && ksum == 0)
    {
        anss++;
    }
    ans[st][ksum] = anss % p;
    vis[st][ksum] = 0;
    return ans[st][ksum];
}
int main()
{
    // freopen("P3953_6.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        flag = 0;
        tot = 0;
        tot2 = 0;
        cin >> n >> m >> k >> p;
        for (ll i = 1; i <= n; i++)
        {
            elast[i] = flast[i] = 0;
            for (ll kk = 0; kk <= k; kk++)
            {
                ans[i][kk] = -1;
            }
        }
        for (ll i = 1; i <= m; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            add(y, x, z);
            add2(x, y, z);
        }
        memset(vis2, 0, sizeof(vis2));
        dijkstra(n);
        ll rans = 0;
        for (ll i = 0; i <= k; i++)
        {
            memset(vis, 0, sizeof(vis));
            rans += dijkstra2(1, i);
            rans %= p;
        }
        if (flag)
        {
            cout << -1 << endl;
            continue;
        }
        cout << rans << endl;
    }
}