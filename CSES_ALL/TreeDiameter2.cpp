#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;
int n, ans;
vector<int> adj[maxN];
vector<int> d(maxN);

void dfs(int u, int par) {

    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            ans = max(ans, d[u] + d[v] + 1);
            d[u] = max(d[u], d[v] + 1);
        }
    }
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
    cout << ans;
}