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

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2;i <= n;i++) {
        for (int j = 6;j >= 1;j--) {
            if (i - j >= 0) {
                dp[i] = (dp[i] % MOD + dp[i - j] % MOD) % MOD;
            }
        }
    }
    cout << dp[n] % MOD;
    return 0;
}