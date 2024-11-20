// #include <bits/stdc++.h>
// using namespace std;
// #pragma GCC target("popcnt")
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;
// // #include <ext/pb_ds/assoc_container.hpp>
// // using namespace __gnu_pbds;
// // typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// // find_by_order() 
// // order_of_key()


// int main() {
//     ll n;
//     cin >> n;

//     ll sum = (n * (n + 1)) / 2;
//     if (sum % 2) {
//         cout << "0";
//         return 0;
//     }
//     sum /= 2;
//     ll dp[n + 1][sum + 1];
//     for (int i = 0;i <= n;i++) {
//         for (int j = 0;j <= sum;j++) {
//             if (i == 0 && j == 0) {
//                 dp[i][j] = 1;
//             }
//             else if (i == 0) {
//                 dp[i][j] = 0;
//             }
//             else if (j == 0) {
//                 dp[i][j] = 0;
//             }
//             else {
//                 dp[i][j] = dp[i - 1][j] % MOD;
//                 if (i <= j) {
//                     dp[i][j] = (dp[i][j] % MOD + dp[i - 1][j - i] % MOD) % MOD;
//                 }
//             }
//         }
//     }
//     dp[n][sum] /= 2;
//     cout << dp[n][sum] % MOD;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;

    if (sum % 2) {
        cout << "0" << endl;
        return 0;
    }

    sum /= 2;

    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));
    dp[0][0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j] % MOD;
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }

    cout << (dp[n][sum] * 500000004) % MOD << endl;
    return 0;
}
