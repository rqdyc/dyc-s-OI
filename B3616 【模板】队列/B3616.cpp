#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll op,x;
queue<ll>q;
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
			if(q.empty()){
				cout<<"ERR_CANNOT_POP"<<endl;
			}
			else{
				q.pop();
			}
		}
		if(op==3){
			if(q.empty()){
				cout<<"ERR_CANNOT_QUERY"<<endl;
			}
			else{
				cout<<q.front()<<endl;
			}
		}
		if(op==4){
			cout<<q.size()<<endl;
		}
	}
}
