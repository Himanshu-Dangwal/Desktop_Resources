#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<bool> sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

int main()
{
    int A, B;
    cin >> A >> B;
    vector<bool> is_prime = sieve(B);

    long long sum = 0;
    for (int i = A; i <= B; i++)
    {
        if (is_prime[i])
        {
            sum = (sum + i) % MOD;
        }
    }

    cout << sum << endl;
    return 0;
}
