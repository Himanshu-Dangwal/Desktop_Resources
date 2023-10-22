#include <bits/stdc++.h>
using namespace std;

int maxProfit(int *a, int n, int k, int ongoing, int ***dp)
{
    if (n <= 0)
    {
        return 0;
    }
    if (dp[n][k][ongoing] > -1)
    {
        return dp[n][k][ongoing];
    }
    if (k == 0)
    {
        return 0;
    }
    int option2 = 0;
    int option3 = 0;
    int option1 = maxProfit(a + 1, n - 1, k, ongoing, dp); // ignore
    if (ongoing)
    {
        option2 = maxProfit(a + 1, n - 1, k - 1, 0, dp) + a[0];
    }
    else
    {
        if (k > 0)
        {
            option3 = maxProfit(a + 1, n - 1, k, 1, dp) - a[0];
        }
    }
    dp[n][k][ongoing] = max(option1, max(option2, option3));
    return dp[n][k][ongoing];
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int k, n;
        cin >> k >> n;
        int a[n];
        int ***dp = new int **[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int *[k + 1];
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = new int[2];
                for (int k = 0; k <= 1; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maxProfit(a, n, k, 0, dp) << endl;
    }
    return 0;
}