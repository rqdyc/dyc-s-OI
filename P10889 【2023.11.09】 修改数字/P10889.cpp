#include <bits/stdc++.h>
using namespace std;
#define ll long long
string n[11];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n[1];
    for (ll j = 2; j <= 10; j++)
    {
        bool flag = 0;
        for (ll i = 0; i < n[1].size(); i++)
        {
            ll sum = n[1][i] - '0' + j - 1;
            sum %= 10;
            if (sum <= 8 && !flag)
            {
                sum++;
                flag = 1;
            }
            n[j] += (char)(sum + '0');
        }
    }
    sort(n + 1, n + 11);
    cout << n[10] << endl;
}