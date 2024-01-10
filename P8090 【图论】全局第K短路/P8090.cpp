#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 10;
const ll M = 4e5 + 10;
const ll K = 110;
ll n, m, k;
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
unordered_map<ll, ll> dis[N];
unordered_map<ll, ll> vis[N];
unordered_map<ll, ll> change[N];
ll rans;
void dijkstra()
{
    ll sum = 0;
    priority_queue<node, vector<node>, cmp> q;
    for (ll i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        change[i][i] = 1;
        q.push(node(i, 0, i));
    }
    while (!q.empty())
    {
        node r = q.top();
        q.pop();
        ll x = r.x, st = r.st, z = r.dis;
        if (z != 0 && x > st)
        {
            //			cout<<sum<<" "<<st<<"->"<<x<<":"<<z<<endl;
            sum++;
        }
        if (sum == k)
        {
            rans = z;
            return;
        }
        if (vis[st][x])
        {
            continue;
        }
        vis[st][x] = 1;
        for (ll i = elast[x]; i; i = e[i].next)
        {
            ll y = e[i].y;
            if (((change[st][y] && dis[st][y] > dis[st][x] + e[i].z) || (!change[st][y])))
            {
                dis[st][y] = dis[st][x] + e[i].z;
                q.push(node(y, dis[st][y], st));
                if (!change[st][y])
                {
                    change[st][y] = 1;
                }
            }
        }
    }
}
priority_queue<ll, vector<ll>, greater<ll>> ans;
ll maxx, minn = 1e17;
int main()
{
    freopen("Testdata001.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        ans.push(z);
        minn = min(minn, z);
        maxx = max(maxx, z);
        add(x, y, z);
        add(y, x, z);
    }
    if (k == 1)
    {
        cout << minn << endl;
    }
    else if (m >= 2e4)
    {
        for (ll i = 1; i < k; i++)
        {
            ans.pop();
        }
        cout << ans.top() << endl;
    }
    else
    {
        dijkstra();
        cout << rans << endl;
    }
    return 0;
}