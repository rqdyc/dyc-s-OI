#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=1e5;
const ll N=11,M=11;
const ll amax=1e13;
ll n,m;
ll a[N];
int main() {
	freopen("testdata001.in","w",stdout);
	mt19937 rnd(time(NULL));
	n=(N*80/100+rnd()%(N-N*80/100+1)),m=(N*80/100+rnd()%(N-N*80/100+1));
	cout<<n<<" "<<m<<"\n";
	for(ll i=1; i<=n; i++) {
		a[i]=(rnd()|(rnd()<<9))%amax;
		if(i!=1) {
			cout<<" ";
		}
		cout<<a[i];
	}
	cout<<"\n";
	ll op,rt,l,r,qq;
	for(ll i=1; i<=m; i++) {
		op=rnd()%2;
		if(op%2==1) {
			cout<<"A ";
			rt=rnd()%4+1;
			l=rnd()%n+1;
			r=rnd()%n+1;
			if(r<l)swap(l,r);
			if(rt==3||rt==4){
				qq=rnd()%P+1;
			}
			else{
				qq=rnd()%amax+1; 
			}
			cout<<rt<<" "<<l<<" "<<r<<" "<<qq<<"\n";
		} else {
			cout<<"Q ";
			rt=rnd()%4+1;
			l=rnd()%n+1;
			r=rnd()%n+1;
			if(r<l)swap(l,r);
			cout<<rt<<" "<<l<<" "<<r<<"\n";
		}
	}
	fclose(stdout);
}
