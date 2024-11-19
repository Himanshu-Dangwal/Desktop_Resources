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
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for (int i = 0;i < n;cin >> price[i++]);
    for (int i = 0;i < n;cin >> pages[i++]);

    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    int maxi = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= x;j++) {
            dp[i][j] = dp[i - 1][j];
            if (price[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - price[i - 1]]);
            }
            maxi = max(maxi, dp[i][j]);
        }
    }
    cout << maxi;

    return 0;
}