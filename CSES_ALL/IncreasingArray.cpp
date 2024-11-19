#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<int,int>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    for (int i = 1;i < n;i++) {
        if (arr[i] < arr[i - 1]) {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << ans;
    return 0;
}