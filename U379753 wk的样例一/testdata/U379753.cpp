#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
const ll P=1e9+7;
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
	set<node>::iterator itr=split(r+1),itl=split(l);
	s.erase(itl,itr);
	s.insert(node(l,r,(x+P)%P));
	return;
}
void add(ll l,ll r,ll x) {
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		(it->v)+=x;
		(it->v)=(it->v+P)%P;
	}
}
ll exgcd(ll a,ll b,ll &x,ll &y) { //扩展欧几里得算法
	if(b==0) {
		x=1,y=0;
		return a;
	}
	ll ret=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return ret;
}
ll getinv(ll a,ll mod) { //求a在mod下的逆元，不存在逆元返回0
	ll x,y;
	ll d=exgcd(a,mod,x,y);
	return d==1?(x%mod+mod)%mod:0;
}
void change_inv(ll l,ll r,ll p) {
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		(it->v)=getinv(it->v,p);
		(it->v)=(it->v+P)%P;
	}
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
void change_pow(ll l,ll r,ll x) {
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		it->v=(qpow(it->v,x,P))%P;
		(it->v)=(it->v+P)%P;
	}
	return;
}
ll getsum(ll l,ll r) {
	ll ans=0;
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		ans+=(it->v)*(it->r-it->l+1);
	}
	return ans;
}
ll getrt(ll l,ll r,ll u) {
	ll ans=0;
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		if((it->v)%u==0)ans+=(it->r-it->l+1);
	}
	return ans;
}
ll getor(ll l,ll r) {
	ll ans=0;
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		ans|=(it->v);
	}
	return ans;
}
ll n,m;
ll a[N];
char ques;
int main() {
	freopen("testdata000.in","r",stdin);
	freopen("testdata000.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		s.insert(node(i,i,a[i]));
	}
	ll op,l,r,c;
	for(ll i=1; i<=m; i++) {
		cin>>ques;
		if(ques=='A') {
			cin>>op>>l>>r>>c;
			if(op==1) {
				assign(l,r,c);
			}
			if(op==2) {
				add(l,r,c);
			}
			if(op==3) {
				change_inv(l,r,c);
			}
			if(op==4) {
				change_pow(l,r,c);
			}
		} else {
			cin>>op>>l>>r;
			if(op==1) {
				cout<<(getsum(l,r)+P)%P<<"\n";
			}
			if(op==2) {
				cin>>c;
				cout<<(getrt(l,r,c)+P)%P<<"\n";
			}
			if(op==3) {
				cout<<(getor(l,r)+P)%P<<"\n";
			}
		}
	}
}
