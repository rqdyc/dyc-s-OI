#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n;
ll a[N],r[N];
map<ll,ll>m;
struct node {
	ll l,r,max;
} Tree[N*16];
void build(ll id,ll l,ll r) {
	Tree[id].l=l,Tree[id].r=r;
	if(l==r) {
		Tree[id].max=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	Tree[id].max=max(Tree[id*2].max,Tree[id*2+1].max);
}
ll getmax(ll id,ll l,ll r) {
	if(Tree[id].l>=l&&Tree[id].r<=r) {
		return Tree[id].max;
	}
	ll mid=(Tree[id].l+Tree[id].r)>>1,maxn=-1;
	if(l<=mid)maxn=max(maxn,getmax(id*2,l,r));
	if(r>mid)maxn=max(maxn,getmax(id*2+1,l,r));
	return maxn;
}
ll find_ans(ll wes,ll x){
//	cout<<endl;
	ll l=wes+1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
//		cout<<wes+1<<" "<<mid<<" "<<getmax(1,wes+1,mid)<<endl;
		if(getmax(1,wes+1,mid)<=x){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		r[i]=a[i];
	}
	sort(r+1,r+n+1);
	ll tot=0;
	for(ll i=1; i<=n; i++) {
		if(!m[r[i]])tot++,m[r[i]]=tot;
	}
	for(ll i=1; i<=n; i++) {
		a[i]=m[a[i]];
//		cout<<a[i]<<" ";
	}
	build(1,1,n);
	ll ans;
	for(ll i=1; i<=n; i++) {
		ans=find_ans(i,a[i]);
		cout<<ans-i-1<<" ";
	}
}
