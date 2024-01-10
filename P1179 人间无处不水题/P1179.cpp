#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[50],f[50],n_num;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j)continue;
			if(a[i]%a[j]==0)f[i]++; 
		}
	}
	for(ll i=1;i<=n;i++){
		if(f[i]>=2)n_num++;
	}
	if(n_num%5==0&&n_num!=0)n_num--;
	cout<<n_num<<endl;
}
