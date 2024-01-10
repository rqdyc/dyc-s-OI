#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<iostream>
using namespace std;
#define ll long long
void put(ll x) {
	if(x<0)putchar('-'),x=-x;
	if(x>9)put(x/10);
	putchar(x%10+'0');
}
constexpr ll N=2e5+10;
constexpr ll INF=1145141919810;
ll n,m;
ll a[N];
ll sum[N];
ll dp[N];
ll c[N];
ll tot=0;
ll lowbit(ll x) {
	return x&(-x);
}
void modify(ll x,ll val) {
	x=tot-x;
	if(x==0) {
		c[0]=max(c[0],val);
		return;
	}
	for(ll j=x; j<=tot; j+=lowbit(j)) {
		c[j]=max(c[j],val);
	}
}
ll getmax(ll x) {
	x=tot-x;
	if(x==0) {
		return c[0];
	}
	ll ans=-INF;
	for(ll j=x; j>0; j-=lowbit(j)) {
		ans=max(ans,c[j]);
	}
	return ans;
}
ll ww[N];
ll ww2[N];
unordered_map<ll,ll>mm;
int main() {
	freopen("Testdata010.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		ww[i]=sum[i];
	}
	sort(ww,ww+n+1);
	ll len=unique(ww,ww+n+1)-ww+1;
	cout<<len<<endl;
	for(ll i=0; i<=len; i++) {
		tot++;
		mm[ww[i]]=tot;
	}
	ll l=-1e9,r=1e9,mid;
	while(l<=r) {
		for(ll i=0; i<=n; i++) {
			c[i]=dp[i]=-INF;
		}
		mid=l+(r-l)/2;
		bool flagg=0;
		dp[0]=0;
		modify(mm[0],dp[0]);
		for(ll i=1; i<=n; i++) {
			if(sum[i]-mid>ww[n]) {
				dp[i]=-INF;
			} else {
				ll wes=*lower_bound(ww,ww+len+1,sum[i]-mid);
				dp[i]=getmax(mm[wes])+1;
			}
			modify(mm[sum[i]],dp[i]);
			if(dp[i]>=m) {
				flagg=1;
				break;
			}
		}
		if(flagg) {
			r=mid-1;
		} else {
			l=mid+1;
		}
//		put((ll)(clock()));
//		puts("");
	}
//	put((ll)(clock()));
//	puts("");
	cout<<l<<"\n";
	return 0;
}
