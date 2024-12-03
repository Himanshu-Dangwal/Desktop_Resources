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

const int maxN = 2e5 + 10;
ll n, q;
vector<ll> arr(maxN), seg(4 * maxN);

void buildTree(ll si, ll sj, ll segIdx) {

    if (si == sj) {
        seg[segIdx] = arr[si];
        return;
    }

    ll mid = (si + sj) / 2;
    buildTree(si, mid, 2 * segIdx + 1);
    buildTree(mid + 1, sj, 2 * segIdx + 2);
    seg[segIdx] = (seg[2 * segIdx + 1] ^ seg[2 * segIdx + 2]);
}

ll query(int si, int sj, int segStart, int segEnd, int segIdx) {
    if (segEnd < si || segStart > sj) {
        return 0;
    }

    if (segStart >= si && segEnd <= sj) {
        return seg[segIdx];
    }

    ll mid = (segStart + segEnd) / 2;
    return (query(si, sj, segStart, mid, 2 * segIdx + 1) ^ query(si, sj, mid + 1, segEnd, 2 * segIdx + 2));
}

int main()
{
    cin >> n >> q;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    buildTree(0, n - 1, 0);
    while (q--) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        cout << query(a, b, 0, n - 1, 0) << endl;
    }
    return 0;
}