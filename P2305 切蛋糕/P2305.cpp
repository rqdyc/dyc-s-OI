#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=310;
ll n,t;
ll a[N],b[N];
unsigned ll dp[N][N];
ll Cartesian(ll x,ll y) {
	if(abs(x-y)<2)return 0;
	return (abs(a[x]+a[y])*abs(b[x]+b[y]))%t;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>t;
	for(ll i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	for(ll k=3; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			dp[i][j]=1145141919810114514ll;
			for(ll l=i+1; l<j; l++) {
//				cout<<i<<" "<<l<<" "<<j<<" "<<Cartesian(i,j)<<" "<<Cartesian(i,l)<<" "<<Cartesian(l,j)<<endl;
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]+Cartesian(i,l)+Cartesian(l,j));
//				cout<<dp[i][j]<<endl;
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[1][n];
}
