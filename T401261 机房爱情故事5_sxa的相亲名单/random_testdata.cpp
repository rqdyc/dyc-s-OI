#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5, M = 2e5;
const ll amax = 1e9;
ll n, q, op, op2, l, r, x, y, l1, l2, r1, r2;
ll z;
ll a[N];
int main()
{
	mt19937 rnd(time(NULL));
	n = (N * 80 / 100 + rnd() % (N - N * 80 / 100 + 1)), q = (N * 80 / 100 + rnd() % (N - N * 80 / 100 + 1));
	cout << n << " " << q << "\n";
	for (ll i = 1; i <= q; i++)
	{
		op = rnd() % 2;
		if (op % 2 == 1)
		{
			cout << "C ";
			op2 = rnd() % 3 + 1;
			if (op2 == 1)
			{
				l = rnd() % n + 1;
				r = rnd() % n + 1;
				if (l > r)
					swap(l, r);
				x = rnd() % amax + 1;
				cout << op2 << " " << l << " " << r << " " << x << endl;
			}
			if (op2 == 2)
			{
				l = rnd() % n + 1;
				y = rnd() % amax + 1;
				cout << op2 << " " << l << " " << y << endl;
			}
			if (op2 == 3)
			{
				l1 = r1 = 0;
				while (l1 - r1 == 0)
				{
					l1 = rnd() % n + 1;
					r1 = rnd() % n + 1;
					if (l1 > r1)
					{
						l1 = r1 = 0;
						continue;
					}
					if ((r1 - l1 + 1) > (l1 - 1) && (r1 - l1 + 1) > (r1 - (l1 + 1) + 1))
					{
						l1 = r1 = 0;
					}
				}
				//				cout<<l1<<" "<<r1<<endl;
				while (!((r2 - l2) == (r1 - l1)) || !(l2 >= 1) || !(r2 >= 1))
				{
					ll rdd = rnd();
					//					cout<<rdd<<endl;
					l2 = (l1 + rdd) % n + 1;
					r2 = (r1 + rdd) % n + 1;
					if (r2 < l2 || max(l1, l2) - min(r1, r2) <= 0)
					{
						r2 = l2 = 0;
					}
				}
				cout << op2 << " " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
			}
		}
		else
		{
			cout << "Q ";
			l = rnd() % n + 1;
			r = rnd() % n + 1;
			if (l > r)
				swap(l, r);
			z = rnd() % amax;
			cout << l << " " << r << " " << z << endl;
		}
	}
	fclose(stdout);
}
