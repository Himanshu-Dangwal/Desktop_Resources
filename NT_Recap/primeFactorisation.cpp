#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void primeFactorisation(int n)
{

    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout << i << " " << cnt << endl;
        }
    }

    if (n > 1)
    {
        cout << n << " " << 1 << endl;
    }

    return;
}

void solve()
{
    int n;
    cin >> n;

    primeFactorisation(n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}