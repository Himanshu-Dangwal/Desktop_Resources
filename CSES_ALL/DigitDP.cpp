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

ll dp[20][200][2];

// ll find(ll n, ll r) {

//     ll rem = r % (pow(10, n));
//     return rem / (pow(10, n - 1));

// }
ll sz;

ll solve(ll n, ll x, bool tight, string& r) {

    if (x < 0) return 0;

    if (x == 0) {
        return 1;
    }

    if (n == 1) {
        if (x <= 9) {
            return 1;
        }
        return 0;
    }

    if (dp[n][x][tight] != -1) {
        return dp[n][x][tight];
    }

    ll ans = 0;
    if (!tight) {
        for (int i = 0;i <= 9;i++) {
            ans += solve(n - 1, x - i, 0, r);
        }
    }
    else {
        // ll limit = find(n, r);
        ll limit = r[sz - n] - '0';
        for (int i = 0;i <= limit;i++) {
            if (i == limit) {
                ans += solve(n - 1, x - i, 1, r);
                break;
            }
            ans += solve(n - 1, x - i, 0, r);
        }
    }

    return dp[n][x][tight] = ans;
}

int main()
{
    ll x;
    string r;
    cin >> r >> x;
    int n = r.length();
    sz = n;
    memset(dp, -1, sizeof(dp));
    solve(n, x, 1, r);
    cout << dp[n][x][1];
    return 0;
}