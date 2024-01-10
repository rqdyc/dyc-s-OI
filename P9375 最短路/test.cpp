#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 10;
const ll M = 2e5 + 10;
struct edge
{
    ll x, y, z;
    ll next;
} e[M << 1];
ll elast[N];
ll n, m, q;
void add(ll x, ll y, ll z, ll tot)
{
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
ll dis[2][N];
ll sec_dis[2][N];
ll pre[2][N];
ll pre_edge[2][N];
void dijkstra(ll st, bool opt)
{
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis[opt][i] = 1e17;
        sec_dis[opt][i] = 1e17;
    }
    dis[opt][st] = 0;
    sec_dis[opt][st] = 0;
    q.push(node(st, dis[opt][st]));
    while (!q.empty())
    {
        ll x = q.top().x;
        ll rdis = q.top().dis;
        q.pop();
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            if (dis[opt][y] > dis[opt][x] + e[i].z)
            {
                sec_dis[opt][y] = dis[opt][y];
                dis[opt][y] = dis[opt][x] + e[i].z;
                pre[opt][y] = x;
                pre_edge[opt][y] = i;
                q.push(node(y, dis[opt][y]));
                q.push(node(y, sec_dis[opt][y]));
            }
            else if (sec_dis[opt][y] > rdis + e[i].z && dis[opt][y] <= rdis + e[i].z)
            {
                sec_dis[opt][y] = rdis + e[i].z;
                q.push(node(y, sec_dis[opt][y]));
            }
        }
    }
}

struct cmp2
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        return hash<T1>()(p.first) + p.second;
    }
};
bool viss[M << 1];
bool vis_node[N];
vector<ll> tr;
bool ck[N];
void dfs(ll st)
{
    while (st)
    {
        ll edgeid = pre_edge[0][st];
        if (edgeid > m)
        {
            edgeid -= m;
        }
        viss[edgeid] = 1;
        vis_node[st] = 1;
        tr.push_back(st);
        ck[st] = 1;
        // cout << e[edgeid].x << " " << e[edgeid].y << " " << e[edgeid].z << endl;
        st = pre[0][st];
    }
}
ll rpre[2][N];
void find_dfs(ll x, bool opt)
{
    ll rx = x;
    while (1)
    {
        if (ck[x])
        {
            rpre[opt][rx] = x;
            return;
        }
        x = pre[opt][x];
    }
}
ll wes[N];
struct tree
{
    ll l, r, min = 1e17, lazy = 1e17;
} Tree[N << 3];
void build(ll id, ll l, ll r)
{
    Tree[id].l = l, Tree[id].r = r;
    if (l == r)
    {
        return;
    }
    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}
void pushDown(ll id)
{
    if (Tree[id].l == Tree[id].r)
    {
        return;
    }
    Tree[id * 2].lazy = min(Tree[id].lazy, Tree[id * 2].lazy);
    Tree[id * 2].min = min(Tree[id].lazy, Tree[id * 2].min);
    Tree[id * 2 + 1].lazy = min(Tree[id].lazy, Tree[id * 2 + 1].lazy);
    Tree[id * 2 + 1].min = min(Tree[id].lazy, Tree[id * 2 + 1].min);
    Tree[id].lazy = 1e17;
}
void change(ll id, ll l, ll r, ll x)
{
    if (Tree[id].lazy != 1e17)
    {
        pushDown(id);
    }
    if (l <= Tree[id].l && Tree[id].r <= r)
    {
        Tree[id].min = min(Tree[id].min, x);
        Tree[id].lazy = min(x, Tree[id].lazy);
        return;
    }
    ll mid = (Tree[id].l + Tree[id].r) >> 1;
    if (l <= mid)
        change(id * 2, l, r, x);
    if (r > mid)
        change(id * 2 + 1, l, r, x);
    Tree[id].min = max(Tree[id * 2].min, Tree[id * 2 + 1].min);
}
// GetSum(1,l,r);
ll GetMin(ll id, ll l, ll r)
{
    if (Tree[id].lazy)
    {
        pushDown(id);
    }
    if (l <= Tree[id].l && r >= Tree[id].r)
    {
        return Tree[id].min;
    }
    ll mid = (Tree[id].l + Tree[id].r) >> 1, ans = 1e17;
    if (l <= mid)
    {
        ans = min(ans, GetMin(id * 2, l, r));
    }
    if (r > mid)
    {
        ans = min(ans, GetMin(id * 2 + 1, l, r));
    }
    // cout<<ans<<" ";
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        add(x, y, z, i);
        add(y, x, z, i + m);
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    dfs(n);
    for (ll i = 1; i <= n; i++)
    {
        find_dfs(i, 0);
        find_dfs(i, 1);
    }
    for (ll i = 0; i < tr.size(); i++)
    {
        wes[tr[i]] = i + 1;
    }
    build(1, 1, tr.size());
    for (ll i = 1; i <= m; i++)
    {
        if (viss[i])
        {
            continue;
        }
        cout << e[i].x << " " << rpre[0][e[i].x] << endl;
        cout << e[i].y << " " << rpre[0][e[i].y] << endl;
        cout << endl;
        ll wes_x = wes[rpre[0][e[i].x]], wes_y = wes[rpre[1][e[i].y]];
        if (wes_x > wes_y)
        {
            swap(wes_x, wes_y);
        }
        if (wes_x < wes_y)
        {
            // cout << "[" << wes_x << "," << wes_y << "]=" << e[i].z + dis[0][e[i].x] + dis[1][e[i].y] << endl;
            change(1, wes_x, wes_y - 1, e[i].z + dis[0][e[i].x] + dis[1][e[i].y]);
        }
        wes_x = wes[rpre[1][e[i].x]], wes_y = wes[rpre[0][e[i].y]];
        if (wes_x > wes_y)
        {
            swap(wes_x, wes_y);
        }
        if (wes_x < wes_y)
        {
            // cout << "[" << wes_x << "," << wes_y << "]=" << e[i].z + dis[1][e[i].x] + dis[0][e[i].y] << endl;
            change(1, wes_x, wes_y - 1, e[i].z + dis[1][e[i].x] + dis[0][e[i].y]);
        }
    }
    ll Minn = 1e17;
    while (q--)
    {
        ll xx, x, yy, y;
        cin >> xx >> yy;
        // if (n <= 2000 && m <= 2000 && q <= 2000)
        // {
        //     ll bef = e[xx].z;
        //     e[xx].z = yy;
        //     e[xx + m].z = yy;
        //     dijkstra(1, 0);
        //     cout << dis[0][n] << endl;
        //     e[xx].z = bef;
        //     e[xx + m].z = bef;
        //     continue;
        // }
        if (!viss[xx])
        {
            x = e[xx].x, y = e[xx].y;
            cout << min(dis[0][n], min(dis[0][x] + yy + dis[1][y], dis[1][x] + yy + dis[0][y])) << endl;
        }
        else
        {
            if (e[xx].z >= yy)
            {
                cout << dis[0][n] - e[xx].z + yy << endl;
            }
            else
            {
                x = e[xx].x, y = e[xx].y;
                ll wes_x = wes[x], wes_y = wes[y];
                if (wes_x > wes_y)
                {
                    swap(x, y);
                    swap(wes_x, wes_y);
                }
                // cout << Minn << endl;
                // cout << wes_x << " " << wes_y << endl;
                cout << min(dis[0][n] - e[xx].z + yy, GetMin(1, wes_x, wes_y - 1)) << endl;
                // cout << x << ":" << wes_x << " " << y << ":" << wes_y << endl;
            }
        }
    }
}