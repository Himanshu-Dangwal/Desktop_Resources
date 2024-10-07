#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        int x = power(a, n / 2);
        return x * x;
    }

    return a * power(a, n - 1);
}

void solve()
{
    int a, n;
    cin >> a >> n;

    cout << power(a, n);
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