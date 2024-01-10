#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll LEN=1e5+10;
ll L;
ll i,j,k;
char s[LEN];
int main() {
	cin>>L;
	for(ll ii=1; ii<=L/72+(L%72!=0); ii++) {
		scanf("%s",s+(ii-1)*72);
	}
//	printf("%s",s+1);
	i=0,j=1,k=0;
	while(i<L&&j<L&&k<L) {
		if(s[(i+k)%L]==s[(j+k)%L])k++;
		else {
			if(s[(i+k)%L]>s[(j+k)%L])i=i+k+1;
			else j=j+k+1;
			if(i==j)i++;
			k=0;
		}
	}
	cout<<min(i,j)<<endl;
}
