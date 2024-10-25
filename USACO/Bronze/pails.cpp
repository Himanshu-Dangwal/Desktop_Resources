#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    int x, y, m;
    cin >> x >> y >> m;

    if (m % x == 0)
    {
        cout << m / x;
        return 0;
    }

    int div = m / x;
    int ans = div * x;
    if (x + (m % x) >= y)
    {
        ans = (div - 1) * x + y;
    }

    cout << ans;
    return 0;
}