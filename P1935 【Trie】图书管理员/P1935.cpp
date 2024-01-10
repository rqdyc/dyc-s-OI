#include<bits/stdc++.h>
using namespace std;
#define ll long long
char ques;
string ask;
ll tot=0;
map<string,ll>s;
ll n;
int main() {
//	freopen("TestData002.in","r",stdin);
//	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		ask.clear();
		cin>>ques>>ask;
		if(ques=='A') {
			s[ask]++;
		}
		if(ques=='B') {
			s[ask]--;
			s[ask]=max(0ll,s[ask]);
		}
		if(ques=='C') {
			if(s[ask]!=0) {
				printf("yes\n");
			} else printf("no\n");
		}
	}
}
