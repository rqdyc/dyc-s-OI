#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 10;
const ll M = 1e6 + 10;
string name;
ll id;
ll n, m, a, b;
struct node
{
    ll x, y, z;
} e[M];
ll tot = 0;
void add(ll x, ll y, ll z)
{
    tot++;
    e[tot].x = x;
    e[tot].y = y;
    e[tot].z = z;
}
void ques1()
{

}
void ques2()
{
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> name >> id;
    cin >> n >> m >> a >> b;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    if (id == 1 || id == 2)
    {
        ques1();
    }
}