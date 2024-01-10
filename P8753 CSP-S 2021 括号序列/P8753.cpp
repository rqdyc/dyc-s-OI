#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=510;
const ll P=1e9+7;
ll n,kk;
char a[N];
bool check_1[N][N];
ll dp[N][N][5];
bool check(ll l,ll r){
	if((a[l]=='?'||a[l]=='(')&&(a[r]=='?'||a[r]==')')){
		return 1;
	}
	return 0;
}
/*
1:********
2:(***)(**
3:***)(**)
4:(**)(**)
*/
int main() {
	cin>>n>>kk;
	scanf("%s",a+1);
	for(ll i=1; i<=n; i++) {
		if(a[i]=='*') {
			dp[i][i][1]=1;
		}
		if(a[i]=='(') {
			dp[i][i][2]=1;
		}
		if(a[i]==')') {
			dp[i][i][3]=1;
		}
		if(a[i]=='?') {
			dp[i][i][1]=1;
			dp[i][i][2]=1;
			dp[i][i][3]=1;
		}
	}
	// for(ll k=2; k<=n; k++) {
	// 	for(ll i=1; i<=n-k+1; i++) {
	// 		ll j=i+k-1;
	// 		for(ll l=i; l<j; l++) {
	// 			if(check(i,l)){
					
	// 			}
	// 		}
	// 		cout<<k<<" "<<i<<" "<<j<<endl;
	// 		cout<<1<<" "<<dp[i][j][1]<<endl;
	// 		cout<<2<<" "<<dp[i][j][2]<<endl;
	// 		cout<<3<<" "<<dp[i][j][3]<<endl;
	// 		cout<<4<<" "<<dp[i][j][4]<<endl;
	// 	}
	// }
	cout<<dp[1][n][4];
}