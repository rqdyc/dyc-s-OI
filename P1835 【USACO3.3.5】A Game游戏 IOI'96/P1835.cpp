#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+10;
ll n;
ll anss;
ll a[N];
ll dp[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		anss+=a[i];
		dp[i][i]=a[i];
		dp[i-1][i]=max(dp[i][i],dp[i-1][i-1]);
	}
	for(ll i=n-2;i>=1;i--){
		for(ll j=i;j<=n;j++){
			dp[i][j]=max(a[i]+min(dp[i+1][j-1],dp[i+2][j]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}
	cout<<dp[1][n]<<" "<<anss-dp[1][n];
}
