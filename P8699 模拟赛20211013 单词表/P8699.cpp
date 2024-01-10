#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll a[N];
ll st[N];
ll n,w;
ll Log[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout<<sizeof(st)<<endl;
	cin>>n>>w;
	Log[1]=0,Log[2]=1;
	for(ll i=3; i<N; i++) {
		Log[i]=Log[i/2]+1;
	}
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		st[i]=a[i];
	}
	ll ans=0,tot=0;
	for(ll s=1; s<=n; s++) {
		ans=(n/s)+(n%s!=0)-1;
		if(Log[s-1]!=Log[s]&&s!=1) {
			tot++;
			for(ll i=1; i<=n; i++) {
				st[i]=max(st[i],st[i+(1<<(tot-1))]);
			}
		}
		for(ll i=1; i<=n; i+=s) {
			ll rt=Log[s];
//			cout<<i<<" "<<(i+s-1)<<" "<<max(st[i],st[(i+s-1)-(1<<rt)+1])<<endl;
			ans+=max(st[i],st[(i+s-1)-(1<<rt)+1]);
		}
//		cout<<s<<" "<<ans<<" "<<w<<endl;
		if(ans<=w) {
			cout<<s<<endl;
			break;
		}
	}
	return 0;
}
