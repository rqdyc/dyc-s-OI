#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=1e8+7;
const ll T=1.5e4+10;
const ll N=1e3;
ll n,p,t;
ll dp[T];
ll c[T];
int main() {
	freopen("pass_lock.in","r",stdin);
	freopen("pass_lock.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&p,&t);
	dp[0]=1;
	for(ll i=1; i<=n; i++) {
		memset(c,0,sizeof(c));
		for(ll j=0;j<=t;j++){
			c[j]=c[j-1]+dp[j];
			c[j]%=P;
//			cout<<j<<" "<<c[j]<<endl;
		}
		for(ll k=t; k>=1; k--) {
			dp[k]=0;
			if(((k-1)-p)<0)dp[k]=c[k-1];
			else dp[k]+=c[k-1]-c[(k-1)-p];
			dp[k]%=P;
		}
		dp[0]=0;
	}
	printf("%lld",(dp[t]+P*100)%P);
}
