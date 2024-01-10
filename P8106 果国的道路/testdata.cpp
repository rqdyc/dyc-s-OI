#include <bits/stdc++.h>
using namespace std;
map<int, bool> pq[1510];
long long rng()
{
    return (rand() << 15 | rand());
}
int main()
{
    freopen("ppp.in", "w", stdout);
    srand(time(0));
    int n = 1500, m = 2e5;
    cout << n << " " << m << endl;
    while (m--)
    {
        int x = rng() % n + 1, cnt = 0;
        while (1)
        {
            for (int i = 1; i <= n; i++)
                if (pq[x][i])
                    cnt++;
            if (cnt == n - 1)
                x = rng() % n + 1;
            else
                break;
        }
        int y = rng() % n + 1;
        while (x == y || pq[x][y])
            y = rng() % n + 1;
        pq[x][y] = pq[y][x] = true;
        cout << x << " " << y << " " << rng() % 50 + 1 << endl;
    }
}