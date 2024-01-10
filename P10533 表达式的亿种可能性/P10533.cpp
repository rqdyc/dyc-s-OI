#pragma loop_opt(on)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("sse")
#pragma GCC target("f16c")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("sse4")
#pragma GCC target("ssse3")
#pragma GCC target("popcnt")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC target("tune=native")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC diagnostic error "-std=c++14"
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=1e9+7;
const ll N=510;
ll n;
ll a[N];
char opt[N];
ll dp[N][N];
ll fact[N];
ll invfact[N];
ll qpow(ll a_,ll n_,ll p_) {
	ll ans_=1;
	a_%=p_;
	while(n_) {
		if(n_&1)ans_=ans_*a_%p_;
		n_>>=1;
		a_=a_*a_%p_;
	}
	return (ans_+p_)%p_;
}
ll optor(ll i,ll l,ll j) {
	ll x=dp[i][l],y=dp[l+1][j];
	if(opt[l]=='+') {
		return (x*fact[j-l-1]%P+y*fact[l-i]%P)%P;
	}
	if(opt[l]=='*') {
		return x*y%P;
	}
	if(opt[l]=='-') {
		return (x*fact[j-l-1]%P-y*fact[l-i]%P)%P;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	scanf("%lld",&n);
	fact[0]=1;
	for(ll i=1; i<=n; i++) {
		fact[i]=(fact[i-1]*i)%P;
	}
	invfact[0]=1;
	for(ll i=1; i<=n; i++) {
		invfact[i]=qpow(fact[i],P-2,P)%P;
	}
	for(ll i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		dp[i][i]=a[i];
	}
	scanf("%s",opt+1);
	for(ll k=2; k<=n; k++) {
		for(ll i=1; i<=n-k+1; i++) {
			ll j=i+k-1;
			for(ll l=i; l<j; l++) {
				dp[i][j]+=((optor(i,l,j)%P)*fact[k-2]%P*invfact[j-l-1]%P*invfact[l-i]%P)%P;
				dp[i][j]=(dp[i][j]+P)%P;
//				cout<<i<<" "<<l<<" "<<j<<" "<<dp[i][l]<<" "<<dp[l+1][j]<<" "<<opt[l]<<endl;
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<(dp[1][n]+P)%P;
}
