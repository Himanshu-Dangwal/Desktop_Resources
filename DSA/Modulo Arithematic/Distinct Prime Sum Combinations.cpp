#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countWays(int N, int lastPrime)
{
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;

    int ways = 0;
    for (int nextPrime = lastPrime; nextPrime <= N; ++nextPrime)
    {
        if (isPrime(nextPrime))
        {
            ways = (ways + countWays(N - nextPrime, nextPrime)) % MOD;
        }
    }
    return ways;
}

int main()
{
    int N;
    cin >> N;
    cout << countWays(N, 1) << endl;
    return 0;
}
