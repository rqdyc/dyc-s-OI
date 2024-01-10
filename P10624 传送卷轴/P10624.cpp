#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 10;
const ll M = 4e6 + 10;
ll n;
ll kk, p;
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
ll st, en;
ll dis[N];
bool vis[N];
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
void dijkstra(ll st)
{
	priority_queue<node, vector<node>, cmp> q;
	for (ll i = 1; i <= n; i++)
	{
		dis[i] = 1e17;
		vis[i] = 0;
	}
	dis[st] = 0;
	q.push(node(st, 0));
	while (!q.empty())
	{
		ll x = q.top().x;
		q.pop();
		if (x == en)
		{
			break;
		}
		if (vis[x])
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
bool vis2[N];
ll minn[N];
ll poit[N];
void dfs(ll x, ll dep, ll diss)
{
	vis2[x] = 1;
	if (diss < minn[dep])
	{
		minn[dep] = diss;
		poit[dep] = x;
	}
	for (ll i = elast[x]; i; i = e[i].next)
	{
		ll y = e[i].y;
		if (!vis2[y])
		{
			dfs(y, dep + 1, diss + e[i].z);
		}
	}
}
void dfs2(ll x, ll dep)
{
	if (dep - kk >= 1)
	{
		add(x, poit[dep - kk], p);
		add(poit[dep - kk], x, p);
	}
	vis2[x] = 1;
	for (ll i = elast[x]; i; i = e[i].next)
	{
		ll y = e[i].y;
		if (!vis2[y])
		{
			dfs2(y, dep + 1);
		}
	}
}
ll T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (ll i = 1; i <= n; i++)
		{
			minn[i] = 1e17;
		}
		memset(e, 0, sizeof(e));
		tot = 0;
		memset(elast, 0, sizeof(elast));
		for (ll i = 1; i < n; i++)
		{
			ll x, y;
			ll z;
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		cin >> kk >> p;
		cin >> st >> en;
		memset(vis2, 0, sizeof(vis2));
		dfs(1, 1, 0);
		memset(vis2, 0, sizeof(vis2));
		dfs2(1, 1);
		dijkstra(st);
		cout << dis[en] << endl;
	}
	return 0;
}