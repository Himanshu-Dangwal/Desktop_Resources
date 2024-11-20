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

int dp[501][501];
int main() {
    int n, m;
    cin >> n >> m;


    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {

            if (i ^ j) dp[i][j] = INT_MAX;

            //Horizontal Cuts
            for (int k = 1;k < i;k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }

            //Verticval Cuts
            for (int k = 1;k < j;k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }

        }
    }
    cout << dp[n][m];
}