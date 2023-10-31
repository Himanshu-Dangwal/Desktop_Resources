#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll lcm_ab = lcm(a, b);
    ll lcm_abc = lcm(lcm_ab, c);
    cout << lcm_abc << endl;
}
int main()
{
    solve();
    return 0;
}