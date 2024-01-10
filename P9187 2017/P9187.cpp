#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
const ll P=2017;
const ll P2=1e12+7;
ll n,r;
ll a[N];
ll dp[P+100];
bool dpr[P+100];
ll ksm(ll x,ll n,ll p){
	ll ans=1;
	while(n>0){
		if(n%2==1)ans*=x;
		n>>=1;
		x=x*x%p;
		x%=p;
		ans%=p;
	}
	return ans;
}
ll getinv(ll x){
	return ksm(x,P-2,P);
}
int main(){
	while(scanf("%lld%lld",&n,&r)!=EOF){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		dp[0]=dp[a[1]]=dpr[a[1]]=1;
		for(ll i=2;i<=n;i++){
			for(ll j=0;j<=P-1;j++){
				dp[(j*a[i])%P]+=dp[j];
				dp[(j*a[i])%P]%=P2;
			}
		}
		cout<<dp[r]%2<<endl;
	}	
}
