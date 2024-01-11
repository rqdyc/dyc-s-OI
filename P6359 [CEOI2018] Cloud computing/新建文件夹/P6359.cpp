#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e3+10;
const ll inf=-1e15;
ll n,m;
struct node {
	ll c,f,w;
	bool operator<(const node& a)const {
		if(a.f==f)return w<a.w;
		return f>a.f;
	}
} e[N];
ll dp[N<<5];
ll core_num;
ll ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ans=inf;
	cin>>n;
//	cout<<n<<endl;
	for(ll i=1; i<=n; i++) {
//		cout<<dp[i]<<endl;
		cin>>e[i].c>>e[i].f>>e[i].w;
		e[i].w=-e[i].w;
	}
	cin>>m;
	for(ll i=n+1; i<=m+n; i++) {
		cin>>e[i].c>>e[i].f>>e[i].w;
	}
	sort(e+1,e+n+m+1);
	for(ll i=1; i<=n+m; i++) {
		if(e[i].w<0) {
			for(ll j=core_num+1; j<=core_num+e[i].c; j++) {
				dp[j]=inf;
			}
			for(ll j=core_num; j>=0; j--) {
				dp[j+e[i].c]=max(dp[j+e[i].c],dp[j]+e[i].w);
			}
			core_num+=e[i].c;
		} else {
			for(ll j=0; j<=core_num-e[i].c; j++) {
				dp[j]=max(dp[j],dp[j+e[i].c]+e[i].w);
			}
		}
	}
	for(ll i=0; i<=core_num; i++) {
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
