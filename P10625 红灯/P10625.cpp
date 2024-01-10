#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = (ll)(5e5 + 10) << 4;
const ll M = N;
ll n;
ll c[N][4];
struct cmp2
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        return hash<T1>()(p.first) + p.second;
    }
};
unordered_map<pair<ll, ll>, ll, cmp2> m;
ll prtot = 0;
ll getid(ll x, ll y)
{
    auto c = make_pair(x, y);
    if (!m[c])
    {
        prtot++;
        m[c] = prtot;
    }
    return m[c];
}
ll s1, s2, ids, t1, t2, idt;
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
void add_edge(ll x, ll y, ll id)
{
    for (ll i = 0; i < 4; i++)
    {
        add(getid(x, y), getid(y, c[y][(i + id) % 4]), (i == 1 ? 0 : 1));
    }
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
ll dis[N];
bool vis[N];
void dijkstra(ll st, ll en)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= prtot; i++)
    {
        dis[i] = 1e17;
    }
    dis[st] = 0;
    q.push(node(st, 0));
    while (!q.empty())
    {
        ll x = q.top().x;
        q.pop();
        if (vis[x])
        {
            continue;
        }
        if (x == en)
        {
            continue;
        }
        vis[x] = 1;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //	cout<<sizeof(e)<<endl;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < 4; j++)
        {
            cin >> c[i][j];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < 4; j++)
        {
            ll y = c[i][j];
            if (c[i][j])
            {
                add_edge(y, i, j);
            }
        }
    }
    cin >> s1 >> s2 >> t1 >> t2;
    ids = getid(s1, s2);
    idt = getid(t1, t2);
    //	cout<<prtot<<endl;
    dijkstra(ids, idt);
    if (dis[idt] == 1e17)
    {
        dis[idt] = -1;
    }
    cout << dis[idt] << endl;
}