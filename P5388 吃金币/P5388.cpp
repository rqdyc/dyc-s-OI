#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,x;
ll a[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=x;
	ll ans=abs(a[2]-a[1]);
	for(ll i=3;i<=n+1;i++){
		ans=__gcd(ans,abs(a[i]-a[i-1]));
	}
	cout<<ans<<endl;
}
