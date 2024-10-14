#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int Catalan(int n)
{
    if (n == 0 || n == 1)
        return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int ans = 0;
        int l = 0, r = i - 1;
        while (r >= 0)
        {
            ans += dp[l] * dp[r];
            l++;
            r--;
        }
        dp[i] = ans;
    }

    return dp[n];
}
// Himanshu dangwal signature
void solve()
{
    int n;
    cin >> n;

    cout << Catalan(n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}