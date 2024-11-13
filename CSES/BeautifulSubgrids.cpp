#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()
const int maxN = 3002;
bitset<maxN> b[maxN];

int cal(int n) {
    return n * (n - 1);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0;i < n;i++) {
        cin >> b[i];
    }
    ll ans = 0;
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            ans += cal((b[i] & b[j]).count());

        }
    }
    ans /= 2;
    cout << ans;
    return 0;
}