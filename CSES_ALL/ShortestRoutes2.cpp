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


int main() {
    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> mat(n, vector<ll>(n, 1e18));

    for (int i = 0;i < m;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if (mat[a][b] < c) {
            continue;
        }
        mat[a][b] = c;
        mat[b][a] = c;
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (i == j) {
                mat[i][j] = 0LL;
            }
        }
    }

    for (int k = 0;k < n;k++) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (i != j && j != k && mat[i][k] != 1e18 && mat[k][j] != 1e18) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    while (q--) {
        ll s, d;
        cin >> s >> d;
        s--, d--;

        if (mat[s][d] == 1e18) {
            cout << "-1" << endl;
        }
        else {
            cout << mat[s][d] << endl;
        }
    }

    return 0;
}




