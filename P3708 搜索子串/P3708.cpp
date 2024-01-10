#pragma loop_opt(on)
#pragma GCC optimize(2)
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
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
string ask,ark;
ll tot=0;
ll pr;
map<string,ll>m;
int main() {
//	freopen("TestData005.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	pr=(1<<(3*n));
	ask.resize((ll)(4e6+10));
	cin>>ask;
	ark.resize(n*2);
	for(ll i=0; i<n; i++) {
		ark[i]=ask[i];
	}
	if(!m[ark])m[ark]=++tot;
	for(ll i=n; i<ask.size(); i++) {
//		ark.clear();
		for(ll j=0; j<n-1; j++) {
			ark[j]=ark[j+1];
		}
		ark[n-1]=ask[i];
		if(!m[ark])m[ark]=++tot;
		if(tot>pr)break;
//		cout<<ark<<endl;
	}
	cout<<tot<<endl;
}
