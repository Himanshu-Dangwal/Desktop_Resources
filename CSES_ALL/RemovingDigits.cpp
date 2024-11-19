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

unordered_map<int, int> dp;
int dfs(int n) {
    if (n == 0) {
        return 0;
    }

    if (n < 10) {
        dp[n] = 1;
        return 1;
    }

    if (dp.find(n) != dp.end()) {
        return dp[n];
    }

    string str = to_string(n);
    for (int i = 0;i < str.size();i++) {
        if (str[i] - '0' != 0) {
            int val = dfs(n - (str[i] - 48));
            if (dp.find(n) == dp.end()) {
                dp[n] = 1 + val;
            }
            else {
                dp[n] = min(dp[n], 1 + val);
            }
        }
    }

    return dp[n];
}

int main()
{
    dp[0] = 0;
    int n;
    cin >> n;
    cout << dfs(n);
    return 0;
}