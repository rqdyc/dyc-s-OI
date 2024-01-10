#include <bits/stdc++.h>
using namespace std;
#define ll long long
mt19937 rnd(time(NULL));
const ll N = 200;
int main()
{
    freopen("Testdata001.in", "w", stdout);
    cout << N << endl;
    for (ll i = 1; i <= N; i++)
    {
        ll opt = rnd() % 4;
        if (opt == 0)
        {
            cout << (char)(rnd() % 26 + 'A') << " = " << (char)(rnd() % 26 + 'a') << endl;
        }
        if (opt == 1)
        {
            cout << (char)(rnd() % 26 + 'A') << " = " << (char)(rnd() % 26 + 'A') << endl;
        }
        if (opt == 2)
        {
            cout << (char)(rnd() % 26 + 'A') << "." << (char)(rnd() % 26 + 'a') << " = " << (char)(rnd() % 26 + 'A') << endl;
        }
        if (opt == 3)
        {
            cout << (char)(rnd() % 26 + 'A') << " = " << (char)(rnd() % 26 + 'A') << "." << (char)(rnd() % 26 + 'a') << endl;
        }
    }
}