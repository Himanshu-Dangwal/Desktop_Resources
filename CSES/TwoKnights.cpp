#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll k = 1; k <= n; k++)
    {
        if (k == 1)
        {
            cout << "0" << endl;
        }
        else
        {
            ll total = ((k * k) * (k * k - 1)) / 2;
            total -= 4 * (k - 1) * (k - 2);
            cout << total << endl;
        }
    }

    return 0;
}