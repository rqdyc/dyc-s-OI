#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n;
struct person {
	ll a,t,id;
} a[N],b[N];
bool cmp1(person a,person b) {
	if(a.a==b.a)return a.id<b.id;
	return a.a<b.a;
}
ll times=0;
ll ans=-1;
bool visit[N];
int main() {
//	freopen("P5120_2.in","r",stdin);
//	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i].a>>a[i].t;
		b[i].a=a[i].a;
		b[i].t=a[i].t;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	priority_queue<ll,vector<ll>,greater<ll> >q;
	q.push(a[1].id);
	times=b[q.top()].a;
	ll id=2;
	while(!q.empty()||id<n) {
		visit[q.top()]=1;
		if(q.empty()){
//			id++;
			times=a[id].a;
			q.push(a[id].id);
			continue;
		}
//		cout<<q.top()<<endl;
		times=max(times,b[q.top()].a);
		ans=max(ans,times-b[q.top()].a);
		times+=b[q.top()].t;
		q.pop();
//		cout<<times<<"\n";
		for(; id<=n&&a[id].a<=times; id++) {
//			cout<<a[id].id<<" ";
			if(!visit[a[id].id])q.push(a[id].id);
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
}
