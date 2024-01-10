#include <bits/stdc++.h>
using namespace std;
#define ll long long
mt19937 rnd(time(NULL));
const ll T = 200;
const ll N = 50;
struct node
{
    ll x, y, z;
    node(ll x = 0, ll y = 0, ll z = 0) : x(x), y(y), z(z) {}
};
bool operator<(node a, node b)
{
    if (a.x == b.x)
    {
        if (a.y == b.y)
        {
            return a.z < b.z;
        }
        return a.y < b.y;
    }
    return a.x < b.x;
}
map<node, bool> m;
const ll wmax = 10;
const ll dmax = 1e6;
ll _rand(ll l, ll r)
{
    return (ll)(pow(-1, rnd() % 2)) * rnd() % (r - l) + l;
}
int main()
{
    freopen("11.in", "w", stdout);
    cout << T << endl;
    for (ll lll = 1; lll <= T; lll++)
    {
        m.clear();
        cout << N << endl;
        for (ll i = 1; i <= N; i++)
        {
            for (ll j = 1; j <= 2; j++)
            {
                ll x = _rand(0, wmax);
                ll y = _rand(0, wmax);
                ll z = _rand(0, wmax);
                node rt = node(x, y, z);
                if (m[rt])
                {
                    j--;
                }
                else
                {
                    m[rt] = 1;
                    cout << x << " " << y << " " << z << " ";
                }
            }
            ll t = _rand(0, dmax), d = _rand(0, wmax);
            cout << t << " " << d << endl;
        }
        for (ll j = 1; j <= 2; j++)
        {
            ll x = _rand(0, wmax);
            ll y = _rand(0, wmax);
            ll z = _rand(0, wmax);
            node rt = node(x, y, z);
            if (m[rt])
            {
                j--;
            }
            else
            {
                m[rt] = 1;
                cout << x << " " << y << " " << z << " ";
            }
        }
        cout << endl;
    }
}