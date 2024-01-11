#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll op,x;
priority_queue<ll,vector<ll>,greater<ll> >q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>x;
			q.push(x);
		}
		if(op==2){
			cout<<q.top()<<endl;
		}
		if(op==3){
			q.pop();
		}
	}
	return 0;
}
