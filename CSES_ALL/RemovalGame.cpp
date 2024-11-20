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

int main() {
    int n;
    cin >> n;

    ll arr[n];
    for (int i = 0;i < n;cin >> arr[i++]);

    ll dp[n][n];

    ll prefix[n];
    prefix[0] = arr[0];
    for (int i = 1;i < n;i++) prefix[i] = arr[i] + prefix[i - 1];

    for (int g = 0;g < n;g++) {
        for (int i = 0, j = g;j < n;i++, j++) {
            if (g == 0) {
                dp[i][j] = arr[i];
            }
            else if (g == 1) {
                dp[i][j] = max(arr[i], arr[j]);
            }
            else {
                ll val1 = arr[i] + prefix[j] - prefix[i] - dp[i + 1][j];
                ll val2 = arr[j] + (prefix[j - 1] - dp[i][j - 1]);
                // cout << val2 << endl;
                if (i - 1 >= 0) {
                    val2 -= prefix[i - 1];
                }
                // cout << i << " " << j << endl;
                // cout << val1 << " " << val2 << endl;
                dp[i][j] = max(val1, val2);
            }
        }
    }

    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < n;j++) {
    //         if (dp[i][j] < 1000 && dp[i][j] >= 0)
    //             cout << dp[i][j] << " ";
    //         else {
    //             cout << "M ";
    //         }
    //     }
    //     cout << endl;
    // }

    cout << dp[0][n - 1];
}