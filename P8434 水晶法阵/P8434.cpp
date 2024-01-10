#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=33;
ll n;
ll ans;
struct point {
	ll x,y,id;
} Point[N];
struct edge {
//	point a,b;
	long double dr;
} Edge[N*N];
bool visit[N];
void add(ll sum,point a,point b) {
	if(a.x>b.x) {
		swap(a,b);
	}
//	Edge[sum].a=a;
//	Edge[sum].b=b;
	Edge[sum].dr=(long double)(b.y-a.y)/(long double)(b.x-a.x);
}
ll summ=0; 
void dfs(ll x,ll y) {
	if(y>n/2) {
		summ=0;
		for(ll i=1;i<y;i++){
			for(ll j=i+1;j<y;j++){
				if(Edge[i].dr==Edge[j].dr)summ++;
			}
		}
		ans=max(ans,summ);
//		for(ll i=1;i<y;i++){
//			cout<<Edge[i].a.id<<" "<<Edge[i].b.id<<endl;
//		}
//		cout<<endl;
//		cout<<s<<endl;
		return;
	}
	while(visit[x])x++;
	for(ll i=x+1; i<=n; i++) {
		if(!visit[i]) {
			if(x!=0) {
				add(y,Point[x],Point[i]);
				visit[i]=visit[x]=1;
			}
//			cout<<x<<" "<<i<<endl;
			dfs(x+1,y+1);
			visit[i]=visit[x]=0;
			Edge[y].dr=0;
		}
	}
	return;
}
int main() {
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//  13 20
	cin>>n;
	if(n<=3) {
		cout<<0<<endl;
		return 0;
	}
	for(ll i=1; i<=n; i++) {
		scanf("%lld%lld",&Point[i].x,&Point[i].y);
		Point[i].id=i;
	}
	dfs(0,0);
	cout<<ans<<endl;
//	for(ll i=1; i<=n; i++) {
//		printf("%lld %lld\n",Point[i].x,Point[i].y);
//	}
	return 0;
}
/*
 test data 1
12
-5 -3
3 2
1 -3
4 -1
-5 -2
-4 -5
3 5
-3 4
2 -4
-3 3
1 2
-4 5
*/
