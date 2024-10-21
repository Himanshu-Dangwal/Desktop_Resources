#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long int ll;

void solve()
{

    ll x, y;
    cin >> x >> y;

    if (x < y)
    {
        ll ans = 0;
        if (y % 2)
        {
            ans = y * y - (x - 1);
        }
        else
        {
            ans = y * y - y - (y - x - 1);
        }
        cout << ans << endl;
        return;
    }
    else if (x == y)
    {
        ll n = x - 1;
        ll a = 2;
        ll d = 2;
        ll ans = 0;
        ans = 2 * a + (n - 1) * d;
        ans = ans * n;
        ans /= 2;
        ans += 1;
        cout << ans << endl;
        return;
    }
    else
    {
        ll ans = x * x;
        if (x % 2 == 0)
        {
            ans = ans - (y - 1);
        }
        else
        {
            ans = ans - x - (x - y - 1);
        }
        cout << ans << endl;
    }
    return;
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