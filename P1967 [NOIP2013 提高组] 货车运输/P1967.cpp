#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
const ll M=5e5+10;
ll num=0,n,m,xxx,yyy,zzz;
struct node {
	ll x,y,z;
} e[M],f[M];
map<pair<ll,ll>,ll>mm;
bool operator < (node a,node b) {
	return a.z>b.z;
}
void add(ll xx,ll yy,ll zz,ll num) {
	e[num].x=xx;
	e[num].y=yy;
	e[num].z=zz;
	mm[make_pair(xx,yy)]=zz;
	mm[make_pair(yy,xx)]=zz;
}
void add2(ll xx,ll yy,ll zz,ll num) {
	f[num].x=xx;
	f[num].y=yy;
	f[num].z=zz;
}
ll father[N];
ll getfather(ll i) {
	return father[i]==i?i:father[i]=getfather(father[i]);
}
void Merge(ll x,ll y) {
	ll fx=getfather(x);
	ll fy=getfather(y);
	if(fx!=fy) {
		father[fx]=fy;
	}
}
ll cntt=0;
ll ff[N][50];
ll Map[N][50];
ll depth[M];
bool mark[M];
ll last[M],nextt[M],endd[M],len[M];
void dfs(ll x) {
	mark[x]=true;
	ll a,xx;
	depth[x]=depth[ff[x][0]]+1;
	a=ceil(log(depth[x])/log(2));
	for(ll i=1; i<=a; i++) {
		ff[x][i]=ff[ff[x][i-1]][i-1];
		Map[x][i]=min(Map[x][i-1],Map[ff[x][i-1]][i-1]);
	}
	xx=last[x];
	while(xx!=0) {
		if(mark[endd[xx]]==false) {
			ff[endd[xx]][0]=x;
			Map[endd[xx]][0]=len[xx];
			dfs(endd[xx]);
		}
		xx=nextt[xx];
	}
}
ll lca(ll x,ll y) {
	ll e;
	ll ans=1e9;
	if(depth[x]>depth[y]) {
		swap(x,y);
	}
	e=ceil(log(n)/log(2));
	ll k=depth[y]-depth[x];
	for(ll i=0; i<=e; i++) {
		if(k&(1<<i)) {
			ans=min(ans,Map[y][i]);
			//cout<<ans<<endl;
			y=ff[y][i];
		}
	}
	if(x==y)return ans;
	e=ceil(log(depth[x])/log(2));
	for(ll i=e; i>=0; i--) {
		if(ff[x][i]!=ff[y][i]) {
			ans=min(Map[x][i],ans);
			//cout<<ans<<endl;
			x=ff[x][i];
			ans=min(Map[y][i],ans);
			//cout<<ans<<endl;
			y=ff[y][i];
		}
	}
	ans=min(ans,Map[x][0]);
	//cout<<ans<<endl;
	ans=min(ans,Map[y][0]);
	//cout<<ans<<endl;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		father[i]=i;
	}
	for(ll i=1; i<=m; i++) {
		cin>>xxx>>yyy>>zzz;
		add(xxx,yyy,zzz,i);
	}
	sort(e+1,e+1+m);
	ll num=0;
	for(ll i=1,cnt=0; i<=m&&cnt<n-1; i++) {
		ll u=e[i].x,v=e[i].y,w=e[i].z;
		if(getfather(father[u])!=getfather(father[v])) {
			cnt++;
			Merge(u,v);
			add2(u,v,w,++num);
		}
	}
	for(ll i=1; i<=num; i++) {
		ll x=f[i].x,y=f[i].y,z=f[i].z;
		cntt++;
		endd[cntt]=y;
		len[cntt]=z;
		nextt[cntt]=last[x];
		last[x]=cntt;
		cntt++;
		endd[cntt]=x;
		len[cntt]=z;
		nextt[cntt]=last[y];
		last[y]=cntt;
	}
	dfs(1);
	cin>>m;
	for(ll i=1; i<=m; i++) {
		ll x,y;
		cin>>x>>y;
		ll anss=lca(x,y);
		if((anss==1e9||anss==0)&&!mm[make_pair(x,y)]) {
			cout<<-1<<endl;
		} else if(anss==1e9||anss==0) {
			cout<<mm[make_pair(x,y)]<<endl;
		} else {
			cout<<anss<<endl;
		}
	}
}
