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
    ll t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;

        vector<ll> arr(n);
        for (int i = 0;i < n;cin >> arr[i++]);

        int maxi = arr[0] - 0;

        for (int i = 1;i < n;i++) {
            ll pAns = arr[i] - arr[i - 1];
            if (pAns > maxi) maxi = pAns;
        }

        ll pAns = 2 * (x - arr[n - 1]);
        if (pAns > maxi) maxi = pAns;
        cout << maxi << endl;
    }
    return 0;
}