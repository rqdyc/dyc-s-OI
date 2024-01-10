#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
const ll M=5e5+10;
ll n,m;
ll dp[M];
ll v,w,c;
ll last_dp[M];
ll q[M];
int main() {
	scanf("%lld%lld",&n,&m);
	for(ll i=1; i<=n; i++) {
		scanf("%lld%lld%lld",&v,&w,&c);
		c=min(c,m/v);
//		memcpy(last_dp,dp,sizeof(dp));
		for(ll k=0; k<v; k++) {
			ll head=1,tail=0;
			for(ll j=0; j<=(m-k)/v; j++) {
				if(head<=tail&&j-c>q[head]) {
					head++;
				}
				while(head<=tail&&dp[k+j*v]-j*w>=last_dp[tail]-q[tail]*w) {
//					cout<<dp[q.back()]-((q.back()-k)/v[i])*w[i]<<" "<< dp[j]-((j-k)/v[i])*w[i]<<endl;
					tail--;							
				}
				q[++tail]=j;
				last_dp[tail]=dp[k+j*v];
				dp[k+j*v]=last_dp[head]+((j-q[head]))*w;
//				cout<<j<<" "<<q.front()<<endl;
			}
//			for(ll i=1;i<=m;i++)
//				cout<<i<<" "<<dp[i]<<endl;
//			}
		}
	}
	printf("%lld",dp[m]);
}
