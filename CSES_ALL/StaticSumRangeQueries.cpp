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
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);
    arr[0] = 0;
    for (ll i = 1;i <= n;i++) {
        ll x;
        cin >> x;
        arr[i] = x;
    }


    for (ll i = 2;i <= n;i++) {
        arr[i] += arr[i - 1];
    }


    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll ans = arr[b] - arr[a - 1];
        cout << ans << endl;
    }
    return 0;
}