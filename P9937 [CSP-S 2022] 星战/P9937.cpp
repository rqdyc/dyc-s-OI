// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 10;
ll n, m, q, sum, id;
ll in[N], w[N], out[N];
ll f[N];
int main()
{
    //	freopen("d.in","r",stdin);
    //	freopen("ans.txt","w",stdout);
    cin >> n >> m;
    mt19937 rd(time(NULL));
    for (ll i = 1; i <= n; i++)
    {
        w[i] = rd();
        sum += w[i];
    }
    //	cout<<sum<<endl;
    ll now = 0;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        in[y] += w[x];
        f[y] = in[y];
        now += w[x];
    }
    cin >> q;
    while (q--)
    {
        cin >> id;
        if (id == 1)
        {
            ll x, y;
            cin >> x >> y;
            in[y] -= w[x];
            now -= w[x];
        }
        else if (id == 2)
        {
            ll x;
            cin >> x;
            now -= in[x];
            in[x] = 0;
        }
        else if (id == 3)
        {
            ll x, y;
            cin >> x >> y;
            in[y] += w[x];
            now += w[x];
        }
        else if (id == 4)
        {
            ll x;
            cin >> x;
            now += f[x] - in[x];
            in[x] = f[x];
        }
        // cout<<now<<endl;
        if (now == sum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}