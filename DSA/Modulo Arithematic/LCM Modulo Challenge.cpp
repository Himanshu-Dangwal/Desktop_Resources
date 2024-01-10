#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int N;
    cin >> N;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long long result = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            result = (result * lcm(arr[i], arr[j])) % MOD;
        }
    }

    cout << result << endl;

    return 0;
}
