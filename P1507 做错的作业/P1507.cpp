#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=310;
string ask;
ll n;
ll dp[N][N];
ll check(char a,char b) {
//	cout<<a<<" "<<b<<" ";
	if(a=='('&&b==')') {
//		cout<<1<<endl;
		return 1;
	}
	if(a=='{'&&b=='}') {
//		cout<<1<<endl;
		return 1;
	}
	if(a=='<'&&b=='>') {
//		cout<<1<<endl;
		return 1;
	}
	if(a=='['&&b==']') {
//		cout<<1<<endl;
		return 1;
	}
//	cout<<0<<endl;
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>ask;
	n=ask.size();
//	cout<<n<<endl;
	for(ll i=1; i<=n; i++) {
		dp[i][1]=1;
		dp[i][0]=0;
	}
	ll j;
	for(ll i=1;i<=n;i++){//Î»Êý 
		for(ll j=1;j<=n-i+1;j++){
			dp[j][i]=min(dp[j][i],dp[j][i-1]+1);
			for(ll k=1;k<=i-1;k++){
				if(check(ask[j+k-2],ask[j+i-2])){
//					if(j==9)cout<<ask[j+k-2]<<" "<<ask[j+i-2]<<" "<<dp[j][k-1]<<" "<<dp[k+j][i-k-1]<<endl;
					dp[j][i]=min(dp[j][i],dp[j][k-1]+dp[k+j][i-k-1]);
				}
			}
//			cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
		}
	}
	cout<<dp[1][n]<<endl;
}
