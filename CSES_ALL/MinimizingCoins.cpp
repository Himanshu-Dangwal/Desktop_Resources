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

    vector<int> coins(n);
    for (int i = 0;i < n;cin >> coins[i++]);

    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 1;i <= x;i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
    return 0;
}