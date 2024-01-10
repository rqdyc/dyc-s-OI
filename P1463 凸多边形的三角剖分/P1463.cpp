#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
ll n;
ll a[N];
unsigned ll dp[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll k=3;k<=n;k++){
		for(ll i=1;i<=n-k+1;i++){
			ll j=i+k-1;
			dp[i][j]=1145141919810114514ll;
			for(ll l=i+1;l<j;l++){
//				cout<<i<<" "<<j<<" "<<k<<" ";
//				cout<<a[i]<<" "<<a[l]<<" "<<a[j]<<" "<<a[i]*a[l]*a[j]<<endl;
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]+a[i]*a[l]*a[j]);
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[1][n];
}
