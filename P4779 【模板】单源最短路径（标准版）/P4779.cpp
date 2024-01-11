#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
const ll M = 2e5 + 10;
struct edge
{
    ll x, y, z;
    ll next;
} e[M];
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
ll n, m;
ll dis[N];
bool vis[N];
void dijkstra(ll st)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        vis[i] = 0;
        dis[i] = 1e17;
    }
    dis[st] = 0;
    q.push(node(st, dis[st]));
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
            ll y=e[i].y;
            if(dis[y]>dis[x]+e[i].z){
                dis[y]=dis[x]+e[i].z;
                q.push(node(y,dis[y]));
            }
        }
    }
}
ll s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    dijkstra(s);
    for (ll i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}