#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 10;
ll n;
string f[N];
string add(string a, string b)
{
    string c = "";
    // cout << a << " " << b << " ";
    ll sum, rt = 0;
    for (ll i = 0; i < max(a.size(), b.size()); i++)
    {
        sum = max(0ll, (ll)a[i] - '0') + max(0ll, (ll)b[i] - '0') + rt;
        rt = 0;
        if (sum >= 10)
        {
            sum -= 10;
            rt = 1;
        }
        c += (sum + '0');
    }
    if (rt == 1)
    {
        c += "1";
    }
    // cout << c << endl;
    return c;
}
int main()
{
    cin >> n;
    f[0] = f[1] = "1";
    for (ll i = 2; i <= n; i++)
    {
        f[i] = add(f[i - 1], f[i - 2]);
    }
    reverse(f[n].begin(), f[n].end());
    cout << f[n] << endl;
}