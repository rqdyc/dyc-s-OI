#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
const ll M = 2e5 + 10;
struct edge
{
    ll x, y;
    ll next;
    ll c;
} e[M << 1];
ll tot = 0;
ll elast[N];
void add(ll x, ll y, ll c)
{
    tot++;
    e[tot].x = x;
    e[tot].y = y;
    e[tot].c = c;
    e[tot].next = elast[x];
    elast[x] = tot;
}
struct node
{
    ll x, dis;
    ll c;
    node(ll x = 0, ll dis = 0, ll c = 0) : x(x), dis(dis), c(c) {}
};
ll dis[N];
ll n, m;
void dijkstra(ll st)
{
    dis[st] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        add(x, y, c);
        add(y, x, c);
    }
    dijkstra(1);
    if (dis[n] == 1e17)
    {
        continue;
    }
}