#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+10;
ll n;
ll a[N];
ll sum[N];
ll dp[N][N];
ll best[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		dp[i][i]=0;
		best[i][i]=i;
	}
	ll j=0;
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			j=i+k-1;
			for(ll k=best[i][j-1];k<=best[i+1][j];k++){
				if(dp[i][j]>dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]){
					dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
					best[i][j]=k;
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
}
/*
dp[1][2]=14
dp[1][3]=20+
*/
