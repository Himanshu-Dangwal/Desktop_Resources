// #include <bits/stdc++.h>
// using namespace std;
// #pragma GCC target("popcnt")
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;
// // #include <ext/pb_ds/assoc_container.hpp>
// // using namespace __gnu_pbds;
// // typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// // find_by_order() 
// // order_of_key()
// const int maxN = 2e5 + 10;
// int n, q;
// vector<int> adj[maxN], lvl(maxN);
// int up[maxN][21];

// void dfs(int u, int par, int level) {
//     lvl[u] = level;

//     for (int child : adj[u]) {
//         if (child != par) {
//             dfs(child, u, level + 1);
//         }
//     }
// }

// void binaryLifting(int node, int par) {
//     up[node][0] = par;

//     for (int i = 1;i <= 20;i++) {
//         if (up[node][i - 1] != -1) {
//             up[node][i] = up[up[node][i - 1]][i - 1];
//         }
//         else {
//             up[node][i] = -1;
//         }
//     }

//     for (int child : adj[node]) {
//         if (child != par)
//             binaryLifting(child, node);
//     }
// }

// int lift(int node, int k) {
//     if (node == -1 || (k == 0)) return node;

//     for (int i = 20;i >= 0;i--) {
//         if (k >= (1 << i)) {
//             return lift(up[node][i], k - (1 << i));
//         }
//     }

//     return 0;
// }

// int LCA(int u, int v) {
//     int levelU = lvl[u], levelV = lvl[v];

//     if (levelU < levelV) {
//         return LCA(v, u);
//     }

//     int diff = levelU - levelV;
//     u = lift(u, diff);

//     if (u == v) return u;

//     for (int i = 20;i >= 0;i--) {
//         if (up[u][i] != up[v][i]) {
//             u = up[u][i];
//             v = up[v][i];
//         }
//     }

//     return up[u][0];
// }

// int main()
// {
//     cin >> n >> q;
//     for (int i = 1;i < n;i++) {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     dfs(1, 0, 0);
//     // for (int i = 1;i <= n;i++) {
//     //     cout << lvl[i] << " ";
//     // }
//     // cout << endl;
//     binaryLifting(1, -1);

//     while (q--) {
//         int u, v;
//         cin >> u >> v;

//         int lcaNode = LCA(u, v);
//         // cout << lcaNode << " " << u << " " << v << endl;
//         int d = lvl[u] + lvl[v] - 2 * lvl[lcaNode];
//         cout << d << endl;
//     }
//     return 0;
// }




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
int up[maxN][21], lvl[maxN];

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
        int ans = lvl[u] + lvl[v] - 2 * lvl[lcaNode];
        cout << ans << endl;
    }
    return 0;
}
