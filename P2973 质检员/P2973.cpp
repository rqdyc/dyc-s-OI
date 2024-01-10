#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
ll n,m;
ll input[N];
ll stdd[N];
ll ans[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=0; i<n; i++) {
		cin>>input[i];
	}
	ll a=0,b=1,c=0;
	while(a<n&&b<n&&c<n) {
		if(input[(a+c)%n]==input[(b+c)]%n) {
			c++;
		} else {
			if(input[(a+c)%n]>input[(b+c)%n]) {
				a=a+c+1;
			} else {
				b=b+c+1;
			}
			if(a==b) {
				a++;
			}
			c=0;
		}
	}
	a=min(a,b);
//	cout<<a<<endl;
	for(ll i=a; i<=a+n-1; i++) {
		stdd[i-a+1]=input[i%n];
	}
	for(ll k=1; k<=m; k++) {
		for(ll i=0; i<n; i++) {
			cin>>input[i];
		}
		a=0,b=1,c=0;
		while(a<n&&b<n&&c<n) {
			if(input[(a+c)%n]==input[(b+c)%n]) {
				c++;
			} else {
				if(input[(a+c)%n]>input[(b+c)%n]) {
					a=a+c+1;
				} else {
					b=b+c+1;
				}
				if(a==b) {
					a++;
				}
				c=0;
			}
		}
		a=min(a,b);
		for(ll i=a; i<=a+n-1; i++) {
			ans[k][i-a+1]=input[i%n];
			if(ans[k][i-a+1]!=stdd[i-a+1]) {
				cout<<k<<" ";
				break;
			}
		}
	}
}
