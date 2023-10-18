// Target Sum subsets::
#include <bits/stdc++.h>
using namespace std;

int minimumSubsetDifference(vector<int> &arr)
{
    int n = arr.size();

    int sum = 0;
    for (int x : arr)
        sum += x;

    int target = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= target; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
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
    int value;
    for (int j = target; j >= 0; j--)
    {
        if (dp[n][j])
        {
            value = j;
            break;
        }
    }

    int secondSum = sum - value;
    return abs(value - secondSum);
}

int main()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    cout << minimumSubsetDifference(arr);

    return 0;
}
