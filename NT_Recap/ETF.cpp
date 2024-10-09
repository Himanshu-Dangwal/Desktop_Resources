#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int ETF(int n)
{

    int phi = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            phi *= (i - 1);
            phi /= i;
        }
    }

    if (n > 1)
    {
        phi *= (n - 1);
        phi /= n;
    }

    return phi;
}

void solve()
{
    int n;
    cin >> n;
    cout << ETF(n) << endl;
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
