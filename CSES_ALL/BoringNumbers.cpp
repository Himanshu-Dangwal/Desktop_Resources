#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

ll dp[20][12][2][2];

ll solve(ll n, string& s, bool tight, int idx, bool leadingZeroes) {

    if (n == 1) {
        if (tight) {
            int lastVal = s[s.length() - 1] - '0';
            if (idx % 2 == 0) {
                if (leadingZeroes) {
                    return lastVal / 2;
                }
                else {
                    return 1 + (lastVal / 2);
                }
            }
            else {
                ll ans = 0;
                if (lastVal % 2 == 0) {
                    ans += lasVal / 2;
                }
                else {
                    ans += lastVal / 2;
                    ans += 1;
                }
                return ans;
            }
        }
        else {
            ll ans = 5;
            if (leadingZeroes) {
                if (idx % 2 == 0) {
                    return 4;
                }
                else {
                    return 5;
                }
            }
            return 5;
        }

    }

    if (dp[n][idx][tight][leadingZeroes] != -1) {
        return dp[n][idx][tight][leadingZeroes];
    }

    ll limit = 9;
    if (tight) {
        limit = min(limit, s[s.length() - 1] - '0');
    }

    ll ans = 0;

    for (int i = 0;i <= limit;i++) {
        if (idx % 2 == 0 && i % 2 == 0) continue;
        if (idx % 2 && i % 2) continue;
        if (idx % 2 == 0 && i % 2 == 1) {
            ans += solve(n - 1, s, (tight == 1 && i == limit) ? 1 : 0, idx + 1, 0);
        }
        else {
            ans += solve(n - 1, s, (tight == 1 && i == limit) ? 1 : 0, (i == 0 && leadingZeroes) ? idx : idx + 1, (i == 0 && leadingZeroes) ? 1 : 0);
        }
    }

    return dp[n][idx][tight][leadingZeroes] = ans;
}

int main()
{
    ll l, r;
    cin >> l >> r;

    memset(dp, -1, sizeof(dp));
    string s = to_string(r);
    ll ans1 = solve(s.length(), s, 1, 1, 1);
    memset(dp, -1, sizeof(dp));
    l--;
    s = to_string(l);
    ll ans2 = solve(s.length(), s, 1, 1, 1);
    cout << ans2 - ans1;
    return 0;
}