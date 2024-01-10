#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
char a1[15],a2[15];
string ask[N];
string ark[N];
ll tot=1;
map<string,ll>m;
struct node {
	ll l,r,id;
} v[N*2];
bool cmp(node a,node b) {
	return a.r<b.r;
}
ll summ=0;
int main() {
//	freopen("input.in","r",stdin);
	while(scanf("%s %s",a1,a2)!=EOF) {
		ask[tot]=a1;
		ark[tot]=a2;
		tot++;
	}
	tot--;
	mt19937 rnd(time(NULL));
	for(ll i=1; i<=tot; i++) {
//		cout<<ask[i]<<" "<<ark[i]<<endl;
		m[ask[i]]=m[ask[i]]==0?rnd():m[ask[i]];
		v[i].l=m[ask[i]];
		m[ark[i]]=m[ark[i]]==0?abs(rnd()):m[ark[i]];
		v[i].r=-m[ark[i]];
		v[i].id=i;
		summ+=(m[ask[i]]+m[ark[i]]);
	}
	for(ll i=tot+1; i<=tot*2; i++) {
		v[i].l=-v[i-tot].r;
		v[i].r=-v[i-tot].l;
		v[i].id=i;
	}
	tot*=2;
	sort(v+1,v+tot+1,cmp);
//	for(ll i=1; i<=tot; i++) {
//		cout<<v[i].l<<" "<<v[i].r<<" "<<v[i].id<<endl;
//	}
	ll l,r,mid;
	bool check=0;
//	cout<<summ<<endl;
	for(ll i=1; i<=tot&&!check; i++) {
//		cout<<v[i].l<<endl;
		l=1,r=tot;
		while(l<=r) {
			mid=(l+r)>>1;
//			cout<<v[i].id<<" "<<v[mid].id<<endl;
			if(summ-(v[mid].r+v[i].l)==0&&((v[i].id-tot/2)!=v[mid].id||(v[mid].id-tot/2)!=v[i].id)) {
				cout<<mid<<endl;
				check=1;
				break;
			} else if(summ-(v[mid].r+v[i].l)<0) {
				r=mid-1;
			} else {
				l=mid+1;
			}
		}
		if(summ-(v[l].r+v[i].l)==0&&((v[l].id-tot/2)!=v[i].id||(v[i].id-tot/2)!=v[l].id)) {
			check=1;
			break;
		}
	}
	if(check==1) {
		puts("Possible");
	} else {
		puts("Impossible");
	}
}
