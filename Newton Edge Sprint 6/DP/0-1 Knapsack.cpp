// 0-1 Knapsnack::
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int knapsack(vector<int> &profit, vector<int> &wt, int max_wt)
{
    int n = profit.size();
    int dp[n + 1][max_wt + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= max_wt; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= max_wt; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= max_wt; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= wt[i - 1])
            {
                dp[i][j] = max(dp[i][j], profit[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }

    return dp[n][max_wt];
}

int main()
{
    int n;
    cin >> n;
    vector<int> profit(n), wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    int max_wt;
    cin >> max_wt;

    cout << knapsack(profit, wt, max_wt) << endl;
    return 0;
}
