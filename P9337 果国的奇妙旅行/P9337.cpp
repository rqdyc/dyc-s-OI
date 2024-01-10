#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 3e5 + 10;
const ll M = 3e5 + 10;
struct edge
{
    ll x, y;
    ll next;
} e[M << 1];
ll elast[N];
ll tot = 0;
void add(ll x, ll y)
{
    tot++;
    e[tot].x = x;
    e[tot].y = y;
    e[tot].next = elast[x];
    elast[x] = tot;
}
struct node
{
    ll x;
    long double dis;
    node(ll x = 0, long double dis = 0) : x(x), dis(dis) {}
};
struct cmp
{
    bool operator()(node a, node b)
    {
        return a.dis > b.dis;
    }
};
ll d[N];
long double dis[N];
bool vis[N];
ll n, m;
long double r[N];
long double sum[N];
void dijkstra(ll st)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e17;
        vis[i] = 0;
        sum[i] = 0;
        r[i] = (long double)(d[i]);
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
            ll y = e[i].y;
            sum[y] += dis[x];
            r[y] = r[y] - 1;
        }
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            long double dd = sum[y], rr = r[y];
            // cout << endl;
            dd /= d[y];
            rr /= d[y];
            // cout << r << endl;
            rr = 1 - rr;
            dd = dd + 1;
            // cout << y << ":" << d[y] << " " << dd << " " << r << " ";
            dd /= rr;
            // cout << dd << endl;
            if (dis[y] > dd)
            {
                dis[y] = dd;
                q.push(node(y, dis[y]));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
        d[x]++;
        d[y]++;
    }
    dijkstra(n);
    cout << dis[1] << endl;
}