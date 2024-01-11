#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
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
	set<node>::iterator it=s.lower_bound(node(pos));
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
map<ll,ll>m2;
ll find_ans(ll l,ll r) {
	ll tot=0;
	m2.clear();
	set<node>::iterator it=s.lower_bound(node(l));
	if((it->l)!=l)it--;
	for(set<node>::iterator i=it;(i->l)<=r&&(i->r)!=0;i++){
//		cout<<i->l<<" "<<i->r<<" "<<i->v<<endl;
		if(!m2[i->v])m2[i->v]=++tot;
	}
	return tot;
}
ll n,m;
ll a[N];
ll op,l,r,x,len,ans=0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		s.insert(node(i,i,a[i]));
	}
	for(ll i=1; i<=n; i++) {
		cin>>op;
		switch(op) {
			case 1:
				cin>>l>>r>>x;
				assign(l,r,x);
				break;
			case 2:
				cin>>len;
				ans=0;
				for(ll i=1; i<=n-len+1; i++) {
					ans+=find_ans(i,i+len-1);
				}
				cout<<ans<<endl;
				break;
		}
	}
}
