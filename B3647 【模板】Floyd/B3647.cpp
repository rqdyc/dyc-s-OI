#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll n,m;
ll Map[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			Map[i][j]=1145141919810;
		}
		Map[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		Map[x][y]=min(Map[x][y],z);
		Map[y][x]=min(Map[y][x],z);
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				Map[i][j]=min(Map[i][j],Map[i][k]+Map[k][j]);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<Map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
