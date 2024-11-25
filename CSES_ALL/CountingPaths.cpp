#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

//LCA 
const int maxN = 2e5 + 10;
int n, q;
vector<int> adj[maxN];
int up[maxN][21], lvl[maxN], dist[maxN];

void dfs(int u, int par, int level) {
    lvl[u] = level;

    for (int child : adj[u]) {
        if (child != par) {
            dfs(child, u, level + 1);
        }
    }
}

void binaryLifting(int u, int par) {
    up[u][0] = par;

    for (int i = 1;i <= 20;i++) {
        if (up[u][i - 1] != -1) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        else {
            up[u][i] = -1;
        }
    }

    for (int child : adj[u]) {
        if (child != par) {
            binaryLifting(child, u);
        }
    }
}

int liftNode(int node, int k) {
    if (node == -1 || k == 0) {
        return node;
    }

    for (int i = 20;i >= 0;i--) {
        if (k >= (1 << i)) {
            return liftNode(up[node][i], k - (1 << i));
        }
    }

    return -1;
}


int getLCA(int u, int v) {
    if (lvl[u] < lvl[v]) {
        return getLCA(v, u);
    }

    u = liftNode(u, lvl[u] - lvl[v]);
    if (u == v) return u;

    for (int i = 20;i >= 0;i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void dfs2(int u, int par) {

    for (int child : adj[u]) {
        if (child != par) {
            dfs2(child, u);
            dist[u] += dist[child];
        }
    }
}

int main()
{
    cin >> n >> q;
    for (int i = 1;i < n;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1, 0);
    binaryLifting(1, -1);

    while (q--) {
        int u, v;
        cin >> u >> v;

        int lcaNode = getLCA(u, v);
        dist[u] += 1;
        dist[v] += 1;
        dist[lcaNode] -= 1;

        if (up[lcaNode][0] != -1) {
            dist[up[lcaNode][0]] -= 1;
        }
    }

    dfs2(1, -1);

    for (int i = 1;i <= n;i++) {
        cout << dist[i] << " ";
    }
    return 0;
}
