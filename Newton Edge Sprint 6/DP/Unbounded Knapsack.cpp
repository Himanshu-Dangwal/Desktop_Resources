#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> weight(n), value(n);

    for (int i = 0; i < n; cin >> weight[i++])
        ;
    for (int i = 0; i < n; cin >> value[i++])
        ;

    int maxWeight;
    cin >> maxWeight;

    vector<int> dp(maxWeight + 1, 0);

    for (int i = 1; i <= maxWeight; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (weight[j] <= i)
            {
                dp[i] = max(dp[i], value[j] + dp[i - weight[j]]);
            }
        }
    }

    cout << dp[maxWeight];
}