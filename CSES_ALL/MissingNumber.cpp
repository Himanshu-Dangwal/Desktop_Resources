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


int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1;i < n;i++) {
        int x;
        cin >> x;
        ans ^= x;
        ans ^= i;
    }
    ans ^= n;
    cout << ans;
    return 0;
}
