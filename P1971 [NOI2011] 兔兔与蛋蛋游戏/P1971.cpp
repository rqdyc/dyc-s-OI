//二分图博弈 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=80; 
ll n,m;
struct node{
	ll x,y,next;
}e[N*N*2];
ll gethash(ll x,ll y){
	return (x-1)*m+y;
}
ll tot;
ll link[N*N*2];
ll elast[N*N*2];
ll del[N*N*2];
ll ans[1010]; 
ll rans[1010];
bool visit[N*N*2];
void add(ll x,ll y){
	tot++;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].next=elast[x];
	elast[x]=tot;
}
bool hungarian(ll id){
	ll x=id,y;
	visit[x]=1;
	for(ll i=elast[x];i;i=e[i].next){
		y=e[i].y;
		if(visit[y]||del[y])continue;
		visit[y]=1;
		if(!link[y]||hungarian(link[y])){
			link[y]=x;
			link[x]=y;
			return 1;
		}
	}
	return 0;
}
ll k;
char Map[N][N];
void init(){
	memset(visit,0,sizeof(visit));
}
ll x,y;//空格位置 
void solve(ll id){
	ll pointt=gethash(x,y);
	del[pointt]=1;
	if(link[pointt]==0){
		ans[id]=0;
	}
	else{
		ll point2=link[pointt];
		link[point2]=link[pointt]=0;
		init();
		if(hungarian(point2))ans[id]=0;
		else ans[id]=1;
	}
	cin>>x>>y;
	return;
}
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%s",Map[i]+1);
		for(ll j=1;j<=m;j++){
			if(Map[i][j]=='.'){
				x=i;
				y=j;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(Map[i][j]=='O')continue;
			if(i!=1&&Map[i-1][j]=='O'){//X/.连O 
				add(gethash(i,j),gethash(i-1,j));
				add(gethash(i-1,j),gethash(i,j));
			}
			if(i!=n&&Map[i+1][j]=='O'){
				add(gethash(i,j),gethash(i+1,j));
				add(gethash(i+1,j),gethash(i,j));
			}
			if(j!=1&&Map[i][j-1]=='O'){
				add(gethash(i,j),gethash(i,j-1));
				add(gethash(i,j-1),gethash(i,j));
			}
			if(j!=m&&Map[i][j+1]=='O'){
				add(gethash(i,j),gethash(i,j+1));
				add(gethash(i,j+1),gethash(i,j));
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(Map[i][j]!='O')continue;
			init();
			hungarian(gethash(i,j));
		}
	}
	cin>>k;
	ll cnt=0;
	for(ll i=1;i<=2*k;i++){
//		cout<<x<<" "<<y<<" "<<i<<endl;
		solve(i);
//		cout<<x<<" "<<y<<" "<<i<<" "<<ans[i]<<endl;
		if(i%2==0&&ans[i]==1&&ans[i-1]==1){
			cnt++;
			rans[cnt]=i/2;
		}
	}
	printf("%lld\n",cnt);
	for(ll i=1;i<=cnt;i++){
		printf("%lld\n",rans[i]);
	}
}
