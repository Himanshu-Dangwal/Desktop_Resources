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
int n, q;
vector<int> adj[maxN];
vector<int> ans(maxN), vis(maxN);
vector<vector<int>> up(2e5 + 10, vector<int>(20));

void binaryLifting(int node, int par) {
    up[node][0] = par;

    for (int i = 1;i <= 20;i++) {
        if (up[node][i - 1] != -1) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        else {
            up[node][i] = -1;
        }
    }

    for (auto child : adj[node]) {
        if (child != par) {
            binaryLifting(child, node);
        }
    }
}

int query(int node, int k) {

    if (node == -1 || k == 0) {
        return node;
    }

    for (int i = 19;i >= 0;i--) {
        if (k >= (1 << i)) {
            return query(up[node][i], k - (1 << i));
        }
    }
    return -1;
}

int main()
{
    cin >> n >> q;
    for (int i = 2;i <= n;i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    binaryLifting(1, -1);
    while (q--) {
        int e, k;
        cin >> e >> k;
        cout << query(e, k) << endl;
    }
    return 0;
}
