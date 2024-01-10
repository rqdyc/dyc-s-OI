#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 3010;
const ll M = 7e4 + 10;
ll Point[N];
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
struct node
{
    ll st;
    ll x;
    ll dis;
    node(ll x = 0, ll dis = 0, ll st = 0) : x(x), dis(dis), st(st) {}
};
struct cmp
{
    bool operator()(node a, node b)
    {
        return a.dis > b.dis;
    }
};
ll n, m;
ll sum[N];
vector<ll> l[N];
ll dis[N];
ll rdis[N];
bool vis[N];
void dijkstra(ll st)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e17;
    }
    dis[st] = rdis[st] = 0;
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
            if (dis[y] > max(rdis[x], dis[x]) + e[i].z)
            {
                dis[y] = max(rdis[x], dis[x]) + e[i].z;
                if (!sum[y])
                {
                    // cout << y << " " << dis[y] << endl;
                    q.push(node(y, dis[y]));
                }
            }
        }
        for (ll i = 0; i < l[x].size(); i++)
        {
            sum[l[x][i]]--;
            rdis[l[x][i]] = max(rdis[l[x][i]], max(rdis[x], dis[x]));
            if (!sum[l[x][i]])
            {
                q.push(node(l[x][i], max(dis[l[x][i]], rdis[l[x][i]])));
            }
        }
    }
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
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> sum[i];
        for (ll j = 1; j <= sum[i]; j++)
        {
            cin >> x;
            l[x].push_back(i);
        }
    }
    dijkstra(1);
    cout << max(rdis[n], dis[n]) << endl;
}