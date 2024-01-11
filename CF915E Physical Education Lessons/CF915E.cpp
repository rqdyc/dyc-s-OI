#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
	ll ans=0,f=1;
	char c=getchar();
	while(c-'0'<0||c-'9'>0) {
		if(c=='-') {
			f=-f;
			c=getchar();
		}
	}
	while(c-'0'>=0&&c-'0'<=9) {
		ans=ans*10+c-'0';
		c=getchar();
	}
	return f*ans;
}
struct node {
	ll l,r;
	mutable ll col;
	node(ll l,ll r=0,ll col=0):l(l),r(r),col(col) {}
	bool operator < (const node &a) const {
		return l<a.l;
	}
};
set<node>s;
set<node>::iterator split(ll pos) {
	set<node>::iterator it=s.lower_bound(node(pos));
	if(it!=s.end()&&(it->l)==pos) {
		return it;
	}
	it--;
	if((it->r)<pos)return s.end();
	ll l=(it->l),r=(it->r),col=(it->col);
	s.erase(it);
	s.insert(node(l,pos-1,col));
	return s.insert(node(pos,r,col)).first;
}
ll ans=0;
void assign(ll l,ll r,ll col) {
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator i=itl; i!=itr; i++) {
		ans-=(i->col)*((i->r)-(i->l)+1);
	}
	s.erase(itl,itr);
	s.insert(node(l,r,col));
	ans+=col*(r-l+1);
}
ll n,q;
ll k,l,r;
int main() {
	n=read(),q=read();
	ans=n;
	s.insert(node(1,n,1));
	for(ll i=1; i<=q; i++) {
		l=read();
		r=read();
		k=read();
		if(k==1)assign(l,r,0);
		else assign(l,r,1);
		printf("%lld\n",ans);
	}
}
