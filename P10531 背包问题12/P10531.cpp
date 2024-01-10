#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll t;
ll n,m;
ll v[N],w[N];
ll dp[N][N*1000];
ll tot=0;
void init() {
	memset(dp,0,sizeof(dp));
	memset(v,0,sizeof(v));
	memset(w,0,sizeof(w));
}
int main() {
//	freopen("P10531.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		tot=0;
		init();
		cin>>n>>m;
		map<ll,ll>m1,m2;
//		m1[m]=++tot;
//		m2[tot]=m;
		for(ll i=1; i<=n; i++) {
			cin>>v[i]>>w[i];
//			m1[v[i]]=++tot;
//			m2[tot]=v[i];
		}
		ll rp;
		for(ll i=1; i<=n; i++) {
			rp=tot;
			for(ll j=1; j<=rp; j++)dp[i][j]=dp[i-1][j];
			for(ll j=rp; j>=0; j--) {
				if(m1[m2[j]]||!j) {
					if(!m1[m2[j]+v[i]]&&(m2[j]+v[i])<=m) {
						m1[m2[j]+v[i]]=++tot;
						m2[tot]=m2[j]+v[i];
						dp[i][tot]=max(dp[i-1][tot],dp[i-1][j]+w[i]);
//						cout<<m2[tot]<<endl;
					}
//					cout<<i<<" "<<tot<<" "<<dp[i][tot]<<" "<<m2[tot]<<endl;
				}
			}
		}
		ll ans=-1;
		for(ll i=1; i<=tot; i++) {
//			cout<<m2[i]<<" "<<dp[n][i]<<endl;
			if(m2[i]<=m)ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
}
