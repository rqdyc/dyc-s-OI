#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 10;
const ll M = 1e6 + 10;
struct edge
{
    ll x, y, z;
    bool t;
    ll next;
} e[M];
ll elast[N];
ll tot = 0;
void add(ll x, ll y, ll z, bool t)
{
    tot++;
    e[tot].x = x;
    e[tot].y = y;
    e[tot].z = z;
    e[tot].t = t;
    e[tot].next = elast[x];
    elast[x] = tot;
}
struct node
{
    ll x;
    ll dis;
    bool t;
    node(ll x = 0, ll dis = 0, bool t = 0) : x(x), dis(dis), t(t){};
};
struct cmp
{
    bool operator()(node a, node b)
    {
        return a.dis > b.dis;
    }
};
ll T;
ll n, m, s, k;
ll dis[N][2];
bool vis[N][2];
unordered_map<ll, ll> l[N];
unordered_map<ll, bool> visss;
void dijkstra(ll st)
{
    visss.clear();
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis[i][0] = dis[i][1] = 1e17;
        vis[i][0] = vis[i][1] = 0;
        visss[i] = 1;
    }
    dis[st][0] = 0;
    q.push(node(st, dis[st][0], 0));
    while (!q.empty())
    {
        ll x = q.top().x;
        bool t = q.top().t;
        // cout << x << " " << t << " " << dis[x][t] << endl;
        q.pop();
        if (vis[x][t])
        {
            // cout << "rvis:" << x << " " << t << " " << dis[x][t] << endl;
            continue;
        }
        vis[x][t] = 1;
        // cout << x << " " << t << " " << dis[x][t] << endl;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            bool rt = e[i].t;
            if (dis[y][rt] > dis[x][t] + (e[i].z - k * (t == 1)))
            {
                dis[y][rt] = dis[x][t] + (e[i].z - k * (t == 1));
                q.push(node(y, dis[y][rt], rt));
            }
        }
        if (t == 1)
        {
            unordered_map<ll, bool> id;
            for (auto it = visss.begin(); it != visss.end(); it++)
            {
            rt:
                if (it == visss.end())
                {
                    break;
                }
                ll j = it->first;
                if (l[x][j] || x == j)
                {
                    continue;
                }
                dis[j][0] = min(dis[j][0], dis[x][t]);
                if (!vis[j][0])
                {
                    // cout << x << " " << j << endl;
                    q.push(node(j, dis[j][0], 0));
                    visss.erase(it++);
                    goto rt;
                }
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
        cin >> n >> m >> s >> k;
        // memset(e, 0, sizeof(e));
        memset(elast, 0, sizeof(elast));
        for (ll i = 1; i <= n; i++)
        {
            l[i].clear();
        }
        tot = 0;
        for (ll i = 1; i <= m; i++)
        {
            ll x, y, z;
            bool t;
            cin >> x >> y >> z >> t;
            add(x, y, z, t);
        }
        for (ll i = 1; i <= tot; i++)
        {
            ll y = e[i].y, t = e[i].t;
            if (t)
            {
                for (ll j = elast[y]; j; j = e[j].next)
                {
                    ll x = e[j].y;
                    l[y][x] = 1;
                }
            }
        }
        dijkstra(s);
        for (ll i = 1; i <= n; i++)
        {
            dis[i][0] = min(dis[i][1], dis[i][0]);
            if (dis[i][0] >= 1e13)
            {
                dis[i][0] = -1;
            }
            cout << dis[i][0] << " ";
        }
        // cout << (rt - T) << " " << clock() << endl;
        cout << endl;
    }
    // cout << clock() << endl;
}