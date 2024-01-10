#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
ll n,m;
string ask;
map<string,ll>m1;
ll q2[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	while(n!=0&&m!=0) {
		m1.clear();
		memset(q2,0,sizeof(q2));
		for(ll i=1; i<=n; i++) {
			cin>>ask;
			m1[ask]++;
			q2[m1[ask]-1]--;
			q2[m1[ask]]++;
		}
		for(ll i=1; i<=n; i++) {
			cout<<q2[i]<<"\n";
		}
		cin>>n>>m;
	}
	return 0;
}
