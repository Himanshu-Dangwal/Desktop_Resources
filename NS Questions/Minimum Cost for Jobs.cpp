#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int min_cost_iterative(vector<vector<int>> cost)
{
    int n = cost.size();
    int *dp = new int[1 << n];
    for (int i = 0; i < (1 << n); i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n) - 1; mask++)
    {
        // now we have to count the number of set bits
        int temp = mask;
        int k = 0;
        while (temp > 0)
        {
            if (temp % 2 == 1)
            {
                k++;
            }
            temp /= 2;
        }
        for (int j = 0; j < n; j++)
        {
            if (!(mask & (1 << j)))
            {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[k][j]);
            }
        }
    }
    return dp[(1 << n) - 1];
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << min_cost_iterative(cost) << '\n';
}