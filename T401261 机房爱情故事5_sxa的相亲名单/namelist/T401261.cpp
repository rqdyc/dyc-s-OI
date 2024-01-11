#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
const ll P=1e9+7;
struct node {
	ll l,r;
	mutable ll v;
	node(ll l=0,ll r=-1,ll v=0):l(l),r(r),v(v) {}
	bool operator < (const node &a) const {
		return l<a.l;
	}
};
node a[N],b[N];
set<node>s;
set<node>::iterator split(ll pos) {
	set<node>::iterator it=s.lower_bound(node(pos));
	if(it!=s.end()&&it->l==pos)return it;
	it--;
	ll lll=it->l,lr=it->r,lv=it->v;
	s.erase(it);
	s.insert(node(lll,pos-1,lv));
	return s.insert(node(pos,lr,lv)).first;
}
void assign(ll l,ll r,ll x) {
	set<node>::iterator itr=split(r+1),itl=split(l);
	s.erase(itl,itr);
	s.insert(node(l,r,x));
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
void change_pow(ll l,ll y) {
	set<node>::iterator itr=split(l+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
		(it->v)=qpow(it->v,y,P);
		(it->v)=((it->v)+P)%P;
//		cout<<(it->l)<<" "<<(it->r)<<" "<<(it->v)<<endl;
	}
}
void swaper(ll l1,ll r1,ll l2,ll r2) {
	if(l1>l2) {
		swap(l1,l2);
		swap(r1,r2);
	}
	ll len1=0,len2=0;
	set<node>::iterator it1r=split(r1+1),it1l=split(l1);
	for(set<node>::iterator it=it1l; it!=it1r; ++it) {
		a[++len1].l=it->l;
		a[len1].r=it->r;
		a[len1].v=it->v;
	}
	set<node>::iterator it2r=split(r2+1),it2l=split(l2);
	for(set<node>::iterator it=it2l; it!=it2r; ++it) {
		b[++len2].l=it->l;
		b[len2].r=it->r;
		b[len2].v=it->v;
	}
	it1r=split(r1+1),it1l=split(l1);
	s.erase(it1l,it1r);
//	cout<<1<<endl;
	it2r=split(r2+1),it2l=split(l2);
	s.erase(it2l,it2r);
//	cout<<1<<endl;
	for(ll i=1; i<=len2; i++) {
		s.insert(node(b[i].l-l2+l1,b[i].r-l2+l1,b[i].v));
	}
	for(ll i=1; i<=len1; i++) {
		s.insert(node(a[i].l-l1+l2,a[i].r-l1+l2,a[i].v));
	}
}
ll n,q;
ll ansof(ll l,ll r,ll z) {
	ll ans=0;
	set<node>::iterator itr=split(r+1),itl=split(l);
	for(set<node>::iterator it=itl; it!=itr; it++) {
//		cout<<(it->l)<<" "<<(it->r)<<" "<<(it->v)<<endl;
		ans+=((it->r)-(it->l)+1)*((it->v)>=z);
	}
	return ans;
}
char ques;
ll op;
ll l,r,x,y,l1,l2,r1,r2,z;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	s.insert(node(0,n+1,0));
	for(ll i=1; i<=q; i++) {
		cin>>ques;
		if(ques=='C') {
			cin>>op;
			if(op==1) {
				cin>>l>>r>>x;
				assign(l,r,x);
			}
			if(op==2) {
				cin>>l>>y;
				change_pow(l,y);
			}
			if(op==3) {
				cin>>l1>>r1>>l2>>r2;
				if(l1==l2&&r1==r2) {
					continue;
				}
				swaper(l1,r1,l2,r2);
			}
		}
		if(ques=='Q') {
			cin>>l>>r>>z;
			cout<<ansof(l,r,z)<<endl;
		}
	}
	return 0;
}
