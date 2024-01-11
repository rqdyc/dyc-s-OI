#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll MAXN = 100005;

struct Node {
	ll l, r;//l��r��ʾ��һ�ε������յ�
	mutable ll v;//v��ʾ��һ��������Ԫ����ͬ��ֵ�Ƕ���

	Node(ll l, ll r = 0, ll v = 0) : l(l), r(r), v(v) {}

	bool operator<(const Node &a) const {
		return l < a.l;//�涨����ÿ�ε���˵�����
	}
};

ll n, m, seed, vmax, a[MAXN];
set<Node> s;

//��posȥ���и�ҵ�һ������pos�����䣬�����ֳ�[l,pos-1],[pos,r]����
set<Node>::iterator split(int pos) {
	set<Node>::iterator it = s.lower_bound(Node(pos));
	if (it != s.end() && it->l == pos) {
		return it;
	}
	it--;
	if (it->r < pos) return s.end();
	ll l = it->l;
	ll r = it->r;
	ll v = it->v;
	s.erase(it);
	s.insert(Node(l, pos - 1, v));
	//insert��������pair�����е�first���²�����ĵ�����
	return s.insert(Node(pos, r, v)).first;
}

/*
 * ����ע������ȼ���itr��
 * ��������������[1,4]�����Ҫadd����[1,2],�����split(1)
 * ��ô���ص�itl��[1,4]��������һ������itr��ʱ�����������ɾ�����[1,2]��[3,4]
 * ��ôitl���ָ��ͱ��ͷ���
 * */
void add(ll l, ll r, ll x) {
	set<Node>::iterator itr = split(r + 1), itl = split(l);
	for (set<Node>::iterator it = itl; it != itr; ++it) {
		it->v += x;
	}
}

void assign(ll l, ll r, ll x) {
	set<Node>::iterator itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(Node(l, r, x));
}

struct Rank {
	ll num, cnt;

	bool operator<(const Rank &a) const {
		return num < a.num;
	}

	Rank(ll num, ll cnt) : num(num), cnt(cnt) {}
};

ll rnk(ll l, ll r, ll x) {
	set<Node>::iterator itr = split(r + 1), itl = split(l);
	vector<Rank> v;
	for (set<Node>::iterator i = itl; i != itr; ++i) {
		v.push_back(Rank(i->v, i->r - i->l + 1));
	}
	sort(v.begin(), v.end());
	int i;
	for (i = 0; i < v.size(); ++i) {
		if (v[i].cnt < x) {
			x -= v[i].cnt;
		} else {
			break;
		}
	}
	return v[i].num;
}

ll ksm(ll x, ll y, ll p) {
	ll r = 1;
	ll base = x % p;
	while (y) {
		if (y & 1) {
			r = r * base % p;
		}
		base = base * base % p;
		y >>= 1;
	}
	return r;
}

ll calP(ll l, ll r, ll x, ll y) {
	set<Node>::iterator itr = split(r + 1), itl = split(l);
	ll ans = 0;
	for (set<Node>::iterator i = itl; i != itr; ++i) {
		ans = (ans + ksm(i->v, x, y) * (i->r - i->l + 1) % y) % y;
	}
	return ans;
}

ll rnd() {
	ll ret = seed;
	seed = (seed * 7 + 13) % MOD;
	return ret;
}

int main() {
	freopen("question.in","r",stdin);
	freopen("ans_answer.out","w",stdout); 
	cin >> n >> m >> seed >> vmax;
	for (int i = 1; i <= n; ++i) {
		a[i] = (rnd() % vmax) + 1;
		s.insert(Node(i, i, a[i]));
	}
	for (int i = 1; i <= m; ++i) {
		ll op, l, r, x, y;
		op = (rnd() % 4) + 1;
		l = (rnd() % n) + 1;
		r = (rnd() % n) + 1;
		if (l > r) swap(l, r);
		if (op == 3) {
			x = (rnd() % (r - l + 1)) + 1;
		} else {
			x = (rnd() % vmax) + 1;
		}
		if (op == 4) {
			y = (rnd() % vmax) + 1;
		}
		if (op == 1) {
			add(l, r, x);
		} else if (op == 2) {
			assign(l, r, x);
		} else if (op == 3) {
			cout << rnk(l, r, x) << endl;
		} else {
			cout << calP(l, r, x, y) << endl;
		}
	}
	return 0;
}
