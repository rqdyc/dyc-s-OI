#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e7 + 1e6 + 10;
string s;
ll q[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    string rt = "$#";
    for (ll i = 0; i < s.size(); i++)
    {
        rt += s[i];
        rt += "#";
    }
    ll mid = 0, r = 0;
    vector<ll> q(rt.size());
    ll maxx = -1;
    for (ll i = 1; i < rt.size(); i++)
    {
        if (i < r)
        {
            q[i] = min(q[mid - (i - mid)], r - i + 1);
        }
        else
        {
            q[i] = 1 + (rt[i] != '#');
        }
        if (i - q[i] >= 0 && i + q[i] < rt.size())
        {
            while (rt[i - q[i]] == rt[i + q[i]])
            {
                q[i]++;
            }
        }
        if (q[i] + i - 1 > r)
        {
            mid = i;
            r = q[i] + i - 1;
        }
        if (q[i] - 1 > maxx)
        {
            maxx = q[i] - 1;
        }
    }
    cout << maxx << endl;
    return 0;
}