#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll in_mine[N];
ll in_answer[N];
ll n,m,seed,max_v;
int main() {
	freopen("question.in","r",stdin);
	cin>>n>>m>>seed>>max_v;
	fclose(stdin);
	cin.clear();
	freopen("ans_answer.out","r",stdin);
	for(ll i=1; i<=m; i++) {
		cin>>in_answer[i];
	}
	fclose(stdin);
	cin.clear();
	freopen("ans_mine.out","r",stdin);
	for(ll i=1; i<=m; i++) {
		cin>>in_mine[i];
//		cout<<in_mine[i]<<endl;
	}
	fclose(stdin);
	cin.clear();
	bool flag=0;
	for(ll i=1; i<=n; i++) {
//		cout<<in_mine[i]<<" "<<in_answer[i]<<endl; 
		if(in_mine[i]!=in_answer[i]) {
			cout<<"An incorrect answer was detected on line "<<i<<", which should be "<<in_answer[i]<<" but is actually "<<in_mine[i]<<"."<<endl;
			flag=1;
		}
	}
	if(!flag) {
		cout<<"No line is wrong"<<endl;
	}
	Sleep(10000);
}
