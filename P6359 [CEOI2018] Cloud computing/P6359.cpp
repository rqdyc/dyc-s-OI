#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e3+10;
const ll inf=-1e15;
ll n,m;
inline ll read() {
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
struct node {
	ll c,f,w;
} e[N];
bool cmp(node a,node b) {
	if(a.w==b.w)return a.f>b.f;
	return a.w<b.w;
}
ll dp[N];
ll core_num;
ll ans;
int main() {
	ans=-inf;
	n=read();
	cout<<n<<endl;
	for(ll i=1; i<=n; i++) {
		dp[i]=-inf;
		cout<<dp[i]<<endl;
		e[i].c=read();
		e[i].f=read();
		e[i].w=read();
		e[i].w=-e[i].w;
	}
	m=read();
	for(ll i=n+1; i<=m+n; i++) {
		dp[i]=-inf;
		e[i].c=read(),e[i].f=read(),e[i].w=read();
	}
	sort(e+1,e+n+m+1,cmp);
	for(ll i=1; i<=n+m; i++) {
		if(e[i].w<0) {
			for(ll j=core_num; j>=0; j--) {
				dp[j+e[i].c]=max(dp[j+e[i].c],dp[j]+e[i].w);
			}
			core_num+=e[i].c;
		} else {
			for(ll j=0; j<=core_num-e[i].c; j++) {
				dp[j]=max(dp[j],dp[j+e[i].c]+e[i].w);
			}
		}
	}
	for(ll i=0; i<=core_num; i++) {
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}
