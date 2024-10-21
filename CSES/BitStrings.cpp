#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int pow(int a, int n, int mod)
{

    if (n == 0)
        return 1;
    if (n == 1)
        return a;

    ll ans = pow(a, n / 2, mod) % MOD;
    ans = (ans % MOD * ans % MOD) % MOD;

    if (n % 2)
    {
        ans = (a % MOD * ans % MOD) % MOD;
    }

    return ans % MOD;
}

int main()
{
    int n;
    cin >> n;

    cout << pow(2, n, MOD);
    return 0;
}