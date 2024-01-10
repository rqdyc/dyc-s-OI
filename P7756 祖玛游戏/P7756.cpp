#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
const ll K=5+10;
ll n,kk;
ll a[N];
ll dp[N][N][K];//[i,j],前跟k
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>kk;
	memset(dp,0x3f,sizeof(dp));
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		for(ll j=0; j<kk; j++) {
//			cout<<i<<" "<<j<<" "<<kk-j-1<<endl;
			dp[i][i][j]=kk-j-1;
		}
	}
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			for(ll l=kk-1; l>=0; l--) {
//				cout<<i<<" "<<j<<" "<<l<<" "<<dp[i][j][l]<<endl;
				if(l==kk-1) {
					dp[i][j][l]=min(dp[i][j][l],dp[i+1][j][0]);
//					cout<<dp[i+1][j][0]<<endl;
				} else {
					dp[i][j][l]=min(dp[i][j][l],dp[i][j][min(l+1,kk-1)]+1);//刚好合并
				}
//				cout<<dp[i][j][l]<<endl;
				if(a[i]==a[i+1]) {
					dp[i][j][l]=min(dp[i][j][l],dp[i+1][j][min(l+1,kk-1)]);
				}
				for(ll l_=i+1; l_<j; l_++) {
					if(a[i]==a[l_+1]) {
						dp[i][j][l]=min(dp[i][j][l],dp[i+1][l_][0]+dp[l_+1][j][min(l+1,kk-1)]);
					}
				}
//				cout<<dp[i][j][l]<<endl;
			}
		}
	}
	cout<<dp[1][n][0]<<endl;
}
