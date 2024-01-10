#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 10;
struct tree
{
    ll l, r, l1_1, l1_0, r1_1, r1_0, sum, max1, max0, lazy;
} Tree[N * 16];
ll n, m;
ll a[N];
ll flag, a_, b_;
ll change(ll a, ll b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (a == 0)
    {
        if (b == 0)
            return 0;
        if (b == 1)
            return 1;
        if (b == 2)
            return 1;
    }
    if (a == 1)
    {
        if (b == 0)
            return 0;
        if (b == 1)
            return 1;
        if (b == 2)
            return 0;
    }
    if (a == 2)
    {
        if (b == 0)
            return 0;
        if (b == 1)
            return 1;
        if (b == 2)
            return -1;
    }
}
void up(ll id)
{
    Tree[id].sum = Tree[id * 2].sum + Tree[id * 2 + 1].sum;
    if (Tree[id * 2].l1_1 < Tree[id * 2].r - Tree[id * 2].l + 1)
        Tree[id].l1_1 = Tree[id * 2].l1_1;
    else
        Tree[id].l1_1 = Tree[id * 2].l1_1 + Tree[id * 2 + 1].l1_1;
    if (Tree[id * 2 + 1].r1_1 < Tree[id * 2 + 1].r - Tree[id * 2 + 1].l + 1)
        Tree[id].r1_1 = Tree[id * 2 + 1].r1_1;
    else
        Tree[id].r1_1 = Tree[id * 2 + 1].r1_1 + Tree[id * 2].r1_1;
    Tree[id].max1 = max(Tree[id * 2 + 1].max1, max(Tree[id * 2].max1, Tree[id * 2].r1_1 + Tree[id * 2 + 1].l1_1));
    if (Tree[id * 2].l1_0 < Tree[id * 2].r - Tree[id * 2].l + 1)
        Tree[id].l1_0 = Tree[id * 2].l1_0;
    else
        Tree[id].l1_0 = Tree[id * 2].l1_0 + Tree[id * 2 + 1].l1_0;
    if (Tree[id * 2 + 1].r1_0 < Tree[id * 2 + 1].r - Tree[id * 2 + 1].l + 1)
        Tree[id].r1_0 = Tree[id * 2 + 1].r1_0;
    else
        Tree[id].r1_0 = Tree[id * 2 + 1].r1_0 + Tree[id * 2].r1_0;
    Tree[id].max0 = max(Tree[id * 2 + 1].max0, max(Tree[id * 2].max0, Tree[id * 2].r1_0 + Tree[id * 2 + 1].l1_0));
    // cout<<id<<" "<<Tree[id].l<<" "<<Tree[id].r<<" "<<Tree[id].l1_1<<" "<<Tree[id].r1_1<<" "<<Tree[id].max1<<endl;
}
void down(ll id)
{
    if (Tree[id].l == Tree[id].r)
        return;
    Tree[id * 2].lazy = change(Tree[id * 2].lazy, Tree[id].lazy);
    Tree[id * 2 + 1].lazy = change(Tree[id * 2 + 1].lazy, Tree[id].lazy);
    /*
    if(Tree[id*2].lazy==-1&&Tree[id*2+1].lazy==-1){
        Tree[id*2].lazy=Tree[id*2+1].lazy=Tree[id].lazy;
    }
    */
    // shift
    if (Tree[id].lazy != 2)
    {
        Tree[id * 2].sum = Tree[id * 2].max1 = Tree[id * 2].l1_1 = Tree[id * 2].r1_1 = (Tree[id * 2].r - Tree[id * 2].l + 1) * Tree[id].lazy;
        Tree[id * 2 + 1].sum = Tree[id * 2 + 1].max1 = Tree[id * 2 + 1].l1_1 = Tree[id * 2 + 1].r1_1 = (Tree[id * 2 + 1].r - Tree[id * 2 + 1].l + 1) * Tree[id].lazy;
        Tree[id * 2].max0 = Tree[id * 2].l1_0 = Tree[id * 2].r1_0 = (Tree[id * 2].r - Tree[id * 2].l + 1) * (1 - Tree[id].lazy);
        Tree[id * 2 + 1].max0 = Tree[id * 2 + 1].l1_0 = Tree[id * 2 + 1].r1_0 = (Tree[id * 2 + 1].r - Tree[id * 2 + 1].l + 1) * (1 - Tree[id].lazy);
    }
    else
    {
        Tree[id * 2].sum = (Tree[id * 2].r - Tree[id * 2].l + 1) - Tree[id * 2].sum;
        swap(Tree[id * 2].max1, Tree[id * 2].max0);
        swap(Tree[id * 2].l1_1, Tree[id * 2].l1_0);
        swap(Tree[id * 2].r1_1, Tree[id * 2].r1_0);
        Tree[id * 2 + 1].sum = (Tree[id * 2 + 1].r - Tree[id * 2 + 1].l + 1) - Tree[id * 2 + 1].sum;
        swap(Tree[id * 2 + 1].max1, Tree[id * 2 + 1].max0);
        swap(Tree[id * 2 + 1].l1_1, Tree[id * 2 + 1].l1_0);
        swap(Tree[id * 2 + 1].r1_1, Tree[id * 2 + 1].r1_0);
    }
    Tree[id].lazy = -1;
}
void build(ll id, ll l, ll r)
{
    Tree[id].l = l;
    Tree[id].r = r;
    Tree[id].lazy = -1;
    if (l == r)
    {
        Tree[id].max1 = Tree[id].sum = Tree[id].l1_1 = Tree[id].r1_1 = a[l];
        Tree[id].max0 = Tree[id].l1_0 = Tree[id].r1_0 = 1 - a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    up(id);
}
void change1(ll id, ll l, ll r, ll x)
{
    if (Tree[id].lazy != -1)
        down(id);
    if (l <= Tree[id].l && Tree[id].r <= r)
    {
        Tree[id].lazy = change(Tree[id].lazy, x);
        Tree[id].max1 = Tree[id].l1_1 = Tree[id].r1_1 = Tree[id].sum = (Tree[id].r - Tree[id].l + 1) * x;
        Tree[id].max0 = Tree[id].l1_0 = Tree[id].r1_0 = (Tree[id].r - Tree[id].l + 1) * (1 - x);
        // cout<<Tree[id].l<<" "<<Tree[id].r<<" "<<Tree[id].l1<<endl;
        return;
    }
    ll mid = (Tree[id].l + Tree[id].r) / 2;
    if (l <= mid)
        change1(id * 2, l, r, x);
    if (r > mid)
        change1(id * 2 + 1, l, r, x);
    up(id);
}
void change2(ll id, ll l, ll r)
{
    if (Tree[id].lazy != -1)
        down(id);
    if (l <= Tree[id].l && Tree[id].r <= r)
    {
        Tree[id].lazy = change(Tree[id].lazy, 2);
        Tree[id].sum = (Tree[id].r - Tree[id].l + 1) - Tree[id].sum;
        swap(Tree[id].max1, Tree[id].max0);
        swap(Tree[id].l1_1, Tree[id].l1_0);
        swap(Tree[id].r1_1, Tree[id].r1_0);
        // cout<<Tree[id].l<<" "<<Tree[id].r<<" "<<Tree[id].l1<<endl;
        return;
    }
    ll mid = (Tree[id].l + Tree[id].r) / 2;
    if (l <= mid)
        change2(id * 2, l, r);
    if (r > mid)
        change2(id * 2 + 1, l, r);
    up(id);
}
ll GetSum1(ll id, ll l, ll r)
{
    if (Tree[id].lazy != -1)
        down(id);
    if (l <= Tree[id].l && r >= Tree[id].r)
    {
        // cout<<Tree[id].l<<" "<<Tree[id].r<<" "<<Tree[id].sum<<endl;
        return Tree[id].sum;
    }
    ll mid = (Tree[id].l + Tree[id].r) / 2, ans = 0;
    if (l <= mid)
        ans += GetSum1(id * 2, l, r);
    if (r > mid)
        ans += GetSum1(id * 2 + 1, l, r);
    // cout<<Tree[id].l<<" "<<Tree[id].r<<" "<<ans<<endl;
    return ans;
}
ll GetSum2(ll id, ll l, ll r)
{
    if (Tree[id].lazy != -1)
        down(id);
    if (l <= Tree[id].l && r >= Tree[id].r)
    {
        return Tree[id].max1;
    }
    ll mid = (Tree[id].l + Tree[id].r) / 2, sum = 0, sum1 = 0, sum2 = 0;
    if (l <= mid)
        sum = GetSum2(id * 2, l, r);
    if (r > mid)
        sum1 = GetSum2(id * 2 + 1, l, r);
    if (l <= Tree[id * 2].r && r >= Tree[id * 2 + 1].l)
    {
        ll len = Tree[id * 2].r - l + 1;
        ll len1 = r - Tree[id * 2 + 1].l + 1;
        ll res = min(Tree[id * 2].r1_1, len);
        ll res1 = min(Tree[id * 2 + 1].l1_1, len1);
        sum2 = res + res1;
    }
    return max(sum, max(sum1, sum2));
}
/*
void prt(ll id,ll l,ll r){
    if(l==r){
        cout<<Tree[id].l<<" "<<Tree[id].r<<" "<<Tree[id].sum<<endl;
        //if(Tree[id].l1<=0)Tree[id].l1=0;
        //if(Tree[id].r1<=0)Tree[id].r1=0;
        return;
    }
    ll mid=(l+r)/2;
    prt(id*2,l,mid);
    prt(id*2+1,mid+1,r);
    cout<<Tree[id].l<<" "<<Tree[id].r<<" "<<Tree[id].sum<<endl;
}
*/
int main()
{
    // freopen("sb.txt","w",stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--)
    {
        cin >> flag >> a_ >> b_;
        a_++;
        b_++;
        if (flag == 0)
        {
            change1(1, a_, b_, 0);
        }
        if (flag == 1)
        {
            change1(1, a_, b_, 1);
        }
        if (flag == 2)
        {
            change2(1, a_, b_);
        }
        if (flag == 3)
        {
            cout << GetSum1(1, a_, b_) << endl;
        }
        if (flag == 4)
        {
            cout << GetSum2(1, a_, b_) << endl;
        }
        // cout<<n-m<<"st"<<endl;
        // prt(1,1,n);
        // cout<<endl;
    }
}