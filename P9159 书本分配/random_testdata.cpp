#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5,amax=1e9;
ll n,m;
int main() {
	freopen("Testdata001.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	mt19937 rnd(time(NULL));
	n=N;
	m=n-(rnd()%n);
	cout<<n<<" "<<m<<endl;
	for(ll i=1;i<=n;i++){
		cout<<(rnd()%amax+1)*((ll)pow(-1,rnd()%114))<<" ";
	}
	return 0;
}
