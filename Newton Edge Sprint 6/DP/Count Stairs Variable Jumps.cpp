#include <bits/stdc++.h>
using namespace std;

int countStairs(vector<int> &arr)
{
    int n = arr.size();
    int dp[n + 1];

    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = arr[i];

        dp[i] = 0;
        for (int j = 1; j <= cur && i + j <= n; j++)
        {
            dp[i] += dp[i + j];
        }
    }

    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << countStairs(arr);

    return 0;
}