#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2010,T=2010;
ll n,t;
ll a[N];
ll dp[N][T];
ll c[N][T];
int main() {
	cin>>n>>t;
	memset(dp,0,sizeof(dp));
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		dp[i][0]=1;
		c[i][0]=1;
	}
	dp[0][0]=1;
	c[0][0]=1;
	for(ll i=1; i<=n; i++) {
		for(ll j=t; j>=a[i]; j--) {
			dp[i][j]+=(dp[i-1][j-a[i]]+dp[i-1][j]);
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp[i-1][j-a[i]]<<endl;
			dp[i][j]%=10;
		}
		for(ll j=1;j<a[i];j++){
			dp[i][j]=dp[i-1][j];
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=t;j++){
//			cout<<mp[i][j];
//		}
//		cout<<endl;
//	}
	for(ll i=1; i<=n; i++) {
		for(ll j=1;j<=min(a[i]-1,t);j++){
			c[i][j]=dp[n][j];
			cout<<(c[i][j]+20100000)%10; 
		}
		for(ll j=a[i]; j<=t; j++) {
			c[i][j]=dp[n][j]-c[i][j-a[i]];
			cout<<(c[i][j]+20100000)%10;
		}
		cout<<endl;
	}
}
