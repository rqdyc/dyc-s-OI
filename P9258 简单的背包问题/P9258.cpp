#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
const ll M=N;
ll n,m;
ll dp[M];
ll sum[M];
ll v[N<<2],w[N<<2],c[N<<2];
ll last_dp[M];
ll last_sum[M];
ll q[M];
const ll P=1e9+7;
//deque<ll>q;
int main() {
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		scanf("%lld%lld",&v[i],&c[i]);
	}
	sum[0]=1;
	for(ll i=1; i<=n; i++) {
		for(ll j=0; j<=m; j++) {
			last_dp[j]=dp[j];
			last_sum[j]=sum[j];
		}
//		memcpy(last_dp,dp,sizeof(dp));
		for(ll k=0; k<v[i]; k++) {
			ll st=1,en=0;
			for(ll j=k; j<=m; j+=v[i]) {
				if(st<=en&&q[st]<j-c[i]*v[i]) {
					st++;
				}
				while(st<=en&&last_dp[q[en]]-(q[en]-k)/v[i]*w[i] < last_dp[j]-(j-k)/v[i]*w[i]) {
//					cout<<dp[q.back()]-((q.back()-k)/v[i])*w[i]<<" "<< dp[j]-((j-k)/v[i])*w[i]<<endl;
					en--;
				}
				q[++en]=j;
//				q.push_back(j);
				dp[j]=last_dp[q[st]]+((j-q[st])/v[i])*w[i];
				sum[j]+=last_sum[q[st]];
				sum[j]%=P;
//				cout<<j<<" "<<q.front()<<endl;
			}
//			for(ll i=1;i<=m;i++){
//				cout<<i<<" "<<dp[i]<<endl;
//			}
		}
	}
	for(ll i=1; i<=m; i++) {
		cout<<(sum[i]+P)%P<<" ";
	}
}
