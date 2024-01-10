#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
const ll M = 2e5 + 10;
const ll P = 1e9 + 7;
struct edge
{
    ll x, y, z;
    ll next;
    edge(ll x = 0, ll y = 0, ll z = 0, ll next = 0) : x(x), y(y), z(z), next(next) {}
} e[M << 1];
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
ll n, m;
ll a, b;
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
ll ans[N];
bool vis[N];
ll dis[N];
void dijkstra(ll u)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e17;
        ans[i] = 0;
    }
    dis[u] = 0;
    ans[u] = 1;
    q.push(node(u, dis[u]));
    while (!q.empty())
    {
        ll x = q.top().x;
        q.pop();
        if (vis[x])
        {
            continue;
        }
        vis[x] = 1;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            if (dis[y] == dis[x] + e[i].z)
            {
                ans[y] += ans[x];
            }
            if (dis[y] > dis[x] + e[i].z)
            {
                dis[y] = dis[x] + e[i].z;
                ans[y] = ans[x];
                q.push(node(y, dis[y]));
            }
        }
    }
}
ll dis2[N];
ll ans2[N];
void dijkstra2(ll u)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis2[i] = 1e17;
        ans2[i] = 0;
    }
    dis2[u] = 0;
    ans2[u] = 1;
    q.push(node(u, dis2[u]));
    while (!q.empty())
    {
        ll x = q.top().x;
        q.pop();
        if (vis[x])
        {
            continue;
        }
        vis[x] = 1;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            if (dis2[y] == dis2[x] + e[i].z)
            {
                ans2[y] += ans2[x];
            }
            if (dis2[y] > dis2[x] + e[i].z)
            {
                dis2[y] = dis2[x] + e[i].z;
                ans2[y] = ans2[x];
                q.push(node(y, dis2[y]));
            }
        }
    }
}
ll rans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> a >> b;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dijkstra(a);
    rans = (ans[b] * ans[b] + P) % P;
    dijkstra2(b);
    for (ll i = 1; i <= n; i++)
    {
        if (dis[i] == dis2[i] && dis[i] + dis2[i] == dis[b])
        {
            rans -= (ans[i] * ans2[i]) * (ans[i] * ans2[i]);
            rans = (rans + P) % P;
        }
    }
    for (ll i = 1; i <= tot; i++)
    {
        ll x = e[i].x, y = e[i].y, z = e[i].z;
        if (x > y)
        {
            continue;
        }
        if (dis[x] + dis2[y] + e[i].z == dis[b] && (dis[x] < e[i].z + dis2[y] || dis2[y] < e[i].z + dis[x]))
        {
            rans -= (ans[x] * ans2[y]) * (ans[x] * ans2[y]);
        }
        else if (dis[y] + dis2[x] + e[i].z == dis[b] && (dis[y] < e[i].z + dis2[x] || dis2[x] < e[i].z + dis[y]))
        {
            rans -= (ans[y] * ans2[x]) * (ans[y] * ans2[x]);
        }
        rans = (rans + P) % P;
    }
    cout << (rans + P) % P << endl;
}