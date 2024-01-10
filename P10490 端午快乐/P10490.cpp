#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll n,k;
ll ans=0;
ll a[N][8];
ll maxx[8];
ll dp[7][(1<<5)+10];
ll summ(ll x) {
	ll ans=0;
	while(x!=0) {
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
//	cout<<(int)sizeof(dp)<<endl;
//	cout<<summ(3)<<endl;
	for(ll i=1; i<=n; i++) {
		for(ll j=1; j<=5; j++) {
			cin>>a[i][j];
			maxx[j]=max(maxx[j],a[i][j]);
		}
	}
	if(k>=5) {
		for(ll i=1; i<=5; i++) {
			ans+=maxx[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	for(ll s=0; s<=(1<<k)-1; s++) {
		for(ll j=1; j<=n; j++) {
			for(ll i=1; i<=k; i++) {
				if(summ(s)!=i-1)continue;
				if((s>>(i-1))&1)continue;
//				cout<<i<<" "<<j<<" "<<s<<" "<<(ll)s+(1<<(j-1))<<" ";
				dp[i][s+(1<<(j-1))]=max(dp[i][s+(1<<(j-1))],dp[i-1][s]+a[j][i]);
//				cout<<a[j][i]<<endl;
			}
		}
	}
//	cout<<(1<<(k))-1<<endl;
	cout<<dp[k][(1<<(k))-1];
}
