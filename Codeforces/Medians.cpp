#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << "1\n1\n"; return;
    }

    if (k == 1 || k == n) {
        cout << "-1\n"; return;
    }

    int p2 = k - (k % 2);
    int p3 = k + 1 + (k % 2);
    cout << "3\n1 " << p2 << " " << p3 << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}