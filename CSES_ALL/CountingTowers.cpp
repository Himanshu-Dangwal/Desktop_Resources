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

const int maxN = 1e6 + 5;
ll dp[maxN][2];

int main()
{
    int t;
    cin >> t;
    dp[1][0] = dp[1][1] = 1;

    for (int i = 2;i < maxN;i++) {
        dp[i][0] = (4 * dp[i - 1][0] % MOD + dp[i - 1][1] % MOD) % MOD;
        dp[i][1] = (2 * dp[i - 1][1] % MOD + dp[i - 1][0] % MOD) % MOD;
    }

    while (t--) {
        int n;
        cin >> n;

        ll ans = (dp[n][0] % MOD + dp[n][1] % MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}