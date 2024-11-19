#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<int,int>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

int main()
{
    int n;
    cin >> n;

    char arr[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }


    if (arr[n - 1][n - 1] == '*') {
        cout << "0";
        return 0;
    }
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < n;j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    int dp[n][n];
    memset(dp, -1, sizeof(dp));

    for (int i = n - 1;i >= 0;i--) {
        for (int j = n - 1;j >= 0;j--) {
            if (i == n - 1 && j == n - 1) {
                dp[i][j] = 1;
            }
            else if (i == n - 1) {
                if (arr[i][j] == '*') {
                    dp[i][j] = 0;
                }
                else {
                    if (dp[i][j + 1]) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
            else if (j == n - 1) {
                if (arr[i][j] == '*') {
                    dp[i][j] = 0;
                }
                else {
                    if (dp[i + 1][j]) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
            else {
                if (arr[i][j] == '*') {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = (dp[i + 1][j] % MOD + dp[i][j + 1] % MOD) % MOD;
                }
            }
        }
    }

    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < n;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][0] % MOD;
}