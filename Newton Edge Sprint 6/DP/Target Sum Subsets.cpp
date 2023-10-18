// Target Sum subsets::
#include <bits/stdc++.h>
using namespace std;

int targetSumSubsets(vector<int> &arr, int target)
{
    int n = arr.size();
    int dp[n + 1][target + 1];
    for (int i = 0; i <= target; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    int target;
    cin >> target;

    if (targetSumSubsets(arr, target))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
