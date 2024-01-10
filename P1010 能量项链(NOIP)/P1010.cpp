#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll n;
ll a[N*2];
ll dp[N*2][N*2]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		a[i+n]=a[i];
	}
	ll j;
	for(ll k=2;k<=n;k++){
		for(ll i=1;i<=2*n-k+1;i++){
			j=i+k-1;
			for(ll k=i;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
//				cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<endl;
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	ll ans=-1;
	for(ll i=1;i<=n+1;i++){
		ans=max(ans,dp[i][i+n-1]);
	}
	cout<<ans<<endl;
}
