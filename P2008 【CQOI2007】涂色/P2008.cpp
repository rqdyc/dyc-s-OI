#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
ll n;
string a;
ll dp[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>a;
	n=a.size();
	for(ll i=1; i<=n; i++) {
		dp[i][i]=1;
	}
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			if(a[i-1]==a[j-1]) {
				dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
			} else {
				for(ll l=i; l<j; l++) {
					dp[i][j]=min(dp[i][j],(ll)dp[i][l]+dp[l+1][j]);
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
