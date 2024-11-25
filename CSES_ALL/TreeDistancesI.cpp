#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;
int n;
vector<int> adj[maxN];
vector<int> dep(maxN), ans(maxN);

void dfs(int u, int par) {

    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            dep[u] = max(dep[u], dep[v] + 1);
        }
    }
}

void dfs2(int u, int par, int par_ans) {
    ans[u] = dep[u];

    vector<int> prefix, suffix;
    for (int child : adj[u]) {
        if (child != par) {
            prefix.push_back(dep[child]);
            suffix.push_back(dep[child]);
        }
    }

    for (int i = 1;i < (int)prefix.size();i++) {
        prefix[i] = max(prefix[i], prefix[i - 1]);
    }

    for (int i = (int)suffix.size() - 2;i >= 0;i--) {
        suffix[i] = max(suffix[i], suffix[i + 1]);
    }

    int child_no = 0;
    for (int child : adj[u]) {
        if (child != par) {
            int leftPrefixMax = (child_no == 0 ? INT_MIN : prefix[child_no - 1]);
            int rightSuffixMax = (child_no == ((int)suffix.size() - 1) ? INT_MIN : suffix[child_no + 1]);
            int newPartialAns = max({ 1 + leftPrefixMax,1 + rightSuffixMax,1 + par_ans });
            dfs2(child, u, newPartialAns);
            child_no++;
        }
    }

    ans[u] = max(ans[u], 1 + par_ans);

}

int main() {
    cin >> n;

    for (int i = 2;i <= n;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    // for (int i = 1;i <= n;i++) {
    //     cout << dep[i] << " ";
    // }
    // cout << endl;

    dfs2(1, -1, -1);

    for (int i = 1;i <= n;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}