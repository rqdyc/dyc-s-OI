#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const ll N=1e3+10;
const ll T=2e3+10;
ll t,n;
ll a[N],b[N];
ll dp[N][T];
int main(){
	cin>>t>>n;
	ll rn=n,rt=t;
//	mt19937 rng(time(NULL));
//	for(ll i=1;i<=t;i++){
//		hash[i]=hash[i-1]+rng()%(1e5+10);
//	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>b[i];
	}
	for(ll i=1;i<=n/2;i++){
		swap(a[i],a[n-i+1]);
		swap(b[i],b[n-i+1]);
	}
	for(ll i=1;i<=n;i++){
		bool flag=0;
		for(ll j=t;j>=0;j--){
			dp[i][j]=dp[i-1][j];
		}
		for(ll j=t;j>=a[i];j--){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	queue<ll >q;
	while(n>0&&t>0){
		if(dp[n][t]==dp[n-1][t-a[n]]+b[n]){
			q.push(rn-n+1);
			t=t-a[n];
		}
		n--;
	}  
	cout<<dp[rn][rt]<<" "<<q.size()<<endl;
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}
