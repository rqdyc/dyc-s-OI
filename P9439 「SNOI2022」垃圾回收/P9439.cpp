#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll N=4e5+10;
const ll M=4e5+10;
const ll Q=4e5+10;
ll n,m,qr;
ll a[N];
struct node {
	ll x,y;
	bool del;
} e[M];
struct ques {
	string op;
	ll x;
} q[Q];
ll father[N];
ll sum[N];
void init() {
	for(ll i=1; i<=n; i++) {
		father[i]=i;
		sum[i]=a[i];
	}
}
ll getfather(ll x) {
	ll rx=x;
	while(x!=father[x]){
//		cout<<x<<endl;
		x=father[x];
	}
	while(rx!=father[rx]){
		father[rx]=x;
		rx=father[rx];
	}
	return x;
}
void Merge(ll x,ll y) {
	ll fx=getfather(x);
	ll fy=getfather(y);
	if(fx!=fy) {
		father[fx]=fy;
		sum[fy]+=sum[fx];
	}
}
ll last_sum;
ll ans=0;
int main() {
//	freopen("P8359_2.in","r",stdin);
//	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>qr;
	for(ll i=1; i<=m; i++) {
		cin>>e[i].x>>e[i].y;
	}
	for(ll i=1; i<=qr; i++) {
		cin>>q[i].op;
		if(q[i].op=="DELETE") {
			cin>>q[i].x;
			e[q[i].x].del=1;
		}
	}
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	init();
	for(ll i=1; i<=m; i++) {
		if(!e[i].del) {
			Merge(e[i].x,e[i].y);
		}
	}
//	cout<<getfather(1)<<endl;
	ans+=sum[getfather(1)]*(qr+1);
	last_sum=sum[getfather(1)];
//	bool change=0;
//	q[0].op="DELETE";
//	q[0].x=0;
	ll last_gc=n;
	for(ll i=qr; i>=1; i--) {
//		cout<<i<<endl;
		if(i>n)break;
		if(q[i].op=="DELETE") {
			Merge(e[q[i].x].x,e[q[i].x].y);
			if(q[i+1].op=="GC") {
				last_gc=i+1;
				ll ri=i+1;
				while(1) {
					i--;
					if(i<1)break;
					if(q[i].op=="GC") {
						break;
					}
					Merge(e[q[i].x].x,e[q[i].x].y);
				}
//				cout<<ri<<" "<<getfather(1)<<" "<<last_sum<<" "<<sum[getfather(1)]<<" "<<(i+1)*(sum[getfather(1)]-last_sum)<<endl;
				ans+=ri*(sum[getfather(1)]-last_sum);
				last_sum=sum[getfather(1)];
			}
		}
	}
//	cout<<1<<endl;
	if(q[1].op=="GC") {
//		cout<<1<<endl;
		last_gc=1;
	}
	for(ll i=2; i<=n; i++) {
//		cout<<i<<endl;
		if(getfather(1)!=getfather(i)) {
			ans+=last_gc*a[i];
		}
	}
	cout<<ans<<endl;
}
