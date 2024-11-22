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

const int maxN = 2e5;
int n, m;
vector<int> adj[maxN];
vector<bool> vis(maxN, false);
vector<int> par(maxN);

void dfs(int u, int pu) {
    par[u] = pu;
    vis[u] = true;

    for (auto child : adj[u]) {
        if (child == pu) continue;
        if (vis[child]) {
            vector<int> ans;
            ans.push_back(child);
            ans.push_back(u);
            int last = par[u];
            while (last ^ child) {
                ans.push_back(last);
                last = par[last];
            }
            ans.push_back(child);
            cout << ans.size() << endl;
            for (int i = 0;i < ans.size();i++) {
                cout << ans[i] + 1 << " ";
            }

            exit(0);
        }
        else {
            dfs(child, u);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}