#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 30;
ll input;
__int128 t, n;
__int128 fact[N + 10];
void solve(__int128 x)
{
	__int128 anss;
	for (ll l = 1; l <= 30; l++)
	{
		for (ll j = 1; j < l; j++)
		{
			anss = fact[l] / fact[j];
			if (anss == x)
			{
				cout << l << " " << j << endl;
			}
		}
	}
}
int main()
{
	fact[0] = 1;
	for (__int128 i = 1; i <= N; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
	cin >> input;
	t = input;
	while (t--)
	{
		cin >> input;
		n = input;
		solve(n);
	}
}
