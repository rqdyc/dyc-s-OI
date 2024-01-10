#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5010;
ll n;
ll a[N];
long double rt=0;
bool look[N][N];
ll dp[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		dp[i][i]=look[i][i]=1;
	}
	for(ll i=1; i<=n; i++) {
		rt=-5010;
		for(ll j=i+1; j<=n; j++) {
			long double nowrt=(long double)((long double)(a[j]-a[i]))/((long double)(j-i));
			if(nowrt>rt) {
				rt=nowrt;
				look[i][j]=1;
			}
		}
	}
//	for(ll i=1; i<=n; i++) {
//		for(ll j=i+1; j<=n; j++) {
//			cout<<i<<" "<<j<<" "<<look[i][j]<<endl;
//		}
//	}
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			
		}
	}
}
