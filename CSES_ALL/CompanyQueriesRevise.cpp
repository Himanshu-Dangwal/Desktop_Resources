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

const int maxN = 2e5 + 10;
int u[maxN][22];
vector<int> adj[maxN];
int n, q;


void binaryLifting(int node, int par) {

    u[node][0] = par;

    for (int i = 1;i <= 20;i++) {
        if (u[node][i - 1] != -1) {
            u[node][i] = u[u[node][i - 1]][i - 1];
        }
        else {
            u[node][i] = -1;
        }
    }

    for (int child : adj[node]) {
        if (child != par)
            binaryLifting(child, node);
    }

}

int query(int node, int k) {

    if (node == -1 || k == 0) {
        return node;
    }

    for (int i = 19;i >= 0;i--) {
        if (k >= (1 << i)) {
            return query(u[node][i], (k - (1 << i)));
        }
    }

    return 0;
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
        int u, k;
        cin >> u >> k;
        cout << query(u, k) << endl;
    }
    return 0;
}