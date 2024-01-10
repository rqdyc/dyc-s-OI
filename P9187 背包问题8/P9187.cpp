#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll T=1e6+10;
const ll N=1e4+10;
bitset<T>dp;
ll t,n;
ll v;
int main(){
	cin>>t>>n;
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		cin>>v;
		dp|=(dp<<(v));
		dp[v]=1;
//		for(ll i=1;i<=t;i++){
//			cout<<dp[i];
//		}
//		cout<<endl;
	}
	for(ll i=0;i<=t;i++){
		cout<<dp[i];
	}
}
