#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
vector<long long> phi(MAX, 0);
vector<long long> result(MAX, 0);

void computeTotient()
{
    phi[1] = 1;
    for (int i = 2; i < MAX; ++i)
    {
        if (phi[i] == 0)
        {
            phi[i] = i - 1;
            for (int j = (i << 1); j < MAX; j += i)
            {
                if (phi[j] == 0)
                {
                    phi[j] = j;
                }
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}

long long sumOfGCD(int num)
{
    computeTotient();
    for (int i = 1; i < MAX; ++i)
    {
        for (int j = 2; i * j < MAX; ++j)
        {
            result[i * j] += i * phi[j];
        }
    }

    for (int i = 2; i < MAX; ++i)
    {
        result[i] += result[i - 1];
    }
    return result[num];
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfGCD(n);
}
