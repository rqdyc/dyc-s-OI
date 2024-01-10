#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1.5e3 + 10;
const ll M = 5e3 + 10;
const ll P = 1e9 + 7;
struct edge
{
    ll x, y, z;
    ll next;
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
ll sum[N];
bool vis[N];
ll dis[N];
ll rans[M];
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
bool vis2[N];
void dfs(ll x)
{
    if (vis2[x])
    {
        return;
    }
    for (ll i = elast[x]; i; i = e[i].next)
    {
        ll y = e[i].y;
        if (dis[y] == dis[x] + e[i].z)
        {
            dfs(y);
            rans[i] += ans[x] * sum[y];
            sum[x] += sum[y];
            sum[x] %= P;
            rans[i] %= P;
        }
    }
    sum[x]++;
    vis2[x] = 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    memset(vis, 0, sizeof(vis));
    for (ll i = 1; i <= n; i++)
    {
        dijkstra(i);
        memset(vis2, 0, sizeof(vis2));
        memset(vis, 0, sizeof(vis));
        memset(sum, 0, sizeof(sum));
        dfs(i);
    }
    for (ll i = 1; i <= m; i++)
    {
        cout << (rans[i] + P) % P << endl;
    }
}