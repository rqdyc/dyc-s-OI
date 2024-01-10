#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
const ll M = 2e5 + 10;
struct edge
{
    ll x, y, z;
    ll next;
} e[M << 1];
ll elast[N];
// ll outt[N];
ll tot = 0;
void add(ll x, ll y, ll z)
{
    tot++;
    // outt[x]++;
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
ll port[N];
bool vis[N];
ll vis_sum = 0;
queue<int> qq;
void dijkstra1(ll st)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = port[i] = 1e17;
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
        if (vis_sum == n)
        {
            break;
        }
        vis[x] = 1;
        vis_sum++;
        // ll outsum = 0;
        // for (ll i = elast[x]; i; i = e[i].next)
        // {
        //     ll y = e[i].y;
        //     for (ll j = elast[y]; j; j = e[j].next)
        //     {
        //         outsum += outt[e[j].y];
        //     }
        // }
        unordered_map<ll, bool> changes;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            if (e[i].z >= port[y])
            {
                continue;
            }
            port[y] = e[i].z;
            for (ll j = elast[y]; j; j = e[j].next)
            {
                ll z = e[j].y;
                if (vis[z])
                {
                    continue;
                }
                if (dis[z] > dis[x] + (e[i].z + e[j].z) * (e[i].z + e[j].z))
                {
                    dis[z] = dis[x] + (e[i].z + e[j].z) * (e[i].z + e[j].z);
                    if (!changes[z])
                    {
                        changes[z] = 1;
                        qq.push(z);
                    }
                }
            }
        }
        for (unordered_map<ll, bool>::iterator iter = changes.begin(); iter != changes.end(); iter++)
        {
            q.push(node(iter->first, dis[iter->first]));
        }
    }
}
const ll N2 = 1200;
ll Map[N2 + 10][N2 + 10];
void dijkstra2(ll st)
{
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e7;
    }
    dis[st] = 0;
    bool flag = 1;
    while (flag)
    {
        flag = 0;
        ll minn = 1e7, x = -1;
        for (ll i = 1; i <= n; i++)
        {
            if (dis[i] < minn && !vis[i])
            {
                minn = dis[i];
                x = i;
            }
        }
        if (x == -1)
        {
            break;
        }
        flag = 1;
        vis[x] = 1;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            for (ll j = elast[y]; j; j = e[j].next)
            {
                ll z = e[j].y;
                if (y == z)
                {
                    break;
                }
                if (vis[z])
                {
                    continue;
                }
                if (dis[z] > dis[x] + (e[i].z + e[j].z) * (e[i].z + e[j].z))
                {
                    dis[z] = dis[x] + (e[i].z + e[j].z) * (e[i].z + e[j].z);
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
    cin >> n >> m;
    if (n <= N2)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                Map[i][j] = 1e7;
            }
            Map[i][i] = 0;
        }
    }
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
        if (n <= N2)
        {
            Map[x][y] = Map[y][x] = z;
        }
    }
    if (n > N2)
    {
        dijkstra1(1);
    }
    else
    {
        dijkstra2(1);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (dis[i] == 1e17 || dis[i] == 1e7)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << dis[i] << " ";
        }
    }
}
