#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll T=5e5+10;
ll m;
ll cnt[11];
bitset<T>dp;
ll ans=0;
void prt1() {
	for(ll i=m; i>=0; i--) {
//		cout<<i<<" ";
		if(dp[i]) {
			cout<<ans+i<<endl;
			break;
		}
	}
}
int main() {
	cin>>m;
	for(ll i=1; i<=8; i++) {
		cin>>cnt[i];
	}
	ll crt,ttt,tr;
	for(ll crt=8; crt>=1; crt--) {
		if(cnt[crt]==0)continue;
		if(m<=2000)break;
//		cout<<(ll)((m-200000)/(9-crt))*(9-crt)<<" ";
		tr=(ll)((m-2000)/(crt));
		if(tr<(cnt[crt]-1)) {
			cnt[crt]-=tr;
			m-=tr*crt;
			ans+=tr*crt;
		} else {
			m-=((cnt[crt]-1)*crt);
			ans+=(cnt[crt]-1)*crt;
			cnt[crt]=1;
		}
//		cout<<cnt[crt]<<" "<<m<<" "<<ans<<endl;
//		cout<<m<<endl;
	}
	for(ll i=1; i<=8; i++) {
		cout<<cnt[i]<<" ";
	}
//	cout<<m<<endl;
	ll v,c;
	dp[0]=1;
	ll Max=0;
	for(ll i=1; i<=8; i++) {
		if(cnt[i]==0)continue;
		v=i,c=cnt[i];
		c=min(c,(m-Max)/v);
//		cout<<c<<endl;
//		cout<<c<<endl;
		for(ll j=1; j<=c; j++) {
			dp|=(dp<<i);
			dp[i]=1;
//			cout<<1<<endl;
		}
		for(ll j=m; j>=1; j--) {
			if(dp[i]) {
				Max=i;
				break;
			}
		}
	}
//	cout<<1<<endl;
	bool flag=0;
//	if(m>2000)cout<<ans<<endl;
//	else prt1();
	for(ll i=1; i<=8; i++) {
		if(cnt[i]>1) {
			prt1();
			flag=1;
			break;
		}
	}
//	cout<<1<<endl;
//	cout<<dp[2000]<<endl;
	if(!flag)cout<<ans+1+2+3+4+5+6+7+8<<endl;
	return 0;
}
