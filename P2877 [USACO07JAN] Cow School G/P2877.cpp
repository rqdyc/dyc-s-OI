#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5010;
ll n;
struct node{
	ll t,p;
	long double r;
}s[N];
bool cmp(node a,node b){
	return a.r<b.r;
}
ll t[N],p[N];
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s[i].t>>s[i].p;
		s[i].r=t[i]/p[i];
	}
	sort(s+1,s+n+1);
}
