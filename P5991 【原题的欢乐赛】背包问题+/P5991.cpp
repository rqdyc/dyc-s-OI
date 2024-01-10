#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=210;
const ll V=2e6+10;
ll a[N],b[N];
ll dp[V];
ll n,v,maxb;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>v;
	for(ll i=1;i<=n;i++){
		cin>>b[i]>>a[i];
	}
//	for(ll i=1;i<=40010;i++){
//		dp[i]=1e17;
//	}
	for(ll i=1;i<=n;i++){
		for(ll j=40010;j>=a[i];j--){
			dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
		}
	}
//	for(ll i=1;i<=40010;i++){
//		cout<<dp[i]<<endl;
//	}
	for(ll i=1;i<=40010;i++){
		if(dp[i]>=v){
			cout<<i<<endl;
			return 0;
		} 
	}
} 
