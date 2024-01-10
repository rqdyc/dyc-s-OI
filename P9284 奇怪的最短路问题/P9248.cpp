#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
const ll M = 1e5 + 10;
ll T;
ll n, m, kk;
vector<ll> k;
struct edge
{
    ll x, y;
    ll z;
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
    ll x, dis;
    ll st;
    node(ll x = 0, ll dis = 0, ll st = 0) : x(x), dis(dis), st(st) {}
};
struct cmp
{
    bool operator()(node a, node b)
    {
        return a.dis > b.dis;
    }
};
ll Minn = 1e17;
ll dis[N];
bool vis[N];
ll vis_id[N];
void dijkstra()
{
    priority_queue<node, vector<node>, cmp> q;
    Minn = 1e17;
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e17;
        vis[i] = 0;
        vis_id[i] = 0;
    }
    for (ll i = 0; i < k.size(); i++)
    {
        dis[k[i]] = 0;
        q.push(node(k[i], 0, k[i]));
    }
    while (!q.empty())
    {
        node pt = q.top();
        q.pop();
        ll x = pt.x;
        if (vis[x])
        {
            continue;
        }
        vis[x] = 1;
        vis_id[x] = pt.st;
        // cout << x << " " << Minn << endl;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            // cout << x << "->" << y << ":" << e[i].z << endl;
            if (vis_id[y])
            {
                if (dis[y] <= dis[x] + e[i].z)
                {
                    if (pt.st != vis_id[y])
                    {
                        Minn = min(Minn, dis[y] + dis[x] + e[i].z);
                    }
                }
            }
            if (dis[y] > dis[x] + e[i].z)
            {
                dis[y] = dis[x] + e[i].z;
                q.push(node(y, dis[y], pt.st));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        memset(e, 0, sizeof(e));
        memset(elast, 0, sizeof(elast));
        tot = 0;
        Minn = 1e17;
        k.clear();
        cin >> n >> m;
        for (ll i = 1; i <= m; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            add(x, y, z);
        }
        cin >> kk;
        while (kk--)
        {
            ll x;
            cin >> x;
            k.push_back(x);
        }
        dijkstra();
        if (Minn == 1e17)
        {
            Minn = -1;
        }
        cout << Minn << endl;
    }
}