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


int dfs(int n, vector<int>& dp) {

    if (n == 10) return 2;
    if (n <= 9) {
        return 1;
    }

    if (dp[n] != -1) return dp[n];

    string str = to_string(n);
    int mini = INT_MAX;
    int sz = str.size();
    for (int i = 0;i < sz;i++) {
        int val = str[i] - '0';
        if (val == 0) continue;
        int pAns = 1 + dfs(n - val, dp);
        mini = min(mini, pAns);
    }

    return dp[n] = mini;
}


int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << n;
    cout << dfs(n, dp);
}