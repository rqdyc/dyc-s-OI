#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,p;
bool visit[11];
ll a[11];
ll ans=0;
void dfs(ll x){
	if(x==10){
		ll q=a[1]*100+a[2]*10+a[3],b=a[4]*100+a[5]*10+a[6],c=a[7]*100+a[8]*10+a[9];
//		cout<<q<<" "<<b<<" "<<c<<endl;
		if(b*n==q*m&&c*n==q*p){
			cout<<q<<" "<<b<<" "<<c<<endl;
			ans++;
		}
	}
	else{
		for(ll i=1;i<=9;i++){
			if(visit[i])continue;
			a[x]=i;
			visit[i]=1;
			dfs(x+1);
			visit[i]=0;
		}
	}
} 
int main(){
	cin>>n>>m>>p;
	dfs(1);
	if(!ans){
		cout<<"No!!!"<<endl;
	}
	return 0;
}
