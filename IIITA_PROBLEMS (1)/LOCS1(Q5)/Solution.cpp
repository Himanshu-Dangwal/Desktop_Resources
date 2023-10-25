#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp1[1002][1002], dp2[1002][1002];
int n, m;
int calc1(int i, int j, vector<int> &a, vector<int> &b)
{
    if (i == n || j == m)
        return 0;
    if (dp1[i + 1][j + 1] != -1)
        return dp1[i + 1][j + 1];
    if (a[i] == b[j])
        return dp1[i + 1][j + 1] = 1 + calc1(i + 1, j + 1, a, b);
    else
        return dp1[i + 1][j + 1] = max(calc1(i + 1, j, a, b), calc1(i, j + 1, a, b));
}
int calc2(int i, int j, vector<int> &a, vector<int> &b)
{
    if (i == -1 || j == -1)
        return 0;
    if (dp2[i + 1][j + 1] != -1)
        return dp2[i + 1][j + 1];
    if (a[i] == b[j])
        return dp2[i + 1][j + 1] = 1 + calc2(i - 1, j - 1, a, b);
    else
        return dp2[i + 1][j + 1] = max(calc2(i - 1, j, a, b), calc2(i, j - 1, a, b));
}
void solve()
{
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &it : a)
        cin >> it;
    for (int &it : b)
        cin >> it;
    int k;
    cin >> k;
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    calc1(0, 0, a, b);
    calc2(n - 1, m - 1, a, b);
    for (int i = 0; i < 1002; i++)
    {
        for (int j = 0; j < 1002; j++)
        {
            if (dp1[i][j] == -1)
                dp1[i][j] = 0;
            if (dp2[i][j] == -1)
                dp2[i][j] = 0;
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == k && b[j] == k)
            {
                ans = max(ans, 2 * min(dp2[i][j], dp1[i + 2][j + 2]) + 1);
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
        solve();
}