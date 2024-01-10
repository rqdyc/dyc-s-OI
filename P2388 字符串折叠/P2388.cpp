#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll n;
string input;
string a;
ll dp[N][N];
ll sum(ll x) {
	if(x<10)return 1;
	if(x<100)return 2;
	return 3; 
}
bool check(ll i,ll l,ll j) {
	if((j-i+1)%(l-i+1)!=0)return 0;
	for(ll ii=i; ii<=l; ii++) {
		for(ll jj=ii; jj<=j; jj+=(l-i+1)) {
			if(a[ii]!=a[jj]){
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	n=input.size();
	a.resize(n+1);
//	cout<<sum(114)<<endl;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			dp[i][j]=j-i+1;
		}
	}
	for(ll i=n; i>=1; i--) {
		a[i]=input[i-1];
		dp[i][i]=1;
	}
	input[0]=0;
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			for(ll l=i; l<j; l++) {
				if(check(i,l,j)) {
					dp[i][j]=min(dp[i][j],2+dp[i][l]+sum(k/(l-i+1)));
				} else {
					dp[i][j]=min(dp[i][j],dp[i][l]+dp[l+1][j]);
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
}
