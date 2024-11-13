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
const int maxN = 20005;
bitset<32> b[maxN];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0;i < n;i++) cin >> b[i];
    int ans = INT_MAX;
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            int cnt = (b[i] ^ b[j]).count();
            ans = min(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}