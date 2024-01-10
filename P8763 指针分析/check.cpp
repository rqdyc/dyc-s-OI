#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a[210];
string b[210];
ll tot = 1;
int main()
{
    freopen("std.out", "r", stdin);
    while (scanf("%s", a[tot]) != EOF)
    {
        tot++;
    }
    fclose(stdin);
    tot = 1;
    freopen("kyz.out", "r", stdin);
    while (scanf("%s", b[tot]) != EOF)
    {
        tot++;
    }
    for (ll i = 1; i < tot; i++)
    {
        if (a[i] != b[i])
        {
            cout << "Different in line " << i << "." << endl;
            cout << "expect:" << a[i] << endl;
            cout << "read:" << b[i] << endl;
            return 0;
        }
    }
    cout << "There is noting wrong,hack it again." << endl;
}