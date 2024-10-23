#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll x = 2 * b - a;
    ll y = 2 * a - b;
    if (x >= 0 && x % 3 == 0 && y >= 0 && y % 3 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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