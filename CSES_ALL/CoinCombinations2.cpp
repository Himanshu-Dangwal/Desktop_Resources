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
    ll n, sum;
    cin >> n >> sum;

    vector<ll > coins(n);
    for (int i = 0;i < n;cin >> coins[i++]);

    vector<ll> dp(sum + 1, 0LL);
    dp[0] = 1;

    sort(coins.begin(), coins.end());
    for (ll coin : coins) {
        for (ll i = coin;i <= sum;i++) {
            dp[i] = (dp[i] % MOD + dp[i - coin] % MOD) % MOD;
        }
    }

    cout << dp[sum] % MOD;
    return 0;
}