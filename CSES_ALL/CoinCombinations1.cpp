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
    sort(coins.begin(), coins.end());
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = coins[0];i <= x;i++) {
        for (int coin : coins) {
            if (coin > i) break;
            dp[i] = (dp[i] % MOD + dp[i - coin] % MOD) % MOD;
        }
    }
    cout << dp[x] % MOD;
    return 0;
}