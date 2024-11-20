#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


int main()
{
    ll n, w;
    cin >> n >> w;

    ll arr[n];
    for (int i = 0;i < n;i++) cin >> arr[i];

    vector<pii> dp(1 << n);
    dp[0] = { 1,0 };

    for (int s = 1;s < (1 << n);s++) {
        dp[s] = { n + 1,0 };
        for (int p = 0;p < n;p++) {
            if (s & (1 << p)) {
                auto exclude = dp[s ^ (1 << p)];
                ll prevAns = exclude.f;
                ll lastWeight = exclude.s;

                if (lastWeight + arr[p] <= w) {
                    exclude.s += arr[p];
                }
                else {
                    exclude.f++;
                    exclude.s = arr[p];
                }

                if (exclude.f < dp[s].f) {
                    dp[s] = exclude;
                }
                else if (exclude.f == dp[s].f) {
                    if (exclude.s < dp[s].s) {
                        dp[s] = exclude;
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].f;
    return 0;
}