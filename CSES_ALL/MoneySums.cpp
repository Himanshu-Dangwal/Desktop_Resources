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

/*
Greedy wouldn't work

int main()
{
    int n, m;
    cin >> n >> m;

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (i == 1) {
                dp[i][j] = j - 1;
            }
            else if (j == 1) {
                dp[i][j] = i - 1;
            }
            else {
                if (i == j) {
                    dp[i][j] = 0;
                }
                else {
                    if (i > j) {
                        dp[i][j] = 1 + dp[i - j][j];
                    }
                    else {
                        dp[i][j] = 1 + dp[i][j - i];
                    }
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}

*/

bool dp[105][100005];
int n;
int main() {
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= sum;j++) {
            if (i == 0 && j == 0) {
                dp[0][0] = true;
            }
            else if (i == 0) {
                dp[i][j] = false;
            }
            else if (j == 0) {
                dp[i][j] = true;
            }
            else {
                dp[i][j] = dp[i - 1][j];
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
    }

    // for (int i = 0;i <= n;i++) {
    //     for (int j = 0;j <= sum;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int cnt = 0;
    for (int j = 1;j <= sum;j++) {
        if (dp[n][j]) cnt++;
    }

    cout << cnt << endl;
    for (int j = 1;j <= sum;j++) {
        if (dp[n][j]) cout << j << " ";
    }
}