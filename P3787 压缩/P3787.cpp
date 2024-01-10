#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
string a;
ll n;
ll dp[N][N];//Ã»ÓÐm
ll dp2[N][N];//ÓÐm
bool check(ll l,ll r) {
	if((r-l+1)%2==1)return 0;
//	cout<<l<<" "<<r<<end]l;
	ll mid=(l+r-1)>>1;
	ll len=(r-l+1);
//	cout<<mid<<endl;
	for(ll i=l; i<=mid; i++) {
//		cout<<i<<" "<<i+len/2<<endl;
		if(a[i]!=a[i+len/2]) {
//			cout<<endl<<endl;
			return 0;
		}
	}
//	cout<<endl<<endl;
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>a;
	n=a.size();
	memset(dp,0x3f,sizeof(dp));
	memset(dp2,0x3f,sizeof(dp2));
	for(ll i=1; i<=n; i++) {
		dp[i][i]=1;
		dp2[i][i]=2;
	}
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			if(check(i-1,j-1)) {
				dp[i][j]=min(dp[i][j],dp[i][(i+j)>>1]+1);
			}
			for(ll l=i; l<j; l++) {
				dp[i][j]=min(dp[i][j],dp[i][l]+j-l);
				dp2[i][j]=min(dp2[i][j],min(dp[i][l],dp2[i][l])+min(dp[l+1][j],dp2[l+1][j])+1);
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<min(dp[1][n],dp2[1][n])<<endl;
}
