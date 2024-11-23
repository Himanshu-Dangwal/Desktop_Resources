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
vector<int> ans(maxN);

int dfs(int u) {

    int cnt = 0;
    for (auto it : adj[u]) {
        cnt += dfs(it);
    }
    ans[u] = cnt;
    return cnt + 1;
}

int main()
{
    cin >> n;

    for (int i = 2;i <= n;i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1);
    for (int i = 1;i <= n;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
