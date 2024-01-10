#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=35;
const ll M=1010;
ll a[N];
ll dp[N][M];
ll dps[N][M];
ll sum[M];
ll n,m;
ll q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>q;
	while(q--) {
		cin>>n>>m;
		memset(dp,0,sizeof(dp));
		memset(dps,0,sizeof(dps));
		memset(a,0,sizeof(a));
		ll ans=0;
		for(ll i=1; i<=n; i++) {
			cin>>a[i];
			sum[i]=a[i]+sum[i-1];
		}
		dp[0][0]=1;
		dps[0][0]=1;
		for(ll i=1; i<=n; i++) {
			for(ll j=m; j>=a[i]; j--) {
				dp[i][j]+=dp[i-1][j-a[i]];
			}
			for(ll j=1; j<=m; j++) {
				dp[i][j]+=dp[i-1][j];
				dps[i][j]=dps[i][j-1]+dp[i][j];
			}
			for(ll j=m; j>=a[i]; j--) {
				for(ll k=1; k<i; k++) {
					if(j+a[k]>m) {
						cout<<i<<" "<<k<<" "<<j<<endl;
						ans+=dps[i][a[k]];
						cout<<dps[i][a[k]]<<endl;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
