#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e4+10;
const ll M=5e4+10;
ll n,m;
ll a[N*8],b[N*8];
ll dp[M];
ll tot=0;
void add(ll v,ll w,ll c) {
	ll mr=1;
	while(c>mr) {
		c-=mr;
		tot++;
		a[tot]=v*mr;
		b[tot]=w*mr;
		mr*=2;
	}
	tot++;
	a[tot]=v*c;
	b[tot]=w*c;
}
ll v,w,c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>v>>w>>c;
		add(v,w,c);
	}
	for(ll i=1;i<=tot;i++){
		for(ll j=m;j>=a[i];j--){
			dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
		} 
	}
	ll ans=0;
	for(ll i=1;i<=m;i++)ans=max(ans,dp[i]);
	cout<<ans<<endl;
}
