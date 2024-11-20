#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    ll dp[n][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0;i < n;i++) {
        if (i == 0) {
            if (arr[i] == 0) {
                for (int j = 1;j <= m;j++) {
                    dp[i][j] = 1;
                }
            }
            else {
                dp[i][arr[i]] = 1;
            }
        }
        else {
            if (arr[i] == 0) {
                for (int j = 1;j <= m;j++) {
                    dp[i][j] = (dp[i][j] % MOD + dp[i - 1][j] % MOD + dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD) % MOD;
                }
            }
            else {
                dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] % MOD + dp[i - 1][arr[i]] % MOD + dp[i - 1][arr[i] + 1] % MOD) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1;i <= m;i++) {
        ans = (ans % MOD + dp[n - 1][i] % MOD) % MOD;
    }
    cout << ans;

    return 0;
}