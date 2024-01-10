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
#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define ll unsigned long long
ll T,n,m;
ll ans=1e17;
char Map[50][50];
ll r[50];
ll t[(1<<24)+10];
bool flag=0;
void init() {
	flag=0;
	ans=1e17;
	memset(Map,0,sizeof(Map));
	memset(r,0,sizeof(r));
}
void dfs(ll x,ll bef,ll sum) {
	if(x>n) {
		ans=min(ans,max(n-sum,(ll)__builtin_popcount(bef)));
		return;
	}
	dfs(x+1,bef,sum);
	dfs(x+1,bef|r[x],sum+1);
	return;
}
int main() {
//	freopen("TestData001.in","r",stdin);
//	freopen("ans.out","w",stdout);
	scanf("%lld",&T);
	bool flagg=0;
	while(T--) {
		init();
		scanf("%lld%lld",&n,&m);
		for(ll i=1; i<=n; i++) {
			scanf("%s",Map[i]+1);
			for(ll j=1; j<=m; j++) {
				if(Map[i][j]=='*') {
					r[i]+=(1<<(j-1));
					flag=1;
				}
			}
		}
		if(!flag) {
			printf("0\n");
			continue;
		}
		dfs(1,0,0);
		printf("%lld\n",ans);
	}
}
