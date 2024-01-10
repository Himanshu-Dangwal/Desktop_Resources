#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> sieve(int n)
{
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main()
{
    int N;
    cin >> N;
    vector<int> primes = sieve(N);
    vector<int> dp(N + 1, 0);
    dp[0] = 1; // Base case

    for (int prime : primes)
    {
        for (int i = prime; i <= N; i++)
        {
            dp[i] = (dp[i] + dp[i - prime]) % MOD;
        }
    }

    cout << dp[N] << endl;
    return 0;
}
