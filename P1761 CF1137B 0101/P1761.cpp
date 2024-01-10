#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a, b;
ll lena, lenb;
ll ra[2], rb[2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    cin >> b;
    lena = a.size(), lenb = b.size();
    for (ll i = 0; i < lena; i++)
    {
        ra[a[i] - '0']++;
    }
    for (ll i = 0; i < lenb; i++)
    {
        rb[b[i] - '0']++;
    }
    ll sum = min(ra[1] / rb[1], ra[0] / rb[0]);
    // cout << sum << endl;
    for (ll i = 1; i <= sum; i++)
    {
        cout << b;
    }
    for (ll i = 1; i <= ra[1] - rb[1] * sum; i++)
    {
        cout << "1";
    }
    for (ll i = 1; i <= ra[0] - rb[0] * sum; i++)
    {
        cout << "0";
    }
    return 0;
}