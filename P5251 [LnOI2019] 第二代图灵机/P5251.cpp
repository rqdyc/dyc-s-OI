#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	ll l,r;
	mutable ll col;
	node(ll l,ll r=0,ll col=0):l(l),r(r),col(col) {}
	bool operator < (const node &a) const {
		return l<a.l;	
	}
};
set<node>s;
set<node>::iterator split(ll pos){
	set<node>::iterator it=s.lower_bound(node(pos));
	if(it!=s.end()&&(it->l)==pos){
		return it;
	}
	it--;
	if((it->r)<pos)return s.end();
	ll l=(it->l),r=(it->r),col=(it->col);
	s.erase(it);
	s.insert(node(l,pos-1,col));
	return s.insert(node(pos,r,col)).first;
}
void assign(ll,l,ll,r,ll col){
	set<node>::iterator itr=split(r+1),itl=split(l);
	s.erase(itl,itr);
	s.insert(node(l,r,col));
}

int main() {

}
