#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

int dp[5005][5005];
int n, m;



int solve(string& s, string& t, int i, int j) {
    // cout << i << " " << j << endl;
    if (dp[i][j] != -1) return dp[i][j];

    if (i == n && j == m) {
        return dp[i][j] = 0;
    }
    if (i == n) {
        return dp[i][j] = (m - j);
    }

    if (j == m) {
        return dp[i][j] = (n - i);
    }


    if (s[i] == t[j]) {
        return dp[i][j] = solve(s, t, i + 1, j + 1);
    }

    int o1 = INT_MAX, o2 = INT_MAX, o3 = INT_MAX;
    o1 = 1 + solve(s, t, i, j + 1); //Add 1 character to s
    o2 = 1 + solve(s, t, i + 1, j); //Remove 1 character
    o3 = 1 + solve(s, t, i + 1, j + 1); //Replace 1 character

    return dp[i][j] = min({ o1,o2,o3 });
}

int main()
{
    string s, t;
    cin >> s >> t;
    n = s.length(), m = t.length();

    memset(dp, -1, sizeof(dp));
    // cout << n << " " << m << endl;
    solve(s, t, 0, 0);
    // for (int i = 0;i < 5;i++) {
    //     for (int j = 0;j < 5;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][0];
    return 0;
}

