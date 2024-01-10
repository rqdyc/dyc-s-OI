#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=35;
ll n;
ll a[N];
ll dp[N][N];
ll dp_root[N][N];
void dfs(ll x,ll y) {
	if(x==y) {
		cout<<x<<" ";
		return;
	}
	if(abs(x-y)==1) {
		cout<<min(x,y)<<" "<<max(x,y)<<" ";
		return;
	}
	cout<<dp_root[x][y]<<" ";
	dfs(x,dp_root[x][y]-1);
	dfs(dp_root[x][y]+1,y);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(ll i=1; i<=n; i++) {
		for(ll j=i+1; j<=n; j++) {
			dp[i][j]=dp[i][j-1]+dp[i+1][j];
		}
	}
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			for(ll l=i+1; l<j; l++) {
				if(dp[i][j]<dp[i][l-1]*dp[l+1][j]+a[l]) {
					dp[i][j]=dp[i][l-1]*dp[l+1][j]+a[l];
					dp_root[i][j]=l;
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	dfs(1,n);
	return 0;
}
