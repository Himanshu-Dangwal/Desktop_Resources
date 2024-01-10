#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<bool> getPrimes(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<bool> sieve = getPrimes(n);

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
        {
            ans = (ans % MOD + i % MOD) % MOD;
        }
    }
    ans = (ans % MOD + 1 % MOD) % MOD;
    cout << ans;
}