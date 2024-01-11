#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll P=1e9+7;
const ll N=1e5+10;
ll n,m,seed,vmax;
ll rnd() {
	ll seedd=seed;
	seed=(seed*7+13)%P;
	return seedd;
}
ll a[N];
struct question {
	ll op,l,r,x,y;
} q[N];
void random_() {
	for(ll i=1; i<=n; i++) {
		a[i]=(rnd()%vmax)+1;
	}
	for(ll i=1; i<=m; i++) {
		q[i].op=(rnd()%4)+1;
		q[i].l=(rnd()%n)+1;
		q[i].r=(rnd()%n)+1;
		if(q[i].l>q[i].r) {
			swap(q[i].l,q[i].r);
		}
		if(q[i].op==3) {
			q[i].x=(rnd()%(q[i].r-q[i].l+1))+1;
		} else {
			q[i].x=(rnd()%vmax)+1;
		}
		if(q[i].op==4) {
			q[i].y=(rnd()%vmax)+1;
		}
	}
}
struct node {
	ll l,r;
	mutable ll v;
	node(ll l,ll r=0,ll v=0):l(l),r(r),v(v) {}
	bool operator < (const node &a) const {
		return l<a.l;
	}
};
set<node>s;
set<node>::iterator split(ll pos) {
	set<node>::iterator it=s.lower_bound(node(pos));;
	if(it!=s.end()&&(it->l)==pos) {
		return it;
	}
	it--;
	ll l=it->l,r=it->r,v=it->v;
	if(r<pos)return s.end();
	s.erase(it);
	s.insert(node(l,pos-1,v));
	return s.insert(node(pos,r,v)).first;
}
void assign(ll l,ll r,ll x) {
	set<node>::iterator itr=split(r+1),itl=split(l);;
	s.erase(itl,itr);
	s.insert(node(l,r,x));
}
void add(ll l,ll r,ll x) {
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		(it->v)+=x;
	}
}
struct node2 {
	ll v,cnt;
	node2(ll v,ll cnt):v(v),cnt(cnt) {}
};
bool cmp(node2 a,node2 b) {
	return a.v<b.v;
}
ll search(ll l,ll r,ll x) {
	set<node>::iterator itr=split(r+1),itl=split(l);
	vector<node2>v;
	for(set<node>::iterator it=itl; it!=itr; it++) {
		v.push_back(node2(it->v,(it->r)-(it->l)+1));
	}
	sort(v.begin(),v.end(),cmp);
	ll i;
	for(i=0; i<v.size(); i++) {
		if(v[i].cnt<x)x-=v[i].cnt;
		else break;
	}
	return v[i].v;
}
ll qpow(ll a_,ll n_,ll p_) {
	ll ans_=1;
	a_%=p_;
	while(n_) {
		if(n_&1)ans_=ans_*a_%p_;
		n_/=2;
		a_=a_*a_%p_;
	}
	return ans_;
}
ll getans_pow(ll l,ll r,ll x,ll y) {
	ll ans_=0;
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		ans_+=(qpow(it->v,x,y)*(((it->r)-(it->l)+1)%y))%y;
		ans_%=y;
	}
	return ans_%y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>seed>>vmax;
	random_();
	for(ll i=1; i<=n; i++) {
		s.insert(node(i,i,a[i]));
	}
	for(ll i=1; i<=m; i++) {
		if(q[i].op==1) {
			add(q[i].l,q[i].r,q[i].x);
		}
		if(q[i].op==2) {
			assign(q[i].l,q[i].r,q[i].x);
		}
		if(q[i].op==3) {
			cout<<search(q[i].l,q[i].r,q[i].x)<<endl;
		}
		if(q[i].op==4) {
			cout<<(getans_pow(q[i].l,q[i].r,q[i].x,q[i].y)+q[i].y)%q[i].y<<endl;
		}
	}
}