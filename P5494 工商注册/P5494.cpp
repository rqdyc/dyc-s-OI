#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll>m1;
string ask;
ll tot=0;
ll n,m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>ask;
		if(!m1[ask]){
			m1[ask]=++tot;
		}
	}
	for(ll i=1;i<=m;i++){
		cin>>ask;
		if(!m1[ask]){
			cout<<"YES\n";
			m1[ask]=++tot;
		}
		else{
			cout<<"NO\n";
		}
	}
}
