#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t[200001];
ll LR[2][200001];
struct s1
{
	ll x, y, l;
} a[400001];
ll last[200001];
struct s2
{
	ll t, to, l, i;
} nxet[400001];
ll cd = 0;
void lj(ll x, ll y, ll l, ll i)
{
	nxet[++cd].t = last[x];
	nxet[cd].to = y;
	nxet[cd].l = l;
	nxet[cd].i = i;
	last[x] = cd;
}
ll dis[2][200001];
bool vis[2][200001];
ll fa[200001];
struct s3
{
	ll x, l;
} h[400001];
ll len;
bool f(s3 num1, s3 num2)
{
	return num1.l > num2.l;
}
void dijkstra1(ll s)
{
	memset(dis[1], 0x7f, sizeof(dis[1]));
	dis[1][s] = 0;
	h[0] = {s, 0};
	len = 1;
	while (len)
	{
		ll x = h[0].x;
		pop_heap(h, h + len, f);
		len--;
		if (vis[1][x])
			continue;
		vis[1][x] = 1;
		for (ll j = last[x]; j; j = nxet[j].t)
		{
			ll y = nxet[j].to;
			if (dis[1][y] > dis[1][x] + nxet[j].l)
			{
				dis[1][y] = dis[1][x] + nxet[j].l;
				fa[y] = nxet[j].i;
				if (a[nxet[j].i].y == y)
					a[nxet[j].i].x ^= a[nxet[j].i].y ^= a[nxet[j].i].x ^= a[nxet[j].i].y;
				h[len].x = y;
				h[len++].l = dis[1][y];
				push_heap(h, h + len, f);
			}
		}
	}
}
void dijkstra2(ll s, ll lr)
{
	memset(dis[lr], 0x7f, sizeof(dis[lr]));
	memset(vis[lr], 0, sizeof(vis[lr]));
	dis[lr][s] = 0;
	LR[lr][s] = s;
	h[0] = {s, 0};
	len = 1;
	while (len)
	{
		ll x = h[0].x;
		pop_heap(h, h + len, f);
		len--;
		if (vis[lr][x])
			continue;
		vis[lr][x] = 1;
		for (ll j = last[x]; j; j = nxet[j].t)
		{
			ll y = nxet[j].to;
			if (dis[lr][y] > dis[lr][x] + nxet[j].l)
			{
				dis[lr][y] = dis[lr][x] + nxet[j].l;
				LR[lr][y] = (t[nxet[j].i] ? y : LR[lr][x]);
				h[len].x = y;
				h[len++].l = dis[lr][y];
				push_heap(h, h + len, f);
			}
		}
	}
}
struct s4
{
	ll l, r, pre, add;
} tree[800001];
void make_tree(ll p, ll l, ll r)
{
	tree[p].l = l;
	tree[p].r = r;
	tree[p].pre = tree[p].add = 1e18;
	if (l < r)
	{
		ll mid = (l + r) >> 1;
		make_tree(2 * p, l, mid);
		make_tree(2 * p + 1, mid + 1, r);
	}
}
void push_down(ll p)
{
	if (tree[p].l < tree[p].r && tree[p].add)
	{
		ll mid = (tree[p].l + tree[p].r) >> 1;
		tree[2 * p].pre = min(tree[2 * p].pre, tree[p].add);
		tree[2 * p].add = min(tree[2 * p].add, tree[p].add);
		tree[2 * p + 1].pre = min(tree[2 * p + 1].pre, tree[p].add);
		tree[2 * p + 1].add = min(tree[2 * p + 1].add, tree[p].add);
		tree[p].add = 1e18;
	}
}
void add(ll p, ll l, ll r, ll k)
{
	if (l <= tree[p].l && tree[p].r <= r)
	{
		tree[p].pre = min(tree[p].pre, k);
		tree[p].add = min(tree[p].add, k);
		return;
	}
	push_down(p);
	ll mid = (tree[p].l + tree[p].r) >> 1;
	if (l <= mid)
		add(2 * p, l, r, k);
	if (r > mid)
		add(2 * p + 1, l, r, k);
}
ll ask(ll p, ll x)
{
	if (tree[p].l == tree[p].r)
		return tree[p].pre;
	push_down(p);
	ll mid = (tree[p].l + tree[p].r) >> 1;
	return x <= mid ? ask(2 * p, x) : ask(2 * p + 1, x);
}
int main()
{
	//	freopen("TestData001.in","r",stdin);
	//	freopen("W.out","w",stdout);
	ll n, m, q;
	scanf("%lld%lld%lld", &n, &m, &q);
	for (ll i = 1; i <= m; i++)
	{
		ll x, y, l;
		scanf("%lld%lld%lld", &x, &y, &l);
		lj(x, y, l, i);
		lj(y, x, l, i);
		a[i].x = x;
		a[i].y = y;
		a[i].l = l;
	}
	for (ll i = m + 1; i <= 2 * m; i++)
	{
		a[i].x = a[i - m].y;
		a[i].y = a[i - m].x;
		a[i].l = a[i - m].l;
	}
	dijkstra1(n);
	ll cnt = 1;
	//	printf("1");
	for (ll x = fa[1]; x; cnt++, x = fa[a[x].y])
	{
		t[x] = cnt;
		//		printf("->%lld",a[x].y);
	}
	//	puts("");
	t[0] = cnt--;
	dijkstra2(1, 0);
	dijkstra2(n, 1);
	make_tree(1, 1, cnt + 1);
	for (ll i = 1; i <= 2 * m; i++)
	{
		if (t[i])
			continue;
		else
		{
			if (t[fa[LR[0][a[i].x]]] < t[fa[LR[1][a[i].y]]])
				add(1, t[fa[LR[0][a[i].x]]], t[fa[LR[1][a[i].y]]] - 1, dis[0][a[i].x] + a[i].l + dis[1][a[i].y]);
			if (t[fa[LR[0][a[i].y]]] < t[fa[LR[1][a[i].x]]])
				add(1, t[fa[LR[0][a[i].y]]], t[fa[LR[1][a[i].x]]] - 1, dis[0][a[i].y] + a[i].l + dis[1][a[i].x]);
		}
	}
	//	printf("1~n:%lld\n",dis[0][n]);
	while (q--)
	{
		ll i, k;
		scanf("%lld%lld", &i, &k);
		if (t[i])
			printf("%lld\n", min(dis[0][n] - a[i].l + k, ask(1, t[i])));
		else
			printf("%lld\n", min(dis[0][n], min(dis[0][a[i].x] + k + dis[1][a[i].y], dis[0][a[i].y] + k + dis[1][a[i].x])));
	}
	return 0;
}