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

const int maxN = 2e5 + 7;
int n;
vector<int> adj[maxN];
vector<int> ans(maxN), vis(maxN);


vector<vector<int>> dp(maxN, vector<int>(2, 0));

void dfs(int u, int par) {

    dp[u][1] = 0, dp[u][0] = 0;
    int leaf = 1;
    for (auto child : adj[u]) {
        if (child != par) {
            leaf = 0;
            dfs(child, u);
        }
    }

    if (leaf) return;

    vector<int> prefix, suffix;

    for (auto child : adj[u]) {
        if (child != par) {
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }

    for (int i = 1;i < (int)prefix.size();i++) {
        prefix[i] += prefix[i - 1];
    }

    for (int i = (int)suffix.size() - 2;i >= 0;i--) {
        suffix[i] += suffix[i + 1];
    }

    dp[u][0] = suffix[0];
    int x = 0;
    for (auto child : adj[u]) {
        if (child != par) {
            int left = (x == 0 ? 0 : prefix[x - 1]);
            int right = (x == (int)suffix.size() - 1 ? 0 : suffix[x + 1]);

            dp[u][1] = max(dp[u][1], 1 + left + right + dp[child][0]);
            x++;
        }
    }

    return;
}


int main()
{
    cin >> n;

    for (int i = 0;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;

    dfs(1, 0);

    ans = max(dp[1][0], dp[1][1]);
    cout << ans;
    return 0;
}
