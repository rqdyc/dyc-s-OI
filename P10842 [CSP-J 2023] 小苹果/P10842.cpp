#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
bool flag=0;
ll days=0;
ll data=0;
int main() {
	cin>>n;
	while(n) {
		data++;
		if(n%3==1&&!flag) {
			days=data;
			flag=1;
		}
		n-=(n/3+(n%3!=0));
//		cout<<data<<" "<<n<<endl;
	}
	cout<<data<<" "<<days<<endl;
}
