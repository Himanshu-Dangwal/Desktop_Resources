#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int n = str.length();
    vector<int> dp(n, 0);

    dp[0] = str[0] == '0' ? 0 : 1;

    for (int i = 1; i < n; i++)
    {
        if (str[i] == '0' && str[i - 1] == '0')
        {
            dp[i] = 0;
        }
        else if (str[i] == '0' && str[i - 1] != '0')
        {
            if (str[i - 1] == '1' || str[i - 1] == '2')
            {
                dp[i] = (i - 2) >= 0 ? dp[i - 2] : 1;
            }
            else
            {
                dp[i] = 0;
            }
        }
        else if (str[i] != '0' && str[i - 1] == '0')
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            int tens = str[i - 1] - '0';
            int unit = str[i] - '0';

            int val = tens * 10 + unit;

            dp[i] = dp[i - 1];
            if (val <= 26)
            {
                if (i - 2 >= 0)
                {
                    dp[i] += dp[i - 2];
                }
                else
                {
                    dp[i] += 1;
                }
            }
        }
    }

    cout << dp[n - 1];
}