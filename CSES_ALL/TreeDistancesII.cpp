#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 2e5 + 10;
int n;
vector<int> adj[maxN];
vector<int> sumDis(maxN), nodeCount(maxN), ans(maxN);

void dfs(int u, int par) {
    sumDis[u] = 0;
    nodeCount[u] = 0;
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            sumDis[u] += sumDis[v] + nodeCount[v];
            nodeCount[u] += nodeCount[v];
        }
    }
    nodeCount[u]++;
}

void dfs2(int u, int par) {
    if (par == -1) {
        ans[u] = sumDis[u];
    }

    for (int child : adj[u]) {
        if (child != par) {
            ans[child] = ans[u] - nodeCount[child] + (nodeCount[1] - nodeCount[child]);
            dfs2(child, u);
        }
    }

}

signed main() {
    cin >> n;

    for (int i = 2;i <= n;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    // for (int i = 1;i <= n;i++) {
    //     cout << sumDis[i] << " " << nodeCount[i] << endl;
    // }
    // cout << endl;
    dfs2(1, -1);
    for (int i = 1;i <= n;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}