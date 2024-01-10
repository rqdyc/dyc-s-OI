#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 210;
ll n;
string q[N][4];
map<ll, bool> s[30];      // 全局
map<ll, bool> sr[30][30]; // 成员
int main()
{
    freopen("Testdata001.in", "r", stdin);
    freopen("std.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> q[i][1] >> q[i][2] >> q[i][3];
    }
    bool flag = 1;
    while (flag)
    {
        // cout << flag << endl;
        flag = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (q[i][1].size() == 1 && q[i][3].size() == 1)
            {
                if (q[i][3][0] >= 'a' && q[i][3][0] <= 'z')
                {
                    ll x = q[i][1][0] - 'A' + 1, y = q[i][3][0] - 'a' + 1;
                    if (!s[x][y])
                    {
                        s[x][y] = 1;
                        flag = 1;
                    }
                }
                else if (q[i][3][0] >= 'A' && q[i][3][0] <= 'Z')
                {
                    ll x = q[i][1][0] - 'A' + 1, y = q[i][3][0] - 'A' + 1;
                    for (auto it = s[y].begin(); it != s[y].end(); it++)
                    {
                        ll ry = it->first;
                        if (!s[x][ry])
                        {
                            s[x][ry] = 1;
                            flag = 1;
                        }
                    }
                }
            }
            else if (q[i][1].size() == 3)
            {
                ll x = q[i][1][0] - 'A' + 1;
                ll x2 = q[i][1][2] - 'a' + 1;
                ll y = q[i][3][0] - 'A' + 1;
                for (auto it = s[x].begin(); it != s[x].end(); it++)
                {
                    ll ry = it->first;
                    for (auto it2 = s[y].begin(); it2 != s[y].end(); it2++)
                    {
                        ll yy = it2->first;
                        if (!sr[ry][x2][yy])
                        {
                            sr[ry][x2][yy] = 1;
                            flag = 1;
                        }
                    }
                }
            }
            else if (q[i][3].size() == 3)
            {
                ll x = q[i][1][0] - 'A' + 1;
                ll y2 = q[i][3][2] - 'a' + 1;
                ll y = q[i][3][0] - 'A' + 1;
                for (auto it = s[y].begin(); it != s[y].end(); it++)
                {
                    ll ry = it->first;
                    for (auto it2 = sr[ry][y2].begin(); it2 != sr[ry][y2].end(); it2++)
                    {
                        ll yy = it2->first;
                        if (!s[x][yy])
                        {
                            s[x][yy] = 1;
                            flag = 1;
                        }
                    }
                }
            }
        }
    }
    for (ll i = 1; i <= 26; i++)
    {
        cout << (char)(i + 'A' - 1) << ": ";
        for (auto it = s[i].begin(); it != s[i].end(); it++)
        {
            ll ry = it->first;
            cout << (char)(ry - 1 + 'a');
        }
        cout << endl;
    }
}