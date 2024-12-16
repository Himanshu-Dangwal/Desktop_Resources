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

int main()
{
    int n;
    cin >> n;

    ll ans = 0;


    vector<int> arr(n);
    for (int i = 0;i < n;i++) cin >> arr[i];

    for (int i = 0;i < n;i++) {
        if (arr[i] < 5) {
            cout << "-1";
            return 0;
        }
    }

    if (n == 1) {
        cout << "5";
        return 0;
    }

    for (int x : arr) ans += x;
    cout << ans;

    return 0;
}