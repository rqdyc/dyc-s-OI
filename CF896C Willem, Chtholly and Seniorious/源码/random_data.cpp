#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("question.in","w",stdout);
	random_device rd;
	uniform_int_distribution<ll>dist(1,100000);
	mt19937 rnd(dist(rd));
	cout<<(rnd()%100000)+1<<" "<<(rnd()%100000)+1<<" "<<(rnd()%1000000000)+1<<" "<<(rnd()%1000000000)+1;
} 
